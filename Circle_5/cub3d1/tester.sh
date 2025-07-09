#!/bin/bash

CUB3D_BIN="./cub3d"
TEST_DIR="./tests/cubs"
LOG_DIR="./tests/logs"
EXP_DIR="./tests/expected"

rm -r "$LOG_DIR" 2> /dev/null
mkdir -p "$LOG_DIR"
pass=0
fail=0

run_tests_for() {
	TEST_NAME="$1"
	EXP_STATUS="$2"
	tests=("$TEST_DIR"/$TEST_NAME/*)

	echo
	echo -n "📦 Test: $TEST_NAME:		"
	for file in "${tests[@]}"; do
		tmp_err=$(mktemp)
		name=$(basename "$file" .cub)
		final_log="$LOG_DIR/$TEST_NAME/${name}.log"
		expected_log="$EXP_DIR/$TEST_NAME/${name}.log"

		{ time $CUB3D_BIN "$file" --test >/dev/null 2>"$tmp_err"; } 2>/dev/null
		status=$?

		if [ $status -ne $EXP_STATUS ]; then
			if [ ! -f "$expected_log" ]; then
				mkdir -p "$EXP_DIR/$TEST_NAME" 2> /dev/null
				cp "$tmp_err" "$expected_log"
			elif ! cmp -s "$tmp_err" "$expected_log"; then
				mkdir "$LOG_DIR/$TEST_NAME" 2> /dev/null
				{
					echo "---expected output---"
					cat "$expected_log"
					echo
					echo "---your output---"
					cat "$tmp_err"
					echo
					echo "---diff---"
					diff -u "$expected_log" "$tmp_err" || true
				} > "$final_log"
				((fail++))
			else
				echo -n "✅"
				((pass++))
			fi
		else
			mkdir "$LOG_DIR/$TEST_NAME" 2> /dev/null
			echo "expected exit status: not $EXP_STATUS" > "$final_log"
			echo "your exit status: $status" >> "$final_log"
			echo -n "❌"
			((fail++))
		fi
		rm -f "$tmp_err"
	done
}

run_tests_for file_name 0
run_tests_for texture_path 0
run_tests_for col_gradient 0
run_tests_for map/player 0
run_tests_for map/m_wall 0
run_tests_for map/inv_char 0

echo
echo
echo "––––––––––––––––––––––––"
echo "✅ Passed: $pass"
echo "❌ Failed: $fail"
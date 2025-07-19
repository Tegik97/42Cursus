#!/bin/bash

REPLACER_BIN="./replacer"
TEST_DIR="$HOME/replacer_tests"
F_SLEEP="sleep 0.02"
S_SLEEP="sleep 0.5"
RS_SLEEP="sleep 0.4"

YELLOW=$(tput setaf 3)
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
NO_COLOR=$(tput sgr0)
BOLD=$(tput bold)

run_tests_for()
{
	FILENAME=$1
	FIND=$2
	REPLACE=$3
	tmp_log=$(mktemp)

	if [ $# -eq 3 ]; then
		echo "${BOLD}${YELLOW}Running test:${GREEN} ./replacer \""$FILENAME"\" \""$FIND"\" \""$REPLACE"\"${NO_COLOR}"
		$F_SLEEP
		$REPLACER_BIN "$FILENAME" "$FIND" "$REPLACE" > $tmp_log 2>&1
	elif [ $# -eq 2 ]; then
		echo "${BOLD}${YELLOW}Running test:${GREEN} ./replacer \""$FILENAME"\" \""$FIND"\"${NO_COLOR}"
		$F_SLEEP
		$REPLACER_BIN "$FILENAME" "$FIND" > $tmp_log 2>&1
	elif [ $# -eq 1 ]; then
		echo "${BOLD}${YELLOW}Running test:${GREEN} ./replacer \""$FILENAME"\"${NO_COLOR}"
		$F_SLEEP
		$REPLACER_BIN "$FILENAME" > $tmp_log 2>&1
	else
		echo "${BOLD}${YELLOW}Running test:${GREEN} ./replacer${NO_COLOR}"
		$F_SLEEP
		$REPLACER_BIN > $tmp_log 2>&1
	fi;
	echo "${GREEN}Output:${NO_COLOR}"
	cat "$tmp_log"
	$F_SLEEP
	echo
	if [ -f "$FILENAME" ]; then
		echo "${YELLOW}Original file:${NO_COLOR}"
		cat "$FILENAME"
		$F_SLEEP
		echo
		echo "${YELLOW}New file:${NO_COLOR}"
		cat "$FILENAME".replace
		echo
	fi;
	rm $tmp_log
	$RS_SLEEP
}

run_valgrind_for()
{
	FILENAME=$1
	FIND=$2
	REPLACE=$3
	VALGRIND="valgrind --leak-check=full --error-exitcode=42 --track-origins=yes --show-leak-kinds=all"
	tmp_log=$(mktemp)
	exit_stat=0

	if [ $# -eq 3 ]; then
		echo "${BOLD}${YELLOW}Running test:${GREEN} $VALGRIND ./replacer \""$FILENAME"\" \""$FIND"\" \""$REPLACE"\"${NO_COLOR}"
		$F_SLEEP
		$VALGRIND $REPLACER_BIN "$FILENAME" "$FIND" "$REPLACE" > $tmp_log 2>&1
	elif [ $# -eq 2 ]; then
		echo "${BOLD}${YELLOW}Running test:${GREEN} $VALGRIND ./replacer \""$FILENAME"\" \""$FIND"\"${NO_COLOR}"
		$F_SLEEP
		$VALGRIND $REPLACER_BIN "$FILENAME" "$FIND" > $tmp_log 2>&1
	elif [ $# -eq 1 ]; then
		echo "${BOLD}${YELLOW}Running test:${GREEN} $VALGRIND ./replacer \""$FILENAME"\"${NO_COLOR}"
		$F_SLEEP
		$VALGRIND $REPLACER_BIN "$FILENAME" > $tmp_log 2>&1
	else
		echo "${BOLD}${YELLOW}Running test:${GREEN} $VALGRIND ./replacer${NO_COLOR}"
		$F_SLEEP
		$VALGRIND $REPLACER_BIN > $tmp_log 2>&1
	fi;
	exit_stat=$?
	echo "${GREEN}Output:${NO_COLOR}"
	cat "$tmp_log"
	echo
	if [ $exit_stat -eq 42 ]; then
		echo "${BOLD}valgrind:${NO_COLOR} ❌"
	else
		echo "${BOLD}valgrind:${NO_COLOR} ✅"
	fi;
	echo
	rm $tmp_log
}

clean_tests()
{
	if [ "$1" = "fclean" ]; then
		echo "${BOLD}${YELLOW}Cleaning all...${NO_COLOR}"
		$S_SLEEP
		if [ -d "$TEST_DIR" ]; then
			rm -r "$TEST_DIR"
			echo "${BOLD}${GREEN}Done${NO_COLOR}"
		else
			echo "${BOLD}${YELLOW}Nothing to clean${NO_COLOR}"
		fi;
		echo
		exit 0;
	elif [ "$1" = "clean" ]; then
		echo "${BOLD}${YELLOW}Removing all .replace files${NO_COLOR}"
		$S_SLEEP
		if find "$TEST_DIR" -maxdepth 1 -name "*.replace" 2> /dev/null | grep -q .; then
			rm -f "$TEST_DIR"/*.replace
			echo "${BOLD}${GREEN}Done${NO_COLOR}"
		else
			echo "${BOLD}${YELLOW}No .replace files in $TEST_DIR${NO_COLOR}"
		fi;
		echo
		exit 0
	fi;
}

generate_tests()
{
	if [ ! -d "$TEST_DIR" ]; then
		echo "${BOLD}${YELLOW}Generating tests...${NO_COLOR}"
		mkdir "$TEST_DIR"

		{
			echo "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
			echo "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
			echo "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."
			echo "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
			echo
			echo "Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium,"
			echo "totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo."
			echo "Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit,"
			echo "sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt."
		} > "$TEST_DIR/lorem_ipsum"

		echo "uno due tre due uno" > "$TEST_DIR/empty_s2"
		echo "uno due tre due uno" > "$TEST_DIR/empty_s1"
		echo "ABC DEF GHI" > "$TEST_DIR/s1_not_found"
		echo "sed sed sed sed. sed? Sed!" > "$TEST_DIR/sed"
		echo "omg some args are missing!!" > "$TEST_DIR/missing_arg"
		touch "$TEST_DIR/cant_read_this"
		chmod -r "$TEST_DIR/cant_read_this"
		touch "$TEST_DIR/empty_file"
		echo "ABC DEF GHI" > "$TEST_DIR/find_eq_replace"
		echo "sed!? sed sed- sed. sed? Sed?!" > "$TEST_DIR/special_char"
		$S_SLEEP
		echo "${BOLD}${GREEN}Done${NO_COLOR}"
		echo
	fi;
}

clean_tests $1
generate_tests
if [ $1 == "valgrind" ]; then
	run_valgrind_for "$TEST_DIR/lorem_ipsum" "dolor" "PAIN"
	run_valgrind_for "$TEST_DIR/sed" "sed" "X"
	run_valgrind_for "$TEST_DIR/empty_s2" "uno" ""
	run_valgrind_for "$TEST_DIR/empty_s1" "" "due"
	run_valgrind_for "" "uno" "due"
	run_valgrind_for "$TEST_DIR/s1_not_found" "MNO" "JKL"
	run_valgrind_for "$TEST_DIR/file_not_found" "123" "321"
	run_valgrind_for "$TEST_DIR/missing_arg" "123"
	run_valgrind_for "$TEST_DIR/missing_arg"
	run_valgrind_for
	run_valgrind_for "$TEST_DIR/cant_read_this" "123" "321"
	run_valgrind_for "$TEST_DIR/empty_file" "ABC" "DEF"
	run_valgrind_for "$TEST_DIR/find_eq_replace" "ABC" "ABC"
	run_valgrind_for "$TEST_DIR/special_char" "?" "!!"
else
	run_tests_for "$TEST_DIR/lorem_ipsum" "dolor" "PAIN"
	run_tests_for "$TEST_DIR/sed" "sed" "X"
	run_tests_for "$TEST_DIR/empty_s2" "uno" ""
	run_tests_for "$TEST_DIR/empty_s1" "" "due"
	run_tests_for "" "uno" "due"
	run_tests_for "$TEST_DIR/s1_not_found" "MNO" "JKL"
	run_tests_for "$TEST_DIR/file_not_found" "123" "321"
	run_tests_for "$TEST_DIR/missing_arg" "123"
	run_tests_for "$TEST_DIR/missing_arg"
	run_tests_for
	run_tests_for "$TEST_DIR/cant_read_this" "123" "321"
	run_tests_for "$TEST_DIR/empty_file" "ABC" "DEF"
	run_tests_for "$TEST_DIR/find_eq_replace" "ABC" "ABC"
	run_tests_for "$TEST_DIR/special_char" "?" "!!"
fi;
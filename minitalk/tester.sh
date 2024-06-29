#!/bin/bash

PID="$1"
PARAM="$2"
BONUS=""
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
PURPLE='\033[0;35m'
BOLD='\033[1m'
NC='\033[0m'

if [ "$3" == "bonus" ] || [ "$3" == 'b' ] || [ "$2" == "-b" ]; then
	BONUS="_bonus"
fi

run_command() {
	local cmd="$1"
	local arg="$2"
	local start_time=$(date +%s.%N)
	
	$cmd "$arg"
	local exit_status=$?
	local end_time=$(date +%s.%N)
	local duration=$(echo "scale=3; $end_time - $start_time" | bc)
	local seconds=$(printf "%.0f" $(echo "$duration" | awk -F "." '{print $1}'))
	local centiseconds=$(echo "$duration" | awk -F "." '{print $2}' | cut -c 1-2)
	if [ $exit_status -eq 0 ]; then
		echo -e "${GREEN}${BOLD}OK${NC} in ${seconds}.${centiseconds}s"
	else
		echo -e "${RED}${BOLD}KO${NC}"
	fi

  return $exit_status
}

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-m" ] || [ "$PARAM" == "-t1" ]; then
	echo -e "${YELLOW}${BOLD}100 chars${NC}"
	ARG=$(printf 'b%.0s' {1..100})
	run_command "./client$BONUS $PID" $ARG
fi

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-m" ] || [ "$PARAM" == "-t2" ]; then
	echo -e "${YELLOW}${BOLD}\n20000 chars${NC}"
	ARG=$(printf 'A%.0s' {1..20000})
	run_command "./client$BONUS $PID" $ARG
fi

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-m" ] || [ "$PARAM" == "-t3" ]; then
	PID="0000"
	echo -e "${YELLOW}${BOLD}\nInvalid PID${NC}"
	ARG="prova"
	run_command "./client$BONUS $PID" $ARG
	PID="$1"
fi

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-m" ] || [ "$PARAM" == "-t4" ]; then
	echo -e "${YELLOW}${BOLD}\nStress Test${NC}"
	for char in {a..n}; do
		echo -e "${PURPLE}3000 iterations of $char${NC}"
		ARG=$(printf "%.0s$char" {1..3000})
		run_command "./client$BONUS $PID" $ARG
	done
fi

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-b" ]; then
	echo -e "${YELLOW}${BOLD}\n--BONUS--${NC}"
fi

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-b" ] || [ "$PARAM" == "-t5" ]; then
	echo -e "${YELLOW}${BOLD}\nUnicode Chars${NC}"
	ARG="🙃🤫🍤"
	run_command "./client$BONUS $PID" $ARG
fi

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-b" ] || [ "$PARAM" == "-t6" ]; then
	echo -e "${YELLOW}${BOLD}\n20000 iterations of 😴${NC}"
	char='😴'
	ARG=$(printf "%.0s$char" {1..20000})
	run_command "./client$BONUS $PID" $ARG
fi

if [ "$PARAM" == "-a" ] || [ "$PARAM" == "-b" ] || [ "$PARAM" == "-t7" ]; then
	echo -e "${YELLOW}${BOLD}\nStress Test${NC}"
	for char in '🌑' '🌒' '🌓' '🌔' '🌕' '🌖' '🌗' '🌘' '🌚'; do
		echo -e "${PURPLE}3000 iterations of $char${NC}"
		ARG=$(printf "%.0s$char" {1..3000})
		run_command "./client$BONUS $PID" $ARG
	done
fi

if [ "$PARAM" == "-h" ] || [ "$PARAM" == "" ]; then
	echo -e "Usage: ./tester <PID> <param>
	To execute the tester using the bonus client add 'bonus'
	at the end of it (./tester.sh <PID> <param> bonus)

	valid params:	-h	(shows this message)
			-a	(executes all tests)
			-m	(only executes mandatory tests)
			-b	(only executes bonus tests)
			-t1..7	(executes the n test)"
fi
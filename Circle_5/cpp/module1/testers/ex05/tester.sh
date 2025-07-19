#!/bin/bash

HARL_BIN="./harl"

YELLOW=$(tput setaf 3)
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
NO_COLOR=$(tput sgr0)
BOLD=$(tput bold)



if [ "$1" == "valgrind" ]; then
	VALGRIND="valgrind --leak-check=full --error-exitcode=42 --track-origins=yes --show-leak-kinds=all"
	for level in DEBUG INFO WARNING ERROR "WRONG" ""; do
	echo "Running: $VALGRIND ./harl $level"
	$VALGRIND $HARL_BIN $level
	exit_stat=$?
	echo
	if [ $exit_stat -eq 42 ]; then
		echo "${BOLD}valgrind:${NO_COLOR} ❌"
	else
		echo "${BOLD}valgrind:${NO_COLOR} ✅"
	fi;
	echo
	done
else
	for level in DEBUG INFO WARNING ERROR "WRONG" ""; do
	echo "Running: ./harl $level"
	$HARL_BIN $level
	echo
	done
fi;
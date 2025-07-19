#!/bin/bash

HARL_BIN="./harl"
F_SLEEP="sleep 0.02"
S_SLEEP="sleep 0.5"
RS_SLEEP="sleep 0.4"

YELLOW=$(tput setaf 3)
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
NO_COLOR=$(tput sgr0)
BOLD=$(tput bold)

for level in DEBUG INFO WARNING ERROR "WRONG" ""; do
	echo "Running: ./harl $level"
	$HARL_BIN $level
	echo
done

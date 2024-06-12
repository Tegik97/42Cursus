#!/bin/bash

val="$1"
param="$2"
GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD='\033[1m'
NC='\033[0m'

# Funzione per eseguire il programma e verificare l'exit status
run_command() {
  local cmd="$1"
  local arg="$2"

  $cmd $arg
  local exit_status=$?

  if [ $exit_status -eq 0 ]; then
    echo -e "${GREEN}${BOLD}OK${NC}"
  else
    echo -e "${RED}${BOLD}KO${NC}"
  fi
}

echo -e "${BOLD}valid map${NC}
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111"
ARG="valid.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}valid big map${NC}"
ARG="big_map.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}map name: test.bar${NC}"
ARG="valid.bar"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}map name: test.be${NC}"
ARG="valid.be"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}map name: .ber${NC}"
ARG=".bar"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}File not found test.ber${NC}"
ARG="test.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}Map with invalid char${NC}
1111111111111
1001000000001
1000011111001
1P0011E0000F1
1111111111111"
ARG="invalid_char_map.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}Map with multiple E${NC}
1111111111111
10010000E00C1
1000011111001
1P0011E000001
1111111111111"
ARG="dup_E_map.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}Map with multiple P${NC}
1111111111111
100P0000000C1
1000011111001
1P0011E000001
1111111111111"
ARG="dup_P_map.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}Map with no collectables${NC}
1111111111111
1000000000001
1000011111001
1P0011E000001
1111111111111"
ARG="no_C_map.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}Invalid wall map${NC}
1111111111111
10010000000C1
1000011111001
1P0011E000000
1111111111111"
ARG="invalid_wall_map.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}Invalid wall size map${NC}
1111111111111
10010000000C1
100001111101
1P0011E000001
1111111111111"
ARG="invalid_size.ber"
run_command "$val $param ./so_long" $ARG

echo ""
echo -e "${BOLD}Square map${NC}
11111
1C0P1
10E01
10001
11111"
ARG="square_map.ber"
run_command "$val $param ./so_long" $ARG

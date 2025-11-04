#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;36m'  # Cyan vivace
BOLD='\033[1m'
NC='\033[0m' # No Color

PASSED=0
FAILED=0

# Percorso dell'eseguibile
RPN_PATH="./RPN"

# Verifica che l'eseguibile esista
if [ ! -f "$RPN_PATH" ]; then
    echo -e "${RED}Error: RPN executable not found at $RPN_PATH${NC}"
    echo "Please compile the project first: cd ../../ex01 && make"
    exit 1
fi

test_case() {
    local input="$1"
    local expected="$2"
    local description="$3"
    
    echo -n "Testing: $description ($input) "
    
    result=$($RPN_PATH "$input" 2>&1 | head -n 1)
    
    if [ "$result" = "$expected" ]; then
        echo -e "= $result ${GREEN}✓ PASS${NC}"
        ((PASSED++))
    else
        echo -e "${RED}✗ FAIL${NC}"
        echo -e "  ${YELLOW}Input:${NC}    \"$input\""
        echo -e "  ${YELLOW}Expected:${NC} $expected"
        echo -e "  ${YELLOW}Got:${NC}      $result"
        ((FAILED++))
    fi
}

echo -e "${BOLD}${BLUE}================================${NC}"
echo -e "${BOLD}${BLUE}    RPN Calculator Tests${NC}"
echo -e "${BOLD}${BLUE}================================${NC}"
echo

# ============================================================================
echo -e "${BOLD}=== Basic Operations ===${NC}"
# ============================================================================
test_case "3 4 +" "7" "Simple addition"
test_case "0 5 +" "5" "Addition with zero"
test_case "10 20 +" "30" "Larger addition"

test_case "5 3 -" "2" "Simple subtraction"
test_case "10 7 -" "3" "Subtraction"
test_case "0 5 -" "-5" "Subtraction from zero"

test_case "3 4 *" "12" "Simple multiplication"
test_case "0 5 *" "0" "Multiplication by zero"
test_case "7 6 *" "42" "Multiplication"

test_case "8 2 /" "4" "Simple division"
test_case "10 3 /" "3" "Integer division"
test_case "0 5 /" "0" "Zero divided by number"

echo

# ============================================================================
echo -e "${BOLD}=== Complex Expressions ===${NC}"
# ============================================================================
test_case "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "Complex"
test_case "7 7 * 7 -" "42" "Complex"
test_case "1 2 * 2 / 2 * 2 4 - +" "0" "Complex"
test_case "3 4 + 2 5 * +" "17" "Complex"
test_case "15 7 1 1 + - / 3 * 2 1 1 + + -" "5" "Very complex expression"

echo

# ============================================================================
echo -e "${BOLD}=== Edge Cases ===${NC}"
# ============================================================================
test_case "42" "42" "Single number"
test_case "0" "0" "Single zero"
test_case "9" "9" "Single digit"

test_case "0 0 +" "0" "Zero plus zero"
test_case "0 0 *" "0" "Zero times zero"
test_case "5 0 -" "5" "Number minus zero"

test_case "3 5 -" "-2" "Negative result"
test_case "0 10 -" "-10" "Negative result"

echo

# ============================================================================
echo -e "${BOLD}=== Operand Order (Important!) ===${NC}"
# ============================================================================
test_case "5 3 -" "2" "Subtraction order"
test_case "3 5 -" "-2" "Subtraction order"
test_case "8 2 /" "4" "Division order"
test_case "2 8 /" "0" "Division order"
test_case "10 5 - 2 -" "3" "Chain subtraction"
test_case "20 4 / 2 /" "2" "Chain division"

echo

# ============================================================================
echo -e "${BOLD}=== Error Tests ===${NC}"
# ============================================================================
test_case "5 0 /" "Error: division by zero" "Division by zero"
test_case "8 2 / 0 /" "Error: division by zero" "Division by zero (after operation)"
test_case "0 0 /" "Error: division by zero" "Zero divided by zero"

test_case "5 +" "Error: not enough operands" "Not enough operands (one number)"
test_case "+ 3 4" "Error: not enough operands" "Operator at start"
test_case "+" "Error: not enough operands" "Only operator"
test_case "3 + 4" "Error: not enough operands" "Infix notation (should be RPN)"

test_case "3 4 5" "Error" "Too many operands (no operations)"
test_case "1 2 + 3 4 +" "Error" "Multiple results in stack"

test_case "3 4 & 2" "Error" "Invalid operator (&)"
test_case "3 4 x" "Error" "Invalid operator (x)"
test_case "abc" "Error" "Invalid token (letters)"
test_case "3 4.5 +" "Error" "Float number (if integers only)"

test_case "" "Error: bad argument" "Empty expression"

echo

# ============================================================================
echo -e "${BOLD}${BLUE}================================${NC}"
echo -e "${BOLD}           Results${NC}"
echo -e "${BOLD}${BLUE}================================${NC}"
echo -e "Passed: ${GREEN}${BOLD}$PASSED${NC}"
echo -e "Failed: ${RED}${BOLD}$FAILED${NC}"
echo -e "Total:  ${BOLD}$((PASSED + FAILED))${NC}"
echo

if [ $FAILED -eq 0 ]; then
    echo -e "${GREEN}${BOLD}✓ All tests passed!${NC} 🎉"
    exit 0
else
    echo -e "${RED}${BOLD}✗ Some tests failed!${NC}"
    exit 1
fi

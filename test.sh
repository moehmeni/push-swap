#!/bin/bash

function check_build {
	if [ ! -f push_swap ]
	then
		make push_swap bonus
	fi
}

function print {
	GREEN='\033[0;32m'
	RED='\033[0;31m'
	NC='\033[0m'
	if [[ $1 == "OK" ]]
	then
		echo -e "${GREEN}OK${NC}"
	else
		echo -e "${RED}KO${NC}"
	fi
}

function test {
	echo "Testing with $1 numbers"
	ARG=$(seq -1000 1000 | sort -R | tail -n $1 | tr '\n' ' ')
	N=$(./push_swap $ARG | wc -l | tr -d ' ')
	echo "Instructtions: $N"
	STATUS=$(./push_swap $ARG | ./checker $ARG)
	echo -n "Checker: "
	print $STATUS
	echo -e "\n"
}

check_build
test 3
test 5
test 100
test 500
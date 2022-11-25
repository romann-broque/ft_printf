#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

if [ -z "$1" ]; then
	echo "ERROR: bin does not specified..."
	exit 1
fi

echo -e "\n<--------- TEST ---------->\n\n"

### CHECK TESTS

BIN=$1
CACHE1="./tests/assets/cache1"
CACHE2="./tests/assets/cache2"

echo "" > ${CACHE1}
echo "" > ${CACHE2}

./${BIN}

### RETURN_VALUE 

IS_SAME=$(diff -a ${CACHE1} ${CACHE2})
RET=$?

if [ "${RET}" == "0" ]; then
	echo -e "${GREEN}OK${NC}"
else
	echo ${IS_SAME}
	echo -e "\n\n"
	echo -e "${RED}KO${NC}"
fi

exit ${RET}

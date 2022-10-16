#!/bin/bash

RED="\033[31m"
GREEN="\033[32m"
NC="\033[0m"

if [ -z "$1" ]; then
	echo "ERROR: bin does not specified..."
	exit 1
fi

echo "<--------- TEST ---------->"

### CHECK TESTS

BIN=$1
CACHE="./tests/assets/cache"

for arg in "$@"; do
	if [ "${arg}" != "${BIN}" ]; then
		ARGS+="${arg} "
	fi
done

echo "$(./${BIN} ${ARGS})" > ${CACHE}

### RETURN_VALUE 

PROGRAM="./tests/is_same"

IS_SAME=$(${PROGRAM} ${CACHE})
RET=$?

if [ "${RET}" == "0" ]; then
	echo -e "${GREEN}OK${NC}"
else
	echo -e "${RED}KO${NC}"
fi

exit ${RET}

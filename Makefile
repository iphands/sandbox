CC=gcc
CFLAGS=-Wall -std=gnu99 -ggdb

all: len fork ll stack-pause ptrace-test

check-syntax: len fork ll stack-pause ptrace-test
	${CC} ${CFLAGS} -o /dev/null -S ${CHK_SOURCES}

clean:
	rm len fork ll stack-pause ptrace-test

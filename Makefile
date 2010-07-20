CC=gcc
CFLAGS=-Wall -std=gnu99 -ggdb

all: len fork ll

check-syntax: len fork ll
	${CC} ${CFLAGS} -o /dev/null -S ${CHK_SOURCES}

clean:
	rm len fork ll

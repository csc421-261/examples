#
# Makefile for threads_counter.c
# author: chatgpt and bjr
# last-update:
#	21 sep 2025: created
#

CC= gcc
CFLAGS= -Wall -pthread
P= threads_counter
OPT_FLAGS= -DADD_SLEEP

all:
	@echo "The read-write should be atomic"
	make run
	@echo
	@echo "The read and write separated by a sleep"
	make run-with-sleep
	make clean

$P: $P.c
	$(CC) $(CFLAGS) -o $P $P.c

$P-sleep: $P.c
	${CC} ${CFLAGS} ${OPT_FLAGS} -o $P $P.c

run: $P
	./$P

run-with-sleep: $P-sleep
	./$P

clean:
	rm -f $P

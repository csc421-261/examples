#
# Makefile for threads_counter.c
# author: chatgpt and bjr
# last-update:
#	21 sep 2025: created
#

CC= gcc
CFLAGS= -Wall -pthread
P= threads_counter

all:
	@echo "The read-write should be atomic"
	make run
	@echo
	@echo "The read and write separated by a sleep"
	make run_s
	make clean

$P: $P.c
	$(CC) $(CFLAGS) -o $P $P.c

$P_s: $P_s.c
	$(CC) $(CFLAGS) -o $@ $<

$P_t: $P_t.c
	$(CC) $(CFLAGS) -o $@ $<

run: $P
	./$P

run_s: $P_s
	./$P_s

run_t: $P_t
	./$P_t

clean:
	rm -f $P $P_s $P_t

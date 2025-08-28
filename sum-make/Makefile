#
# makefile for sum
# author: bjr
# last-update:
#     28 aug 2025 -bjr; created
#
	
all:
	make clean
	make test

sum: sum.c sum_util.o sum_util.h
	gcc -o sum sum.c sum_util.o

sum_util.o: sum_util.c sum_util.h
	gcc -o sum_util.o -c sum_util.c 

test: sum
	./sum 3 4 

clean:
	-rm sum_util.o sum

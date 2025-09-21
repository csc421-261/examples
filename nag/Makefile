#
# Makefile for nag.c
# author: bjr
# last-update;
#	21 sep 2025; 
#
#

nag: nag.c
	cc -o $@ $< -pthread
	
run: nag
	./$<

clean:
	-rm nag

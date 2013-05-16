CC = gcc
CFLAGS = -Wall -std=c99 -O0


test: Uzd4/povsid_nice01.c
	$(cc) $(cflags) Uzd4/*.c -o test

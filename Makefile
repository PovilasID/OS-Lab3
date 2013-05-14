CC = gcc
CFLAGS = -Wall -std=c99 -O0

PROGS = test

.PHONY: all clean

all: $(PROGS)

test: ./precompile/main.c
test: ./precompile/functions01.c
test: ./precompile/functions02.c


clean:
	-rm -f $(RPOGS)
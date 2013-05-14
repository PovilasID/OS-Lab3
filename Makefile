CC = gcc
CFLAGS = -Wall -std=c99 -O0

PROGS = test

.PHONY: all clean

all: $(PROGS)

test: ./precompile/*


clean:
	-rm -f $(RPOGS)
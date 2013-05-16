CC = gcc
CFLAGS = -Wall -std=c99 -O0

PROGS = test

.PHONY: all clean

all: $(PROGS)

test: precompile/main.c
test: precompile/functions01.c
test: precompile/functions02.c

test: Uzd4/povsid_nice01.c
test: Uzd4/povsid_clock02.c
test: Uzd4/povsid_clock01.c
test: Uzd4/povsid_exit01.c
test: Uzd4/povsid_cpulimit01.c
test: Uzd4/povsid_limits02.c
test: Uzd4/povsid_limits02.c

clean:
	-rm -f $(RPOGS)
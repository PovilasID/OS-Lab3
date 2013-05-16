targets = test run_test

all: $(targets)

test: precompile/main.c
	gcc -Wall -pedantic precompile/*.c -o test

run_test: test
	./test
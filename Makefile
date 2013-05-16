all::
	gcc -Wall precompile/main.c -o run

test:: check

check::
	./run
/* Failas: hello3.c */
#include <stdio.h>

int hellofunc( const char * s );

int hellofunc( const char * s ) {
	puts( s );
	return 1;
}

int main() {
	int a = 10, i;

	for( i=0; i < a; i++ ) {
		hellofunc( "Hello, World!" );
	}
	
	a = 0x762;
	
	return a;
}
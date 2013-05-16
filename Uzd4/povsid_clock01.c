/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_clock01.c */

#include <stdio.h>
#include <time.h>

int ps_test_clock();

int ps_test_clock(){
	clock_t start, end, diff;
	int i;
	start = clock();
	for( i = 0; i< 0x7FFFFFFF; i++);
		end = clock();
	diff = end - start;
	printf( "CLOCKS_PER_SEC = %ld\n start=%ld\n end=%ld\n diff=%ld, diff(s)=
		%f\n", CLOCKS_PER_SEC, start, end, diff, (double)diff / CLOCKS_PER_SEC );
	return 1;
}
int main( int argc, char * argv[] ){
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	ps_test_clock();
	return 0;
}
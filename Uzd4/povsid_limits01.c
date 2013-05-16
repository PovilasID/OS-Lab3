/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_limits01.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ps_memsize();

int ps_memsize(){
	long pagesize, pages;
	pagesize = sysconf( _SC_PAGESIZE );
	pages = sysconf( _SC_PHYS_PAGES );
	printf( "System:\n\tpage size: %ld\n\tpages: %ld\n", pagesize, pages );
	printf( "Total system RAM: %.1f MB\n", (double)pagesize * pages / 1024 /
		1024 );
	return 1;
}
int main(){
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	ps_memsize();
	return 0;
}
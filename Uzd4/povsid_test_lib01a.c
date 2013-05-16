/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_lib01a.c */

#include <stdio.h>
#include "povsid_lib01.h"

int main(){
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	povsid_libfunc01( "Library test 1" );
	povsid_libvar01 = 5.1;
	povsid_libfunc01( "Library test 2" );
	return 0;
}
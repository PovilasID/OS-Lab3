/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_lib01.c */

#include <stdio.h>
#include "povsid_lib01.h"

double povsid_libvar01;

int povsid_libfunc01( const char *s ){
	printf( "Dynamic library for testing, %s\n", __FILE__ );
	printf( "\tparameter: \"%s\"\n", s );
	printf( "\tlib variable = %f\n", povsid_libvar01 );
	return 0;
}
/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_open01.c */

#ifndef POVSID_OPEN01_C
#define POVSID_OPEN01_C

int ps_test_open(const char *name);
int ps_test_close(int fd);

#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main( int argc, char *argv[] ){
	int d;
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	if( argc != 2 ){
		printf( "Naudojimas:\n %s failas_ar_katalogas\n", argv[0] );
		exit( 255 );
	}
	d = ps_test_open( argv[1] );
	ps_test_close( d );
	ps_test_close( d ); /* turi mesti close klaida */
	return 0;
}

#endif

int ps_test_open(const char *name){
	int dskr;
	dskr = open( name, O_RDONLY );
	if( dskr == -1 ){
		perror( name );
		exit(1);
	}
	if(__INCLUDE_LEVEL__ == 0)
		printf( "dskr = %d\n", dskr );
	return dskr;
}
int ps_test_close(int fd){
	int rv;
	rv = close( fd );
	if( rv != 0 ) perror ( "Klaida iškvietus close() funkciją" );
	else if (__INCLUDE_LEVEL__ == 0) puts( "closed" );
	return rv;
}
#endif
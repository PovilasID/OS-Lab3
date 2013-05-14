/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_nftw01.c */
#ifndef POVSID_NFTW01_C
#define POVSID_NFTW01_C

#include <ftw.h>
int ps_ftwinfo(const char *p, const struct stat *st, int fl, struct FTW	*fbuf);

#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(){
	int rv;
	printf( "(C) 2013 kestutis Paulikas, %s\n", __FILE__ );
	rv = nftw( ".", ps_ftwinfo, 20, 0 );
	if( rv == -1 ){
		perror( "nftw failed" );
		exit( 1 );
	}
	if( rv != 0 ){
		printf( "ntfw fn function returnd %d != 0 -> nftw finished\n", rv );
	}
	return 0;
}
#endif
int ps_ftwinfo(const char *p, const struct stat *st, int fl, struct FTW	*fbuf){
	static int cnt = 0;
	puts( p );
	cnt++;
if( cnt >= 10 ) return cnt; /* pabandykite uzkomentuoti sita elutę */
	return 0;
}
#endif
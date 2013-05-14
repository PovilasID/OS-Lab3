/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_nftw02.c */
#ifndef POVSID_NFTW02_C
#define POVSID_NFTW02_C


#include <ftw.h>

int ps_ftwinfo(const char *p, const struct stat *st, int fl, struct FTW *fbuf);

#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv){
	int rv;
	int flags = 0;
	
	printf( "(C) 2013  Povilas Sidaravicius %s\n", __FILE__ );
	flags |= FTW_PHYS;
	
	rv = nftw((argc < 2) ? "." : argv[1], ps_ftwinfo, 20, flags);
	
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
int ps_ftwinfo(const char *p, const struct stat *st, int fl, struct FTW *fbuf){
	static int cnt = 0;
	puts( p );
	cnt++;
	return 0;
}
#endif
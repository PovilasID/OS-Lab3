/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_limits02.c */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/resource.h>

int ps_change_filelimit( int nslimit, int nhlimit );
int ps_test_filelimit( const char *fn );

int ps_change_filelimit( int nslimit, int nhlimit ){
	struct rlimit rl;
	getrlimit( RLIMIT_NOFILE, &rl );
	printf( "RLIMIT_NOFILE %ld (soft) %ld (hard)\n", rl.rlim_cur, rl.rlim_max
		);
	rl.rlim_cur = nslimit;
	rl.rlim_max = nhlimit;
	setrlimit( RLIMIT_NOFILE, &rl );
	getrlimit( RLIMIT_NOFILE, &rl );
	printf( "RLIMIT_NOFILE %ld (soft) %ld (hard)\n", rl.rlim_cur, rl.rlim_max
		);
	return 1;
}

int ps_test_filelimit( const char *fn ){
	int n;
	for( n = 0; -1 != open( fn, O_RDONLY ); n++ );
		printf( "Can open %d files\n", n );
	return 1;
}

int main( int argc, char *argv[] ){
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	ps_change_filelimit( 20, 100 );
	ps_test_filelimit( argv[0] );
	return 0;
}
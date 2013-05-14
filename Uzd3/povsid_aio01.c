/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_aio01.c */

#ifndef POVSID_AIO01_C
#define POVSID_AIO01_C

#include <stdio.h>
#include <string.h>
#include <aio.h>

#define BUFFLEN 1048576

int ps_test_aio_read_start(const int d, struct aiocb *aiorp, void *buf, const int count );
int ps_test_dummy( const void *data, int n );
int ps_test_aio_read_waitcomplete( struct aiocb *aiorp );
int ps_test_aio_read(struct aiocb *aiocbp);
int ps_test_aio_suspend(const struct aiocb * const list[], int nent, const struct timespec *timeout);
int ps_test_aio_return(struct aiocb *aiocbp);


#if __INCLUDE_LEVEL__ == 0
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "../../uzd2/povsid_open01.c"

int main(){
	int d;
	struct aiocb aior;
	char buffer[BUFFLEN];
	printf( "(C) 2013 Povilas Sidaravicius %s\n", __FILE__ );
	d = ps_test_open( "/dev/urandom", O_RDONLY );
	ps_test_aio_read_start( d, &aior, buffer, sizeof(buffer) );
	ps_test_dummy( buffer, sizeof(buffer) );
	ps_test_aio_read_waitcomplete( &aior );
	ps_test_close( d );
	ps_test_dummy( buffer, sizeof(buffer) );
	return 0;
}
#endif

int ps_test_aio_read_start( const int d, struct aiocb *aiorp, void *buf,
	const int count ){
	int rv = 0;
	memset( (void *)aiorp, 0, sizeof( struct aiocb ) );
	aiorp->aio_fildes = d;
	aiorp->aio_buf = buf;
	aiorp->aio_nbytes = count;
	aiorp->aio_offset = 0;
	rv = ps_test_aio_read( aiorp );
	return rv;
}
int ps_test_aio_read(struct aiocb *aiocbp){
	int rv;
	if( (rv = aio_read(aiocbp)) == -1 ){
		perror( "aio_read failed" );
		abort();
	}
	return rv;
}
int ps_test_dummy( const void *data, int n ){
	int i, cnt = 0;
	for( i = 0; i < n; i++ )
		if( ((char*)data)[i] == '\0' ) cnt++;
	printf( "Number of '0' in data: %d\n", cnt );
	return 1;
}
int ps_test_aio_read_waitcomplete( struct aiocb *aiorp ){
	const struct aiocb *aioptr[1];
	int rv;
	aioptr[0] = aiorp;
	rv = ps_test_aio_suspend( aioptr, 1, NULL );

	rv = ps_test_aio_return( aiorp );
	printf( "AIO complete, %d bytes read.\n", rv );
	return 1;
}
int ps_test_aio_suspend(const struct aiocb * const list[], int nent, const struct timespec *timeout){
	int rv;
	if( (rv = aio_suspend(list, nent, timeout)) == 0 ){
		perror( "aio_suspend failed" );
		abort();
	}
	return rv;
}
int ps_test_aio_return(struct aiocb *aiocbp){
	int rv;
	if ( (rv = aio_return(aiocbp) ) == -1) {
		perror("aio_return failed");
		abort();
	}
	return rv;
}
#endif
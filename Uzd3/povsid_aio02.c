/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_aio02.c */

#ifndef POVSID_AIO02_C
#define POVSID_AIO02_C

#include <aio.h>

int ps_read_bytes(int desc, struct aiocb *block, char *buf, int bufOffset, int bytes);
int ps_read_wait(struct aiocb *block);

#if __INCLUDE_LEVEL__ == 0
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "../uzd2/povsid_open01.c"
#include "povsid_aio01.c"
static const int bufferSize = 1048576;

int rd;
void ps_exit(int code);

int main(){
	struct aiocb block;
	char *buf;
	int n = 0, t;
	buf = malloc(bufferSize);
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	rd = ps_test_open("/dev/urandom", O_RDONLY);
	if(rd == -1){
		printf("Klaida atidarinejant faila\n");
		ps_exit(1);
	}
	while(n < bufferSize){
		if(ps_read_bytes(rd, &block, buf, n, bufferSize - n) != 0)
			ps_exit(1);
		t = ps_read_wait(&block);
		if(t > 0){
			n += t;
			printf("Perskaityta %d baitu\n", n);
		}else
			ps_exit(1);
	}
	ps_exit(0);
	return 0;
}
#endif
void ps_exit(int code){
	ps_test_close(rd);
	exit(code);
}

int ps_read_bytes(int desc, struct aiocb *block, char *buf, int bufOffset, int bytes){
	memset((void*)block, 0, sizeof(struct aiocb));
	block->aio_fildes = desc;
	block->aio_buf = buf + bufOffset;
	block->aio_nbytes = bytes;
	block->aio_offset = 0;
	if(ps_test_aio_read(block) != 0){
		printf("Klaida skaitymo pradzioje\n");
		return -1;
	}
	return 0;
}

int ps_read_wait(struct aiocb *block){
	const struct aiocb *temp[1];
	temp[0] = block;
	if(ps_test_aio_suspend(temp, 1, NULL) != 0){
		printf("Klaida skaitymo pabaigoje\n");
		return -1;
	}
	return ps_test_aio_return(block);
}

#endif
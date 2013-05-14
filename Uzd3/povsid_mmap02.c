/*Darius Lapunas IF-1/8 darlap1*/
/*darlap1_mmap02.c*/

#ifndef POVSID_MMAP02_C
#define POVSID_MMAP02_C

#include <aio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "../uzd2/povsid_open01.c"
#include "povsid_seek01.c"
#include "povsid_mmap01.c"

char *ps_map(int d, int size, int read);
int ps_test_fstat(int fd, struct stat *buf);

#if __INCLUDE_LEVEL__ == 0

void ps_exit(int code);
int rd;
int wd;

int main(int argc, char *argv[]){
	int s;
	struct stat status;
	void *rm, *wm;
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	if(argc < 3){
		printf("Reikia 2 argumentu: skaitymui ir rasymui\n");
		ps_exit(1);
	}

	if( (rd = ps_test_open(argv[1], O_RDONLY) ) == -1)
		ps_exit(1);

	if( (wd = ps_test_open(argv[2], O_RDWR|O_CREAT, S_IRWXU|S_IWGRP|S_IROTH) ) == -1)
		ps_exit(1);

	if(ps_test_fstat(rd, &status) == -1 )
		ps_exit(1);
	s = status.st_size;
	printf("Dydis - %d baitu\n", s);
	rm = ps_map(rd, s, 1);
	wm = ps_map(wd, s, 0);
	memcpy(wm, rm, s);
	if(ps_test_munamp(rm, s) == -1)
		ps_exit(1);
	if(ps_test_munamp(wm, s) == -1)
		ps_exit(1);
	ps_exit(0);
	return 0;
}

void ps_exit(int code){
	close(rd);
	close(wd);
	exit(code);
}
#endif

char *ps_map(int d, int size, int read){
	void *buf;
	if(!read){
		ps_test_lseek(d, size - 1, SEEK_SET);
		ps_test_write(d, &d, 1);
		buf = ps_test_mmap(NULL, size, PROT_WRITE|PROT_READ, MAP_SHARED, d, 0);
	}else{
		buf = ps_test_mmap(NULL, size, PROT_READ, MAP_SHARED, d, 0);
	}
	if(buf == MAP_FAILED)
		ps_exit(1);
	return buf;
}

int ps_test_fstat(int fd, struct stat *buf){
	if (fstat(fd, buf) == -1) {
		perror("fstat() failed");
	}
	return 0;
}
#endif

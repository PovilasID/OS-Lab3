/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_seek01.c */

#ifndef POVSID_SEEK01_C
#define POVSID_SEEK01_C

#include <unistd.h>
#include <fcntl.h>


#include "../uzd2/povsid_open01.c"

int ps_test_lseek(int fildes, off_t offset, int whence);
int ps_test_write(int fildes, const void *buf, size_t nbyte);

#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>

const int SIZE = 1024;

int seek(const char *to);

int main(int argc, char **argv){

	if(argc != 2) {
		printf("Komandos sablonas:\n %s failo_pavadinimas\n", argv[0]);
		return -1;
	}
	seek(argv[1]);
	
	return 0;
}

int seek(const char *to){
	int fd_to;
	int fd_wr;
	
	char *buffer;
	buffer = malloc(sizeof(char));
		
	fd_to = ps_test_open(to, O_WRONLY | O_CREAT);

	ps_test_lseek(fd_to,SIZE,SEEK_SET);
	
	ps_test_write(fd_to, buffer, 1);
	
	ps_test_close(fd_to);
	ps_test_close(fd_wr);
	return 0;
}
#endif
int ps_test_lseek(int fildes, off_t offset, int whence){
	if(lseek(fildes, offset, whence) == -1){	
		perror("lseek fail");
		ps_test_close(fildes);
		return -1;	
	}
	return 0;
}

int ps_test_write(int fildes, const void *buf, size_t nbyte){
	int fd_wr;
	if((fd_wr = write(fildes, buf, nbyte)) == -1 ){
		perror("fd_wr fail");
		close(fildes);
		return -1;
	}	
	return fd_wr;
}
#endif
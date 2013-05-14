/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_frw01.c */

#ifndef POVSID_FRW01_C
#define POVSID_FRW01_C

#include <stdio.h>
#include <fcntl.h>

FILE *ps_test_fopen(const char *filename, const char *mode);
int ps_test_fclose(FILE *stream);
int ps_test_fread(void *ptr, size_t size, size_t nitems, FILE *stream);
int ps_test_fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream);
int copy(const char *to, const char *from, int bytes);


#if __INCLUDE_LEVEL__ == 0
#include <stdlib.h>

#include <unistd.h>
#include <limits.h>

#include <sys/stat.h>
#include <sys/types.h>
int main(int argc, char **argv){

	int bytes;
	if(argc != 4){
		printf("Komandos sablonas:\n %s kopijuojamas_failas direkotorija_i_kur_kopijuojama baitu_skaicius\n", argv[0]);
		return 1;
	}
	bytes = atoi(argv[3]);
	printf("Baitai skaicium %i\n", bytes);
	copy(argv[2], argv[1], bytes);

	return 0;
}
#endif

FILE *ps_test_fopen(const char *filename, const char *mode){
	FILE *fd_from;
	if((fd_from = fopen(filename, mode)) == NULL ){
		perror("fd_from fail");
		return NULL;
	}
	return fd_from;
}

int ps_test_fclose(FILE *stream){
	if (fclose(stream)==EOF) {
		perror("fclose fail");
		return -1;
	}
	return 0;
}
int ps_test_fread(void *ptr, size_t size, size_t nitems, FILE *stream){
	if(fread(ptr, size, nitems, stream) == NULL){
		perror("Nepavyko nuskaityti");
		ps_test_fclose(stream);
		return -1;
	}
	return 0;
}

int ps_test_fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream){
	if(fwrite(ptr, size, nitems, stream) != nitems){
		perror("Nepavyko irasyti");
		ps_test_fclose(stream);
		return -1;
	}
	return 0;
}

int copy(const char *to, const char *from, int bytes){
	FILE *fd_to, *fd_from;

	char *buffer;
	buffer = malloc(sizeof(char));
	
	fd_from = ps_test_fopen(from, "r");

	fd_to = ps_test_fopen(to, "w+");
	
	if(fread(buffer, 1, bytes, fd_from)  == -1)
		ps_test_fclose(fd_to);
	
	if(fwrite(buffer, 1, bytes, fd_to) == -1)
		ps_test_fclose(fd_from);
		
	fclose(fd_from);
	fclose(fd_to);
	
	return 0;
}
#endif
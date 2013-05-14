/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_getcwd02.c */

#ifndef POVSID_GETCWD02_C
#define POVSID_GETCWD02_C

int ps_test_chdir(char *directory);
int ps_test_fchdir(int dskr);

#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "povsid_open01.c"
#include "povsid_getcwd01.c"

int main(){
	int dir;
	printf( "(C) 2013 Povilas Sidaravicius %s\n", __FILE__ );

	printf("%s\n", ps_test_getcwd());
	printf("dir = %d\n", dir = ps_test_open("."));
	ps_test_chdir("/tmp");
	printf("%s\n", ps_test_getcwd());
	ps_test_fchdir(dir);
	printf("%s\n", ps_test_getcwd());

	return 0;
}
#endif

int ps_test_chdir(char *directory){
	int ret;
	if ( (ret = chdir (directory) ) == -1) {
		perror("Klaida iškvietus chdir() funkciją");
	}
	return ret;
}

int ps_test_fchdir(int dskr){
	if (fchdir(dskr) != 0)
		perror("Klaida iškvietus fchdir() funkciją");
	ps_test_close(dskr);
	return 1;
}
#endif
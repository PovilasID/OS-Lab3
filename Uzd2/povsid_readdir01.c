/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_readdir01.c */

#ifndef POVSID_READDIR_C
#define POVSID_READDIR_C

#include <dirent.h>

DIR *ps_test_opendir(const char * dir_name);
void ps_test_list_dir (const char * dir_name);
int ps_test_closedir(DIR * d, const char * dir_name);

#if __INCLUDE_LEVEL__ == 0
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <limits.h>
#include "povsid_getcwd01.c"

int main (){
	char *cwd;
	if ((cwd = ps_test_getcwd( NULL, pathconf(".",_PC_PATH_MAX))) != NULL){
		puts(cwd);
	}else{
		perror("Klaida iškviečiant getcwd() funkcija");
	}
	
	puts("Failu sarasas: ");
    ps_test_list_dir(cwd);
	free(cwd);
    return 0;
}
#endif

DIR *ps_test_opendir(const char * dir_name){
	DIR *d;
	if ((d = opendir (dir_name))==NULL){
        fprintf (stderr, "Negalejom atidaryti '%s': %s\n", dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }
    return d;
}


int ps_test_closedir(DIR * d, const char * dir_name){
    if (closedir (d)){
        fprintf (stderr, "Negalejom uzdaryti '%s': %s\n", dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }
    return 0;
}

void ps_test_list_dir (const char * dir_name){
    DIR *d;
    struct dirent *DirEntry;
	d = ps_test_opendir(dir_name);
   
	
	while((DirEntry = readdir(d)) != NULL){
		printf ("%s/%s , %i \n", dir_name, DirEntry->d_name, DirEntry->d_ino);
	}   

	ps_test_closedir(d, dir_name);
}
#endif
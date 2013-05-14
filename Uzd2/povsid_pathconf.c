/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_pathconf.c */

#ifndef POVSID_PATHCONF_C
#define POVSID_PATHCONF_C

int ps_test_pathconf(const char *filename, int parameter);


#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <unistd.h>
int main() {
	
	puts("Failo vardo maksimalus ilgis: ");
	ps_test_pathconf(".", _PC_NAME_MAX);
	puts("Failo kelio maksimalus ilgis: ");
	ps_test_pathconf(".", _PC_PATH_MAX);

	return 0;
}
#endif
#include <errno.h>
int ps_test_pathconf(const char *filename, int parameter) {
	errno = 0;

	int result;
	if ( ( result = pathconf(filename, parameter) ) == -1){
		if (errno == 0){
			puts("Neriboto ilgio");
		}else{	
			perror("Klaida iškviečiant pathconf() funkcija");
		}
	}else{
		if (__INCLUDE_LEVEL__== 0)
			printf("%ld\n", result);
	}
	return result;
}
#endif
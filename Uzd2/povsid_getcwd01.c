/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_getcwd01.c */

#ifndef POVSID_GETCWD01_C
#define POVSID_GETCWD01_C

char *ps_test_getcwd();


#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
int main(){
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	ps_test_getcwd();
	return 0;
}
#endif
#include "povsid_pathconf.c"
char *ps_test_getcwd(){
    char *ret = getcwd(NULL, ps_test_pathconf(".",_PC_PATH_MAX));
    if (ret == NULL)
        perror("Klaida iškvietus getcwd() funkciją");
    else if (__INCLUDE_LEVEL__ == 0)
        puts(ret);
    return ret;
}
#endif
/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_test_lib01b.c */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int (*fptr)(const char *s);
double *pd;

int main(){
	void *dl;
	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );
	dl = dlopen( "lib/libpovsid01.so", RTLD_LAZY | RTLD_LOCAL );
	if( dl == NULL ){
		puts( dlerror() );
		exit(1);
	}
	pd = dlsym( dl, "povsid_libvar01" );
	if( pd == NULL ){
		puts( dlerror() );
		exit(1);
	}
/* fptr = (int (*)(char*)) dlsym( dl, "povsid_libfunc01" ); */
	*(void**)(&fptr) = dlsym( dl, "povsid_libfunc01" );
	if( fptr == NULL ){
		puts( dlerror() );
		exit(1);
	}
	*pd = 5.2;
	(*fptr)( "Library test (manualy loaded)" );
	dlclose( dl );
	return 0;
}
Š
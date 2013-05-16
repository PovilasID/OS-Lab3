/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_clock02.c */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct tm *ps_test_localtime(const time_t *time){
	struct tm *ltime;
	if( (ltime = localtime(time)) == NULL){
		perror("Klaida iskvieciant localtime() funkcija ");
		return NULL;
	}
	return ltime;
}
struct tm *ps_test_gmtime( const time_t* time ){
	struct tm *gmt;
	if ( (gmt = gmtime(time)) == NULL) {
		perror("Klaida iskvieciant gmtime() funkcija ");
		return NULL;
	}
	return gmt;
}
char* ps_test_asctime( const tm* time_ptr ){
	char *atime;
	if ( (atime = asctime() ) == NULL ) {
		perror("Klaida iskvieciant asctime() funkcija ");
		return NULL;
	}
	return atime;
}
time_t ps_test_time(time_t *t){
	time_t tt;
	if ( (tt = time(t) ) == ((time_t) -1) ) {
		perror("Klaida iskvieciant time() funkcija");
		return -1;
	}
	return tt;
}

int main(){
	time_t abstract_time;
	struct tm *local, *utc;
	char *utcs, *locals;

	printf( "(C) 2013 Povilas Sidaravicius, %s\n", __FILE__ );

	ps_test_time(&abstract_time);
	local = ps_test_localtime(&abstract_time);
	utc = ps_test_gmtime(&abstract_time);
	utcs = ps_test_asctime(utc);
	locals = ps_test_asctime(local);
	printf("Local time: %s\nUTC time: %s\n", locals, utcs);
	free(local);
	free(utc);
	free(utcs);
	free(locals);
	return 0;
}
/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_cpulimits01.c */

#include <aio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/resource.h>

int ps_test_setrlimit(int resource, const struct rlimit *rlim) {
	if (setrlimit(resource, rlim) == -1) {
		perror("Klaida iskvietus setrlimit() funkcija");
		return -1;
	}
	return 0;
}

int ps_test_getrlimit(int resource, struct rlimit *rlim){
	if (getrlimit( resource, &rlim ) == -1) {
		perror("Klaida iskvietus getrlimit() funkcija");
		return  -1;
	}
	return 0;
}

int ps_test_printf_rlimits(const struct rlimit *rlim, int resource){
	if(printf( "INT kodas = %d %ld (soft) %ld (hard)\n", 
		resource, rlim.rlim_cur, rlim.rlim_max) < 0){
		perror("Klaida isvednatnt rlimit duoemnis");
		return -1;
	return 0;
}


int ps_test_limit_handing(int resource, struct rlimit rlim, int limit){
	ps_tetst_getrlimit( resource, &rlim );
	ps_test_printf_rlimits(&rlim, resource);
	rlim.rlim_cur = limit;
	rlim.rlim_max = limit;
	ps_test_setrlimit(resource, &rlim);
	ps_test_printf_rlimits(&rlim, resource);
	return 0;
}

int main(){
	struct rlimit rl;
	int i;
	ps_test_limit_handing(RLIMIT_CPU, rl, 3);

	ps_test_limit_handing(RLIMIT_CORE, rl, 0);

	for(i = INT_MIN; i < INT_MAX; i++);
	return 0;
}
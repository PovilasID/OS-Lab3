/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_nice01.c */

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

int main(int argc, char *argv[]){
	int i;
	int nc;
	clock_t start;
	clock_t	end;
	time_t startT;
	time_t endT;
	double cpu_laikas;
	double sekundes;
	
	i = 0;
	nc = nice(atoi(argv[1]));
	start = clock();
	time(&startT);
	for(i = INT_MIN; i < INT_MAX; i++);
	
	end = clock();
	time(&endT);
	sekundes = difftime(endT, startT);
	cpu_laikas = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Pradzia: %sPabaiga: %sSkirtumas: %5.2f\n", asctime(localtime(&startT)), asctime(localtime(&endT)), sekundes);
	printf("CPU laikas %5.2f s \n", cpu_laikas);
	return 0;
}
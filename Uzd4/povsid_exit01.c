/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_exit01.c */

void funkcija_1(void)  {
	printf("F1\n");
}
void funkcija_2(void) {
	printf("F2\n");
}
void funkcija_3(void) {
	printf("F 3\n");
}

int ps_test_atexit(void (*function)(void)){
	if (atexit(function) != 0) {
		fprintf(stderr, "cannot set exit function\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}

int main(int argc, char *argv[]){
	int argi;

	if(argc != 2){	
		printf("Iveskite skaiciu:\n  1 - exit() \n  2 - abort() \n  betkoks simbolis - return");
		return 1;
	}
	printf("%s \n", argv[1]);

	argi = atoi(argv[1]);


	ps_test_atexit(funkcija_1);
	ps_test_atexit(funkcija_2);
	ps_test_atexit(funkcija_3);
	
	if( argi == 1){
		_Exit(1);
	} else if (argi == 2){
		abort();
	} else {
		return 0;
	}
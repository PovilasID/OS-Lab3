/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_misc01.c */

#ifndef POVSID_MISC01_C
#define POVSID_MISC01_C


#if __INCLUDE_LEVEL__ == 0
#include <stdio.h>
int main(int argc, char **argv){
	
	char confirm;
    if(argc != 2){    
        return 1;
	}
	
	printf("Ar tikrai norite istrinti faila?\n Irasykite :Y (taip) arba N (ne) \n");
	scanf("%c", &confirm );
	
	if((confirm == 'Y') || (confirm == 'y')){
		ps_test_remove(argv[1]);
	}else if((confirm == 'N') || (confirm == 'n')){
		printf("Failas %s neistrintas \n", argv[1]);
	}else{
		printf("Netinkamas simbolis!\n Prasome ivesti tik Y arba N raide");
	}
    return 0;
}
#endif

int ps_test_remove(const char *path){
	if(remove(path) != -1)	{
		printf("Failas istrintas\n");
	}else{
		perror("Klaida iškvietus remove() funkciją\n");
	}
	return 0;
}
#endif
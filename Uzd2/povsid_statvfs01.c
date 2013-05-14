/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_statvfs01.c */

#ifndef POVSID_STATVFS01_C
#define POVSID_STATVFS01_C


int print_statvfs(const char *name);

#if __INCLUDE_LEVEL__ == 0
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(int argc, char **argv){
    if(argc != 2){
        printf( "Naudojimas:\n %s failas_ar_katalogas\n", argv[0] );
        exit( 255 );
    }

	print_statvfs(argv[1]);
 
    return 0;
}
int print_statvfs(const char *name){
    struct statvfs *buf;
    buf = malloc(sizeof(struct statvfs));
    
    char* c_time_string;
    
    ps_test_statvfs(name, buf);
 
    printf("Informacija apie %s\n",name);
    printf("---------------------------\n");
    printf("Block dydis: \t\t\t\t\t\t%d\n",buf->f_bsize);
    printf("Fragmento dydis: \t\t\t\t\t%d\n",buf->f_frsize);
    printf("fs dydis f_frsize vienetais: \t\t\t\t%d\n",buf->f_blocks);
    printf("Laisvi blokai privilegijuotiems/neprivilegijuotiems: \t%d/%d\n",buf->f_bfree, buf->f_bavail);
    printf("Inodes: \t\t\t\t\t\t%d\n",buf->f_files);
    printf("Laisvi inodes privilegijuotiems/neprivilegijuotiems: \t%d/%d\n",buf->f_ffree, buf->f_favail);
    printf("Failu sistemos ID: \t\t\t\t\t%d\n",buf->f_fsid);
    printf("Mount flagai: \t\t\t\t\t\t%d\n",buf->f_flag);
    printf("Failo vardo max ilgis: \t\t\t\t\t%d\n",buf->f_namemax);
    return 0;
}
#endif
int ps_test_statvfs(const char *path, struct statvfs *buf){
    if(statvfs(path,buf) == -1){
        perror("Klaida iškvietus stat() funkciją");
        return -1;
    }
    return 0;
}
#endif
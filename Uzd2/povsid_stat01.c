/* Povilas Sidaravičius IF-1/10 povsid */
/* Failas: povsid_stat01.c */

#ifndef POVSID_STAT01_C
#define POVSID_STAT01_C


int print_stat(const char *name);

#if __INCLUDE_LEVEL__ == 0
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
int main(int argc, char **argv){
    if(argc != 2){
        printf( "Naudojimas:\n %s failas_ar_katalogas\n", argv[0] );
        exit( 255 );
    }

	print_stat(argv[1]);
 
    return 0;
}
int print_stat(const char *name){
    struct stat *buf;
    buf = malloc(sizeof(struct stat));
    
    char* c_time_string;
    
    ps_test_stat(name, buf);
 
    printf("Informacija apie %s\n",name);
    printf("---------------------------\n");
    printf("Irenginio ID: \t\t%d\n",buf->st_dev);
    printf("Failo mode: \t\t%d\n",buf->st_mode);
    printf("Irenginio UID/GUI: \t%d/%d\n",buf->st_uid, buf->st_gid);
    c_time_string = ctime(&buf->st_atime);
    printf("Failo naudotas: \t%s\n",c_time_string);
    c_time_string = ctime(&buf->st_mtime);
    printf("Failo redaguotas: \t%s\n",c_time_string);
    c_time_string = ctime(&buf->st_ctime);
    printf("Failo keistas: \t\t%s\n",c_time_string);
    
    printf("Failo dydis baiais: \t\t%d baitu\n",buf->st_size);
    printf("Failo dydis blockais: \t\t%d blocku\n",buf->st_blocks);
    printf("Nuorodu skaicius: \t%d\n",buf->st_nlink);
    printf("Failo inode: \t\t%d\n",buf->st_ino);
    printf("Failo leidimai: \t");
    printf( (S_ISDIR(buf->st_mode)) ? "d" : "-");
    printf( (buf->st_mode & S_IRUSR) ? "r" : "-");
    printf( (buf->st_mode & S_IWUSR) ? "w" : "-");
    printf( (buf->st_mode & S_IXUSR) ? "x" : "-");
    printf( (buf->st_mode & S_IRGRP) ? "r" : "-");
    printf( (buf->st_mode & S_IWGRP) ? "w" : "-");
    printf( (buf->st_mode & S_IXGRP) ? "x" : "-");
    printf( (buf->st_mode & S_IROTH) ? "r" : "-");
    printf( (buf->st_mode & S_IWOTH) ? "w" : "-");
    printf( (buf->st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
 
    printf("Failas %s symlink\n", (S_ISLNK(buf->st_mode)) ? "yra" : "nera");
    return 0;
}
#endif
int ps_test_stat(const char *path, struct stat *buf){
    if(stat(path,buf) == -1){
        perror("Klaida iškvietus stat() funkciją");
        return -1;
    }
    return 0;
}
#endif
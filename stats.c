#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
 
    struct stat fileStat;
    if(stat("in.txt",&fileStat) < 0)    
        return 1;
 
    printf("Information for %s\n","in.txt");
    printf("---------------------------\n");
    printf("File Size: \t\t%lld bytes\n",fileStat.st_size);
    printf("Number of Links: \t%d\n",fileStat.st_nlink);
    printf("File inode: \t\t%llu\n",fileStat.st_ino);
 

    // int size = fileStat.st_mode;
    // int size2 = size & 0b111111111;
    // printf("file size originally: %o\n", size);
    // printf("file size: %o\n",size2);



    printf("File Permissions: \t");
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");

    // printf("\n%lu",sizeof(4));
    //printf("\n%x\n", 100);

    printf("\n%o\n",fileStat.st_mode & 0x1FF);

    printf("\n\n");

 
    return 0;
}
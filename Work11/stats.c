#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>

int main(){
 
    struct stat fileStat;
    if(stat("in.txt",&fileStat) < 0)    
        return 1;
    
    printf("Information for %s\n","in.txt");
    printf("---------------------------\n");

    printf("File Permissions: \t%o\n",fileStat.st_mode & 0x1FF);

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

    printf("\nNumber of Links: \t%ld\n",fileStat.st_nlink);

    printf("User ID: \t\t%s\n", getpwuid(fileStat.st_uid) -> pw_name);
    printf("Group ID: \t\t%s\n", getpwuid(fileStat.st_gid) -> pw_name);

    char *size;
    char *format = "%ldB";
    long file_size = fileStat.st_size;
      
    if(file_size/1000 > 0){
      file_size /= 1000;
      format = "%ldKB";
    }
    
    if(file_size/1000 > 0){
      file_size /= 1000;
      format = "%ldMB";
    }
    
    if(file_size/1000 > 0){
      file_size /= 1000;
      format = "%ldGB";
    }
    
    sprintf(size, format, file_size);
    
    printf("File Size: \t\t%s\n", size);
    
    printf("Last Accessed: \t\t%s", ctime(&fileStat.st_atime));

    printf("\n");

    return 0;
}

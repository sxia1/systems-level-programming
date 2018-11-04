#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){
  printf("Please enter the name of a directory: ");
  char name[100];
  scanf("%s", name);
  struct stat fileStat;
  struct dirent *entry;
  DIR *dir;
  
  dir = opendir(name);

  printf("Error: %s\n", strerror(errno));

  if(strcmp(strerror(errno), "Success") == 0){
  
    printf("Statistics for directory:\n");

    stat("test", &fileStat);
    printf("Total Directory Size: %ldB\n", fileStat.st_size);
  
    while(entry = readdir(dir)){
      if(entry -> d_type == DT_DIR){
	printf("%s\t-dir\n", entry -> d_name);
      }
      else{
	printf("%s\t-file\n", entry -> d_name);
      }
    }
  }
  closedir(dir);
}

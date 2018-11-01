#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(){
  struct stat fileStat;
  struct dirent entry;
  DIR *dir;
  
  dir = opendir("test");
  
  printf("Statistics for directory:\n");

  stat("test", &fileStat);
  printf("Total Directory Size: %ldB\n", fileStat.st_size);

  entry = *readdir(dir);
  printf("%s\n", entry.d_name);
  entry = *readdir(dir);
  printf("%s\n", entry.d_name);
  entry = *readdir(dir);
  printf("%s\n", entry.d_name);
  entry = *readdir(dir);
  printf("%s\n", entry.d_name);
  entry = *readdir(dir);
  printf("%s\n", entry.d_name);
  entry = *readdir(dir);
  printf("%s\n", entry.d_name);

  /*
    while(readdir(dir)){
    printf("%s\n", entry.d_name);
    entry = *readdir(dir);
  }
  */
  
  //printf("Directories:");

  //printf("Regular files:");
  
  closedir(dir);
}

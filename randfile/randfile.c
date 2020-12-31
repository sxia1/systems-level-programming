#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>

int randnum(){

  int fd = open("/dev/random", O_RDONLY);
  //printf("opening file: %s\n", strerror(errno));

  int *buffer = malloc(sizeof(int));
  int result = read(fd, buffer, sizeof(int));
  //printf("%d\n", result);
  //printf("reading file: %s\n", strerror(errno));  

  close(fd);
  int retVal = *buffer;

  free(buffer);
  return retVal;
}

int main(){

  //Populating array
  printf("Generating random numbers:\n");
  int arr[10];
  for(int i = 0; i < 10; i ++){
    arr[i] = randnum();
    printf("random %d: %d\n", i, arr[i]);
  }

  //Writing numbers to file...
  int fd = open("file.txt", O_WRONLY);
  write(fd, arr, 10 * sizeof(int));
  printf("\nwriting to file... %s\n", strerror(errno));
  close(fd);

  //Reading numbers from file...
  fd = open("file.txt", O_RDONLY);
  int buffer[10];
  int result = read(fd, buffer, 10 * sizeof(int));
  printf("\nreading from file... %s\n", strerror(errno));  

  //Verification that written values were the same:
  printf("\nVerification that written values were the same:\n");
  for(int i = 0; i < 10; i ++){
    printf("random %d: %d\n", i, buffer[i]);
  }

  
  return 0;
}

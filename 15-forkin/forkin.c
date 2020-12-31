#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

//randnum():
//returns a random number between 5 and 20
char randnum(){
  int fd = open("/dev/random", O_RDONLY);
  int *buffer = malloc(sizeof(char));
  int result = read(fd, buffer, sizeof(char));
  close(fd);
  int retVal = *buffer;
  free(buffer);
  return retVal/16 + 5;
}

int main(){
  
  printf("Hi I am parent %d\n", getpid());

  pid_t child_a, child_b;
  
  //Forking the first child...
  child_a = fork();

  //when child_a is true, it is greater that zero
  //that means it is the parent process
  if(child_a){
    //Forking the second child...
    child_b = fork();
  }

  if(child_a == 0 || child_b == 0){
    printf("Hi, I am child %d\n", getpid());
    char num = randnum();
    sleep(num);
    printf("%d says it slept for %d years\n", getpid(), num);
    return num;
  }

  int status;
  int kid = wait(&status);
  printf("parent %d says %d slept for %d years\n", getpid(), kid, WEXITSTATUS(status));
  printf("Parent is done\n");
  return 0;
}

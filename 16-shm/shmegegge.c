#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define SHM_SIZE 200

int main(int argc, int *argv[]){
  key_t key = 123456;
  int shmid;
  char *data;
  char input[SHM_SIZE];
  
  shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
  data = shmat(shmid, 0, 0);
  printf("Content: %s\n", data);

  printf("Do you want to change the data in the shared memory segment? (y/n)");
  fgets(input, SHM_SIZE, stdin);
  if(strcmp(input, "y\n") == 0){
    printf("Please input a new string: ");
    fgets(input, SHM_SIZE, stdin);
    input[strlen(input) -1] = '\0';
    strncpy(data, input, SHM_SIZE);
    printf("Content: %s\n", data);
  }

  printf("Do you want to remove the shared memory segment? (y/n)");
  fgets(input, SHM_SIZE, stdin);
  if(strcmp(input, "y\n") == 0){
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);
    printf("shared memory segment removed\n");
  }
  return 0;
}

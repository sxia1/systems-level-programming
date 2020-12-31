#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("Exit due to SIGINT\n");
    exit(0);
  }
  else if(signo == SIGUSR1){
    printf("PPID: %d\n", getppid());
  }
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  int i = 1;
  while(i){
    printf("pid: %d\n", getpid());
    sleep(1);
    kill(getpid(), SIGUSR1);
  }
  
  return 0;
  
}

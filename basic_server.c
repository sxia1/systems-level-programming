#include <signal.h>
#include "pipe_networking.h"

static void sighandler(int signo){
  if(signo == SIGINT){
    //remove WKP
    remove("WELL_KNOWN_PIPE");
    exit(0);
  }
}

int main() {

  while(1){
    int to_client;
    int from_client;

    signal(SIGINT, sighandler);

    from_client = server_handshake( &to_client );

    //while client doesn't exit
    char PP[BUFFER_SIZE];
    int reading = 1;
    while(reading = read(from_client, PP, BUFFER_SIZE) > 0){
      //get data from client
      printf("read %s from client: %s\n", PP, strerror(errno));
      //process data
      char *flipped = malloc(strlen(PP) *sizeof(char));
      for(int i = 0; i < strlen(PP); i ++){
	flipped[strlen(PP) -i -1] = PP[i];
      }
      flipped[strlen(PP)] = '\0';
      //send processed data back to client
      write(to_client, flipped, strlen(PP));
      printf("write %s from client: %s\n", flipped, strerror(errno));
      free(flipped);
    }
    close(from_client);
    //reset for a new handshake
  }  
}

#include "pipe_networking.h"

int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  while(1){
    //Prompt user for input
    char input[BUFFER_SIZE];
    char mssg[BUFFER_SIZE];
    printf("Send this to the server: ");
    fgets(input, BUFFER_SIZE, stdin);
    input[strlen(input) -1] = '\0';
    //send input to server
    write(to_server, input, BUFFER_SIZE);
    printf("write %s to server: %s\n", input, strerror(errno));
    //get response from server and display to user
    read(from_server, mssg, BUFFER_SIZE);
    printf("read response %s from server: %s\n", mssg, strerror(errno));
  }
  close(from_server);
}

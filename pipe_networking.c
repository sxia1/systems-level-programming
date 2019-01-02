#include "pipe_networking.h"

/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {

  //server creates the well known pipe
  printf("creating WKP\n");
  //don't need int WKP = b/c it doesn't return a file descriptor
  mkfifo("WELL_KNOWN_PIPE", 0666);
  printf("1. create: %s\n", strerror(errno));

  //server receives the message
  int receive = open("WELL_KNOWN_PIPE", O_RDONLY);
  printf("4. opening read end: %s\n", strerror(errno));
  char PP[BUFFER_SIZE];
  read(receive, PP, BUFFER_SIZE); //don't need int reading =
  printf("5. read: %s\n", strerror(errno));

  //server removes the well known pipe
  printf("removing WKP\n");
  remove("WELL_KNOWN_PIPE");

  //server send message to client
  *to_client = open(PP, O_WRONLY);
  printf("6. opening write end: %s\n", strerror(errno)); 
  write(*to_client, ACK ,sizeof(ACK));
  printf("7. writing: %s\n", strerror(errno));

  //server receives a response
  read(receive, PP, BUFFER_SIZE);
  printf("10. read: %s\n", strerror(errno));
  printf("Handshake Complete\n");

  return receive;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {

  char PRIVATE_PIPE[BUFFER_SIZE];
  sprintf(PRIVATE_PIPE, "%d", getpid());

  //client create the private pipe
  printf("creating PP\n");
  mkfifo(PRIVATE_PIPE, 0666);
  printf("2. create: %s\n", strerror(errno));

  //client connects to the server
  *to_server = open("WELL_KNOWN_PIPE", O_WRONLY);
  printf("opening write end: %s\n", strerror(errno));

  //client sends a message to the server
  write(*to_server, PRIVATE_PIPE, BUFFER_SIZE);
  printf("3. write: %s\n", strerror(errno));

  //client receives message
  //OPEN PRIVATE_PIPE NOT "PRIVATE_PIPE"
  int receive = open(PRIVATE_PIPE, O_RDONLY);
  printf("opening read end: %s\n", strerror(errno));
  char mssg[BUFFER_SIZE];
  read(receive, mssg, BUFFER_SIZE);
  printf("8. read: %s\n", strerror(errno));

  //client removes private pipe
  //REMOVE PRIVATE_PIPE NOT "PRIVATE_PIPE"
  remove(PRIVATE_PIPE);
  printf("removing PP");

  //client responds to the message
  write(*to_server, ACK, sizeof(ACK));
  printf("9. write: %s\n", strerror(errno));

  return receive;
}

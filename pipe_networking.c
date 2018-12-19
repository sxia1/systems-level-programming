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
  int WKP = mkfifo("WELL_KNOWN_PIPE", 0666);
  printf("1. create: %s\n", strerror(errno));

  //server receives the message
  int receive = open("WELL_KNOWN_PIPE", O_RDONLY);
  printf("4. receive: %s\n", strerror(errno));
  char PP[BUFFER_SIZE];
  int reading = read(receive, PP, BUFFER_SIZE);
  printf("5. read: %s\n", strerror(errno));

  //server removes the well known pipe
  remove("WELL_KNOWN_PIPE");

  //server send message to client
  *to_client = open(PP, O_WRONLY);
  printf("6. opening: %s\n", strerror(errno)); 
  int writing = write(*to_client, ACK ,sizeof(ACK));
  printf("7. writing: %s\n", strerror(errno));

  //server receives a response
  reading = read(receive, PP, BUFFER_SIZE);
  printf("10. read: %s\n", strerror(errno));
  printf("Handshake Complete");
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
  int PP = mkfifo(PRIVATE_PIPE, 0666);
  printf("2. create: %s\n", strerror(errno));

  //client connects to the server
  *to_server = open("WELL_KNOWN_PIPE", O_WRONLY);

  //client sends a message to the server
  int writing = write(*to_server, PRIVATE_PIPE, BUFFER_SIZE);
  printf("3. write: %s\n", strerror(errno));
  
  //client receives message
  int receive = open("PRIVATE_PIPE", O_RDONLY);
  char mssg[BUFFER_SIZE];
  int reading = read(receive, mssg, BUFFER_SIZE);
  printf("8. read: %s\n", strerror(errno));

  //client removes private pipe
  remove("PRIVATE_PIPE");
  printf("9. write: %s\n", strerror(errno));

  //client responds to the message
  writing = write(*to_server, ACK, sizeof(ACK));
  return receive;
}

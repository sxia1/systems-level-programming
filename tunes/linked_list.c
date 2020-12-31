#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

//Insert Node in Front CHECK
struct song_node * insert_front(struct song_node *head, char *ncargo, char *acargo){
  struct song_node *new_node = malloc(sizeof(struct song_node));
  strncpy(new_node -> name, ncargo, 256);
  strncpy(new_node -> artist, acargo, 256);
  new_node -> next = head;
  head = new_node;
  return head;
}

//Insert Node Alphabetically CHECK
/* Cases:
   1. List is empty CHECK
   2. Insert at the front CHECK
   3. Insert in the middle CHECK
   4. Insert at the end CHECK
*/
struct song_node *insert_alpha(struct song_node *head, char *ncargo, char *acargo){
  //Case 1: list is empty
  if(!head ||
     //Case 2: new artist is goes first
     (strcmp(head -> artist, acargo) > 0 )||
     //Case 2: new artist is the same and  new name goes first
     //this doesn't work without "== 0"
     ( strcmp(head -> artist, acargo) == 0 && strcmp(head -> name, ncargo) > 0) )
    {
      //then insert the node at the front
      insert_front(head, ncargo, acargo);
    }
  //Case 3:
  else{
    //alias to head and track the previous node
    struct song_node *temp = head;
    struct song_node *before = temp;
    //Walk the temp and before to the point of insertion
    //while the current node isn't null and
    while(temp &&
	  //while the new_nodes artist is greater than prev artist or
	  (strcmp(temp -> artist, acargo) < 0 ||
	   //while the new_nodes artist is the same as the prev artist and
	   //the new_nodes name is greater than the prev name
	   (strcmp(temp -> artist, acargo) == 0 && strcmp(temp -> name, ncargo) < 0) ) )
      {
	before = temp;
	temp = temp -> next;
      }
    //create new_node
    struct song_node *new_node = malloc(sizeof(struct song_node));
    strncpy(new_node -> name, ncargo, 256);
    strncpy(new_node -> artist, acargo, 256);
    //then insert the node
    before -> next = new_node;
    new_node -> next = temp;
    return head;
  }
}

//Print List CHECK
void *print_list(struct song_node *head){
  struct song_node *temp = head;
  while(temp){
    printf("%s %s\n", temp -> artist, temp -> name);
    temp = temp -> next;
  }
}

//Find Specific CHECK
struct song_node *find_specific(struct song_node *head, char* nname, char * nartist){
  struct song_node *temp = head;
  while(temp){
    if(strcmp(temp -> artist, nartist) == 0 && strcmp(temp -> name, nname) == 0){
      return temp;
    }
    temp = temp -> next;
  }
}

//Find Artist Song CHECK
struct song_node *find_artist(struct song_node *head, char * nartist){
  struct song_node *temp = head;
  while(temp){
    if(strcmp(temp -> artist, nartist) == 0){
      return temp;
    }
    temp = temp -> next;
  }
}

//Find Length CHECK
int length(struct song_node *head){
  struct song_node *temp = head;
  int ctr = 0;
  while(temp){
    ctr ++;
    temp = temp -> next;
  }
  return ctr -1;
}

//Find Random CHECK
struct song_node *find_random(struct song_node *head){
  int num = rand() % length(head) +1;
  int ctr = 0;
  struct song_node *temp = head;
  while(num != ctr){
    temp = temp -> next;
    ctr ++;
  }
  return temp;
}

//Remove Node CHECK
struct song_node *remove_node(struct song_node *head, char* nname, char* nartist){
  struct song_node *temp = head;
  struct song_node *before = temp;
  if(strcmp(temp -> name, nname) == 0 && strcmp(temp -> artist, nartist) == 0){
    head = temp -> next;
    free(temp);
  }
  else{
    //while current node isn't NULL and
    while(temp){
      if(strcmp(temp -> name, nname) == 0 &&
	 strcmp(temp -> artist, nartist) == 0){
	before -> next = temp -> next;
	free(temp);
      }
      before = temp;
      temp = temp -> next;
    }
  }
  return head;
}

//Free List
struct song_node *free_list(struct song_node *head){
  struct song_node *temp = head;
  while(temp){
    temp = head -> next;
    free(head);
    head = temp;
  }
  return head;
}


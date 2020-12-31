#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


//takes a pointer to a node struct and prints out all of the data in the list
void print_list(struct node * head){
  struct node * temp = head;
  while(temp){
    printf("%d   ", temp -> cargo);
    temp = temp -> next;
  }
}

/* insert_front()
   takes a pointer to the existing list and the data to be added
   creates a new node and put it at the beginning of the list
   The second argument should match whatever data you contain in your nodes
   Returns a pointer to the beginning of the list */
struct node * insert_front(struct node * head, int i){
  //allocate memory and create node
  struct node *new_node = malloc(sizeof(struct node));
  new_node -> cargo = i;
  new_node -> next = head;
  head = new_node;
  return head;
}

/* free_list()
   Should take a pointer to a list as a parameter
   then go through the entire list freeing each node
   return a pointer to the beginning of the list
   (which should be NULL by then) */
struct node * free_list(struct node *head){
  struct node * temp = head;
  while (head){
    struct node *ntemp = head -> next;
    free(head);
    head = ntemp;
  }
  return head;
}

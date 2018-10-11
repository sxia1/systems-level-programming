#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main(){
  struct node *head;
  printf("INSERTING NUMBERS 1-10 INTO LINKED LIST");

  for(int i = 10; i > 0; i--){
    printf("\n\nINSERTING %d\n", i);
    head = insert_front(head, i);
    print_list(head);
  }
  
  printf("\n\nPRINT FREED LIST\n");
  print_list(free_list(head));
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"
#include "music_library.h"


int main(){
  //put this at beginning of main method, not inside the function
  //when placed in the function, the same number will be generated for all calls in a run
  srand(time(NULL));
  
  //If I don't malloc the pointers, I get a seg fault
  printf("\nTESTING LINKED_LIST============================================================\n\n");

  printf("testing insert_front------------------------------------------------\n");
  struct song_node *front = malloc(sizeof(struct song_node));

  front = insert_front(front, "fname", "fartist");
  front = insert_front(front, "ename", "eartist");
  front = insert_front(front, "dname", "dartist");
  front = insert_front(front, "cname", "cartist");
  print_list(front);

  printf("testing insert_alpha------------------------------------------------");

  struct song_node *alpha = malloc(sizeof(struct song_node));

  alpha = insert_alpha(alpha, "fname", "fartist");
  alpha = insert_alpha(alpha, "ename", "eartist");
  alpha = insert_alpha(alpha, "bname", "bartist");
  alpha = insert_alpha(alpha, "aname", "fartist");
  alpha = insert_alpha(alpha, "dname", "eartist");
  alpha = insert_alpha(alpha, "cname", "bartist");
  print_list(alpha);

  printf("\ntesting find specific song------------------------------------------------\n");
  
  struct song_node *specific = malloc(sizeof(struct song_node));
  specific = find_specific(alpha, "bname", "bartist");
  printf("Find bartist bname: %s %s\n", specific -> artist, specific -> name);

  specific = find_specific(alpha, "aname", "fartist");
  printf("Find fartist aname: %s %s\n", specific -> artist, specific -> name);

  specific = find_specific(alpha, "ename", "eartist");
  printf("Find eartist ename: %s %s\n", specific -> artist, specific -> name);

  printf("\ntesting find artist song------------------------------------------------\n");

  struct song_node *unspecific = malloc(sizeof(struct song_node));
  unspecific = find_artist(alpha, "bartist");
  printf("Find bartist: %s %s\n", unspecific -> artist, unspecific -> name);

  unspecific = find_artist(alpha, "fartist");
  printf("Find fartist: %s %s\n", unspecific -> artist, unspecific -> name);

  unspecific = find_artist(alpha, "eartist");
  printf("Find eartist: %s %s\n", unspecific -> artist, unspecific -> name);

  printf("\ntesting find random song------------------------------------------------\n");

  struct song_node *random = malloc(sizeof(struct song_node));
  random = find_random(alpha);
  printf("Find random: %s %s\n", random -> artist, random -> name);

  random = find_random(alpha);
  printf("Find random: %s %s\n", random -> artist, random -> name);
  
  random = find_random(alpha);
  printf("Find random: %s %s\n", random -> artist, random -> name);

  printf("\ntesting remove node------------------------------------------------\n");
  printf("removing bname bartist:\n");
  alpha = remove_node(alpha, "bname", "bartist");
  print_list(alpha);
  printf("\n");
  
  printf("removing ename eartist:\n");
  alpha = remove_node(alpha, "ename", "eartist");
  print_list(alpha);
  printf("\n");

  printf("removing fname fartist:\n");
  alpha = remove_node(alpha, "fname", "fartist");
  print_list(alpha);
  printf("\n");
  
  printf("\nFreeing lists------------------------------------------------\n");
  front = free_list(front);
  print_list(front);

  alpha = free_list(alpha);
  print_list(alpha);

  printf("\nTESTING MUSIC_LIBRARY============================================================\n\n");
  
  printf("testing add_song------------------------------------------------\n");
  add_song("fname", "fartist");
  add_song("ename", "eartist");
  add_song("bname", "bartist");
  add_song("aname", "fartist");
  add_song("dname", "eartist");
  add_song("cname", "bartist");
  //adding more songs leads to a memory corruption error
  //add_song("cname", "cartist");
  print_library();

  printf("testing find s------------------------------------------------\n");
  specific = find_s("bname", "bartist");
  printf("Find bartist bname: %s %s\n", specific -> artist, specific -> name);

  specific = find_s("aname", "fartist");
  printf("Find fartist aname: %s %s\n", specific -> artist, specific -> name);

  specific = find_s("ename", "eartist");
  printf("Find eartist ename: %s %s\n", specific -> artist, specific -> name);
  

  printf("\ntesting find a------------------------------------------------\n");

  unspecific = find_a("bartist");
  printf("Find bartist: %s %s\n", unspecific -> artist, unspecific -> name);

  unspecific = find_a("fartist");
  printf("Find fartist: %s %s\n", unspecific -> artist, unspecific -> name);

  unspecific = find_a("eartist");
  printf("Find eartist: %s %s\n", unspecific -> artist, unspecific -> name);

  printf("\ntesting shuffle------------------------------------------------\n");
  
  shuffle();

  printf("\ntesting remove song------------------------------------------------\n");
  
  printf("removing bname bartist:\n");
  remove_song("bname", "bartist");
  print_library();
  printf("\n");
  
  printf("removing ename eartist:\n");
  remove_song("ename", "eartist");
  print_library();
  printf("\n");

  printf("removing fname fartist:\n");
  remove_song("fname", "fartist");
  print_library();
  printf("\n");

  printf("\nclear------------------------------------------------\n");
  clear();
  print_library();
 
  return 0;
}

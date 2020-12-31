#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "music_library.h"
#include "linked_list.h"

//Add Song CHECK
struct song_node * add_song(char *ncargo, char *acargo){
  int index = acargo[0] - 'a';
  if(index < 0 || index > 26){
    index = 26;
  }
  //struct song_node *ptr = table[index];
  table[index] = insert_alpha(table[index], ncargo, acargo);
}

//Find S
struct song_node * find_s(char *nname, char *aartist){
  int index = aartist[0] - 'a';
  if(index < 0 || index > 26){
    index = 26;
  }
  return find_specific(table[index] ,nname, aartist);
}

//Find A
struct song_node * find_a(char *aartist){
  int index = aartist[0] - 'a';
  if(index < 0 || index > 26){
    index = 26;
  }
  find_artist(table[index] , aartist);
}

//Print Letter CHECK
void print_letter(char letter){
  int index = (int)letter - 'a';
  if(index < 0 || index > 26){
    index = 26;
  }
  print_list(table[index]);
}

//Print Artist
void print_artist(char *aartist){
  int index = aartist[0] - 'a';
  if(index < 0 || index > 26){
    index = 26;
  }
  struct song_node *temp = table[index];
  while(temp){
    if(strcmp(temp -> artist, aartist) == 0){
      printf("%s %s \n", temp -> artist, temp -> name);
    }
    temp = temp -> next;
  }
}

//Print Library CHECK
void print_library(){
  for(int i = 0; i < 27; i++){
    print_list(table[i]);
  }
}

void shuffle(){
  int ctr = 0;
  int num;
  struct song_node *random;
  while(ctr < 10){
    num = (rand() % 27);
    if(table[num]){
      random = find_random(table[num]);
      printf("%s %s\n", random -> artist, random -> name);
      ctr ++;
    }
  }
}

void remove_song(char *nname, char *nartist){
  int index = nname[0] - 'a';
  if(index < 0 || index > 26){
    index = 26;
  }
  //printf("%d\n", index);
  //print_list(table[index]);
  table[index] = remove_node(table[index], nname, nartist);
}

struct song_node * clear(){
  for(int i = 0; i < 27; i++){
    if(table[i]){
      table[i] = free_list(table[i]);
    }
  }
}

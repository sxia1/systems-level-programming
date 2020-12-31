#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

//INSERT FRONT
struct song_node * insert_front(struct song_node *head, char *ncargo, char *acargo);

//INSERT ALPHA
struct song_node *insert_alpha(struct song_node *head, char *ncargo, char *acargo);

//PRINT LIST
void *print_list(struct song_node *head);

//FIND SPECIFIC
struct song_node *find_specific(struct song_node *head, char* nname, char * nartist);

//FIND ARTIST
struct song_node *find_artist(struct song_node *head, char * nartist);

//LENGTH
int length(struct song_node *head);

//FIND RANDOM
struct song_node *find_random(struct song_node *head);

//REMOVE NODE
struct song_node *remove_node(struct song_node *head, char* nname, char* nartist);

//FREE LIST
struct song_node *free_list(struct song_node *head);

#endif

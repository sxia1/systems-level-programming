struct song_node * table[27];

struct song_node * add_song(char *ncargo, char *acargo);


struct song_node * find_s(char *nname, char *aartist);

struct song_node * find_a(char *aartist);

void print_letter(char letter);

void print_artist(char *aartist);

void print_library();

void shuffle();

void remove_song(char *nname, char *nartist);

struct song_node * clear();

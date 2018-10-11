struct node{ int cargo; struct node *next; };
void print_list(struct node * head);
struct node * insert_front(struct node * head, int i);
struct node * free_list(struct node *head);

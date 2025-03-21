#ifndef LIST_PAGE_H
#define LIST_PAGE_H

typedef struct {
  int index;
  char data[60];
} page;

typedef struct Node {
  struct Node *next;
  struct Node *prev;
  page *data;
} list_page;

//----------------LIST------------------

void list_init(list_page **root, page *hash);
void insert_list(list_page **root, page *hash);
void swap_list(list_page **root, list_page *p_list);
void delete_list(list_page **root, list_page *hash);
void clear_list(list_page **root);
void print_list(list_page *root, int count);
void move_node(list_page **root, list_page *p_list);

#endif
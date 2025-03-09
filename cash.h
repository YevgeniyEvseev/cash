#ifndef CASH_H
#define CASH_H

#define HASH_SIZE_BIT 25
#define POLINOM 23
#define SIZE_INT 32
#define K1_HASH 23111
#define K2_HASH 123453

typedef struct {
  int index;
  char data[60];
} page;

typedef struct {
  int k1;
  int k2;
  int size_in_bit;
} param_hash;

typedef struct Node {
  struct Node *next;
  struct Node *prev;
  page *data;
} cash_page;

typedef struct node {
  param_hash *param;
  struct node *next;
  cash_page *value;
} hash_list;

// void slow_get_page(int n, page *p);
void get_page(int id, page **p, hash_list *hash);

//----------------HASH----------------

// search page by id. return
void insert_hash(hash_list *hash, cash_page *p);
void hash_init(hash_list **hash, param_hash *value);
void set_param(param_hash *value, unsigned k1, unsigned k2, unsigned length);
hash_list *search_hash(hash_list *hash, int id_page);
int hash_str(char *str, const param_hash *value);
unsigned hash_int(int n, const param_hash *value);
void delete_hash(hash_list *hash, int id);
void clear_hash(hash_list **hash);

//----------------LIST------------------

void create_cash(cash_page **root, page *hash);
void insert_list(cash_page **root, page *hash);
void move_list(cash_page *p_list1, cash_page *p_list2);
void drop_list(cash_page *root, page *hash);

#endif

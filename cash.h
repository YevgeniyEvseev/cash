#ifndef CASH_H
#define CASH_H

#define FALSE 0
#define TRUE 1
#define HASH_SIZE_BIT 8
#define POLINOM 23
#define SIZE_INT 32
#define K1_HASH 167657
#define K2_HASH 16777216

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

typedef struct {
  hash_list *list;
  cash_page *root;
} Cash_t;

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

void list_init(cash_page **root, page *hash);
void insert_list(cash_page **root, page *hash);
void swap_list(cash_page **root, cash_page *p_list);
void delete_list(cash_page **root, cash_page *hash);
void clear_list(cash_page **root);
void print_list(cash_page *root, int count);
void move_node(cash_page **root, cash_page *p_list);

//---------------CASH-------------------

void manager_cash(Cash_t *cash, page *key);
void cash_cstr_param(Cash_t *cash, page *p, unsigned k1, unsigned k2,
                     unsigned size);
void cash_cstr(Cash_t *cash, page *p);
void create_cash(Cash_t **cash);
void clear_cash(Cash_t **cash);

#endif

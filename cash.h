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

typedef struct cash_page {
  struct cash_page *next;
  struct cash_page *prev;
  page data;
} cash_page;

typedef struct {
  int k1;
  int k2;
  int size_in_bit;
} param_hash;

typedef struct node {
  struct node *next;
  page *value;
} hash_list;

void slow_get_page(int n, page *p);
void get_page(int id, page *p);

// search page by id. return
void insert_hash(hash_list *hash, const param_hash *value, page *p);
void hash_init(hash_list **hash, const param_hash *value);
void set_param(param_hash *value, unsigned k1, unsigned k2, unsigned length);
int search_hash(hash_list *hash, const param_hash *value, page *p);
int hash_str(char *str, const param_hash *value);
unsigned hash_int(int n, const param_hash *value);
// void delete_hash(page **hash, page *p);
#endif
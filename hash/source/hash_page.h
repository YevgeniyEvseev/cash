#ifndef HASH_PAGE_H
#define HASH_PAGE_H

#include "../../list/source/list_page.h"

struct param_hash;

typedef struct node {
  struct param_hash *param;
  struct node *next;
  list_page *value;
} hash_table;

void insert_hash(hash_table *hash, list_page *p);
void hash_init_def(hash_table **hash);
void hash_init(hash_table **hash, unsigned k1, unsigned k2, unsigned length);
void set_param(struct param_hash *value, unsigned k1, unsigned k2,
               unsigned length);
hash_table *search_hash(hash_table *hash, int id_page);
int hash_str(char *str, const struct param_hash *value);
unsigned hash_int(int n, const struct param_hash *value);
void delete_hash(hash_table *hash, int id);
void clear_hash(hash_table **hash);
void get_page(int id, page **p, hash_table *hash);
int get_size(hash_table *hash);

#endif
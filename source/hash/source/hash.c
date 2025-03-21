#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../define.h"
#include "hash_page.h"

struct param_hash {
  int k1;
  int k2;
  int size_in_bit;
} param;

void hash_init_def(hash_table **hash) {
  int lenght = 1 << HASH_SIZE_BIT;
  *hash = calloc(lenght, sizeof(hash_table));
  (*hash)->param = malloc(sizeof(param));
  (*hash)->param->size_in_bit = HASH_SIZE_BIT;
  (*hash)->param->k1 = K1_HASH;
  (*hash)->param->k2 = K2_HASH;
}

void hash_init(hash_table **hash, unsigned k1, unsigned k2, unsigned len) {
  int lenght = 1 << len;
  *hash = calloc(lenght, sizeof(hash_table));
  (*hash)->param = malloc(sizeof(param));
  (*hash)->param->size_in_bit = len;
  (*hash)->param->k1 = k1;
  (*hash)->param->k2 = k2;
}

void ctor_hash_table(hash_table *hash) {
  int lenght = 1 << hash->param->size_in_bit;
  for (int i = 0; i < lenght; ++i) {
    (hash + i)->value = NULL;
    (hash + i)->next = NULL;
  }
}

void insert_hash(hash_table *hash, list_page *p) {
  hash_table *tmp = search_hash(hash, p->data->index);
  if (tmp != NULL) return;
  int i = hash_int(p->data->index, hash->param);

  if (hash[i].value == NULL) {
    hash[i].value = p;
    hash[i].next = NULL;
    return;
  }
  tmp = hash + i;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  hash_table *node = malloc(sizeof(hash_table));
  node->value = p;
  node->next = NULL;
  tmp->next = node;
}
hash_table *search_hash(hash_table *hash, int id_page) {
  int i = hash_int(id_page, hash->param);
  hash_table *tmp = hash + i;
  if (tmp->value == NULL) return NULL;
  while (tmp->value->data->index != id_page) {
    if (tmp->next == NULL) return NULL;
    tmp = tmp->next;
  }
  return tmp;
}

void set_param(struct param_hash *value, unsigned k1, unsigned k2,
               unsigned length) {
  if (length > 24) length = 24;  // length default
  value->k1 = k1;
  value->k2 = k2;
  value->size_in_bit = length;
}
unsigned hash_int(int n, const struct param_hash *value) {
  return (value->k1 * (unsigned)n + value->k2) >> (32 - value->size_in_bit);
}

int hash_str(char *str, const struct param_hash *value) {
  int l_str = strlen(str);
  int sum_hash = 0;
  int pow_i = POLINOM;
  for (int i = 0; i < l_str; ++i) {
    if (pow_i == 0) pow_i = POLINOM;
    sum_hash = sum_hash + ((*(str + i) - 'a' + 1) << pow_i);
    pow_i--;
    // printf("%d\n", sum_hash);
  }
  return (sum_hash * value->k1 + value->k2) >> (32 - value->size_in_bit);
}

// void slow_get_page(int n, page *p) {}

void get_page(int id, page **p, hash_table *hash) {
  hash_table *p_list = search_hash(hash, id);
  if (p_list == NULL) {
    *p = NULL;
    return;
  }
  *p = p_list->value->data;
}

void delete_hash(hash_table *hash, int id) {
  int i_root = hash_int(id, hash->param);
  if (hash[i_root].value == NULL) return;
  hash_table *p_list = search_hash(hash, id);
  if (hash[i_root].next == NULL) {
    hash[i_root].value = NULL;
    return;
  }
  hash_table *tmp = p_list;
  hash_table *prev;
  while (tmp->next != NULL) {
    prev = tmp;
    tmp = tmp->next;
  }
  p_list->value = tmp->value;
  free(tmp);
  prev->next = NULL;
}
void clear_hash(hash_table **hash) {
  int lenght = 1 << (*hash)->param->size_in_bit;
  for (int i = 0; i < lenght; ++i) {
    if ((*hash + i)->next == NULL) continue;

    hash_table *tmp = (*hash + i)->next;
    hash_table *prev;
    do {
      prev = tmp;
      tmp = tmp->next;
      free(prev);
    } while (tmp != NULL);
  }
  free((*hash)->param);
  free(*hash);
}

int get_size(hash_table *hash) { return 1 << hash->param->size_in_bit; }

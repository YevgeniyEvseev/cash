#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cash.h"

void hash_init(hash_list **hash, const param_hash *value) {
  int lenght = 1 << value->size_in_bit;
  *hash = calloc(lenght, sizeof(hash_list *));
}

void insert_hash(hash_list *hash, const param_hash *value, page *p) {
  int i = search_hash(hash, value, p);
  if (i == -1) i = hash_int(p->index, value);

  if ((hash + i)->value == NULL) {
    (hash + i)->value = p;
    (hash + i)->next = NULL;
    return;
  }
  hash_list *tmp = hash + i;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  hash_list *node = malloc(sizeof(hash_list));
  node->value = p;
  node->next = NULL;
  tmp->next = node;
}
int search_hash(hash_list *hash, const param_hash *value, page *p) {
  int i = hash_int(p->index, value);
  hash_list *tmp = hash + i;
  if (tmp->value == NULL) return -1;
  while (tmp->value->index != p->index) {
    if (tmp->next == NULL) return -1;
    tmp = tmp->next;
  }

  return i;
}

void set_param(param_hash *value, unsigned k1, unsigned k2, unsigned length) {
  if (length > 24) length = 24;  // length default
  value->k1 = k1;
  value->k2 = k2;
  value->size_in_bit = length;
}
unsigned hash_int(int n, const param_hash *value) {
  return (value->k1 * (unsigned)n + value->k2) >> (32 - value->size_in_bit);
}

int hash_str(char *str, const param_hash *value) {
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

void slow_get_page(int n, page *p){
  
}
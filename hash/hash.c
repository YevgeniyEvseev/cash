#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cash.h"

void hash_init(hash_list **hash, param_hash *value) {
  int lenght = 1 << value->size_in_bit;
  *hash = calloc(lenght, sizeof(hash_list));
  (*hash)->param = value;
  for (int i = 0; i < lenght; ++i) {
    (*hash + i)->value = NULL;
    (*hash + i)->next = NULL;
  }
}

void insert_hash(hash_list *hash, cash_page *p) {
  hash_list *tmp = search_hash(hash, p->data->index);
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
  hash_list *node = malloc(sizeof(hash_list));
  node->value = p;
  node->next = NULL;
  tmp->next = node;
}
hash_list *search_hash(hash_list *hash, int id_page) {
  int i = hash_int(id_page, hash->param);
  hash_list *tmp = hash + i;
  if (tmp->value == NULL) return NULL;
  while (tmp->value->data->index != id_page) {
    if (tmp->next == NULL) return NULL;
    tmp = tmp->next;
  }
  return tmp;
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

// void slow_get_page(int n, page *p) {}

void get_page(int id, page **p, hash_list *hash) {
  hash_list *p_list = search_hash(hash, id);
  if (p_list == NULL) {
    *p = NULL;
    return;
  }
  *p = p_list->value->data;
}

void delete_hash(hash_list *hash, int id) {
  int i_root = hash_int(id, hash->param);
  if (hash[i_root].value == NULL) return;
  hash_list *p_list = search_hash(hash, id);
  if (hash[i_root].next == NULL) {
    hash[i_root].value = NULL;
    return;
  }
  hash_list *tmp = p_list;
  hash_list *prev;
  while (tmp->next != NULL) {
    prev = tmp;
    tmp = tmp->next;
  }
  p_list->value = tmp->value;
  free(tmp);
  prev->next = NULL;
}
void clear_hash(hash_list **hash) {
  int lenght = 1 << (*hash)->param->size_in_bit;
  for (int i = 0; i < lenght; ++i) {
    if ((*hash + i)->next == NULL) continue;

    hash_list *tmp = (*hash + i)->next;
    hash_list *prev;
    do {
      prev = tmp;
      tmp = tmp->next;
      free(prev);
    } while (tmp != NULL);
  }
  free((*hash)->param);
  free(*hash);
}

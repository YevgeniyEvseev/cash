#include "cash.h"

#include <stdio.h>
#include <stdlib.h>

#include "define.h"

void create_cash(Cash_t **cash) {
  *cash = malloc(sizeof(Cash_t));
  (*cash)->list = NULL;
  (*cash)->root = NULL;
}

void cash_cstr(Cash_t *cash, page *p) {
  hash_init_def(&(cash->list));
  list_init(&(cash->root), p);
  insert_hash(cash->list, cash->root);
}

void cash_cstr_param(Cash_t *cash, page *p, unsigned k1, unsigned k2,
                     unsigned size) {
  hash_init(&(cash->list), k1, k2, size);
  list_init(&(cash->root), p);
  insert_hash(cash->list, cash->root);
}

void manager_cash(Cash_t *cash, page *key) {
  static int n = 1;
  int length = get_size(cash->list);
  hash_table *found_node = search_hash(cash->list, key->index);
  if (found_node == NULL) {
    insert_list(&cash->root, key);
    insert_hash(cash->list, cash->root);
  } else {
    move_node(&cash->root, found_node->value);
  }
  if (n > length && found_node == NULL) {
    list_page *last_node = cash->root;
    while (last_node->next != NULL) {
      last_node = last_node->next;
    }
    delete_hash(cash->list, last_node->data->index);
    delete_list(&cash->root, last_node);
  } else {
    n++;
  }
}

void clear_cash(Cash_t **cash) {
  clear_hash(&(*cash)->list);
  clear_list(&(*cash)->root);
  free(*cash);
}
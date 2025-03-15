#include "cash.h"

#include <stdio.h>
#include <stdlib.h>

void create_cash(Cash_t **cash) {
  *cash = malloc(sizeof(Cash_t));
  (*cash)->list = NULL;
  (*cash)->root = NULL;
}

void cash_cstr(Cash_t *cash, page *p) {
  param_hash *param = malloc(sizeof(param_hash));
  set_param(param, K1_HASH, K2_HASH, HASH_SIZE_BIT);
  hash_init(&(cash->list), param);
  list_init(&(cash->root), p);
  insert_hash(cash->list, cash->root);
}

void cash_cstr_param(Cash_t *cash, page *p, unsigned k1, unsigned k2,
                     unsigned size) {
  param_hash *param = malloc(sizeof(param_hash));
  set_param(param, k1, k2, size);
  hash_init(&(cash->list), param);
  list_init(&(cash->root), p);
  insert_hash(cash->list, cash->root);
}

void manager_cash(Cash_t *cash, page *key) {
  static int n = 1;
  int length = 1 << cash->list->param->size_in_bit;
  hash_list *found_node = search_hash(cash->list, key->index);
  cash_page *tmp = found_node->value;
  if (found_node == NULL) {
    insert_list(&cash->root, key);
    insert_hash(cash->list, cash->root);
  } else {
    swap_list(cash->root, found_node);
  }
  if (n > length && found_node == NULL) {
    delete_hash(cash->list, key->index);
    delete_list(&cash->root, tmp);
  } else {
    n++;
  }
}
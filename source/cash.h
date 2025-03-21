#ifndef CASH_H
#define CASH_H

#include "./hash/source/hash_page.h"
#include "./list/source/list_page.h"

typedef struct {
  hash_table *list;
  list_page *root;
} Cash_t;

// void slow_get_page(int n, page *p);

//----------------HASH----------------

// search page by id. return

//---------------CASH-------------------

void manager_cash(Cash_t *cash, page *key);
void cash_cstr_param(Cash_t *cash, page *p, unsigned k1, unsigned k2,
                     unsigned size);
void cash_cstr(Cash_t *cash, page *p);
void create_cash(Cash_t **cash);
void clear_cash(Cash_t **cash);

#endif

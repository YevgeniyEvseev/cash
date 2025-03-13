#include "cash.h"

#include <stdio.h>
#include <stdlib.h>

void create_cash(Cash_t **cash) {
  *cash = malloc(sizeof(Cash_t));
  (*cash)->list = NULL;
  (*cash)->root = NULL;
}

void cash_cstr(Cash_t *cash, page *p) {}

void cash_cstr_param(Cash_t *cash, page *p, unsigned k1, unsigned k2,
                     unsigned size) {}

void manager_cash(hash_list **hash, cash_page **list, page *key) {}
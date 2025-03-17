#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cash.h"

int main() {
  page p[300] = {0};
  Cash_t *cash = NULL;
  create_cash(&cash);

  for (int i = 0; i < 300; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  cash_cstr(cash, p);
  for (int i = 0; i < 300; ++i) {
    manager_cash(cash, p + i);
  }
  manager_cash(cash, p + 297);
  manager_cash(cash, p + 295);
  page *p_find;
  get_page(299, &p_find, cash->list);
  print_list(cash->root, 10);
  clear_cash(&cash);
}
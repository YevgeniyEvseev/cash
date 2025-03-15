#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cash.h"

int main() {
  page p[10000] = {0};
  Cash_t *cash = NULL;
  create_cash(&cash);

  for (int i = 0; i < 10000; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  cash_cstr(cash, p);
  for (int i = 0; i < 10000; ++i) {
    manager_cash(cash, p + i);
  }
}
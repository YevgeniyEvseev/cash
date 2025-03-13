#include <stdio.h>
#include <string.h>

#include "../cash.h"

int main() {
  page p[5] = {0};
  cash_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  cash_page *node = root->next;

  delete_list(&root, node);
  clear_list(&root);
}
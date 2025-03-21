#include <stdio.h>
#include <string.h>

#include "../../define.h"
#include "list_page.h"

int main() {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  list_page *node = root->next->next->next;
  print_list(root, 5);
  swap_list(&root, node);
  print_list(root, 5);
  // delete_list(&root, node);
  clear_list(&root);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cash.h"

int main() {
  page p[10000] = {0};
  for (int i = 0; i < 10000; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  hash_list *hash = NULL;
  param_hash value;
  cash_page *cash = NULL;
  set_param(&value, 167657, 16777216, 8);
  hash_init(&hash, &value);
  list_init(&cash, p);

  for (int i = 0; i < 10000; i++) {
    insert_list(&cash, &p[i]);
    insert_hash(hash, cash);
  }
  hash_list *c = search_hash(hash, 9999);
  page *p_find;
  get_page(5555, &p_find, hash);
  printf("collition =%d  insdex=%d\n", hash_int(9999, &value),
         (p_find == NULL) ? -1 : p_find->index);
  delete_hash(hash, 5555);
  get_page(5555, &p_find, hash);
  printf("collition =%d  insdex=%d\n", hash_int(9999, &value),
         (p_find == NULL) ? -1 : p_find->index);
  clear_hash(&hash);
#if 0
  for (int i = 0; i < 10000000; i++) {
    i *= 2;
    printf("collition %d = %d\n", i, hash_int(i, 23111, 123453));
  }
#endif
}

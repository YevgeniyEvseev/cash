#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_page.h"

int main() {
  page p[1000] = {0};
  for (int i = 0; i < 1000; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  hash_table *hash = NULL;
  list_page *cash = NULL;
  hash_init_def(&hash);
  list_init(&cash, p);

  for (int i = 0; i < 1000; i++) {
    insert_list(&cash, &p[i]);
    insert_hash(hash, cash);
  }
  page *p_find;
  get_page(555, &p_find, hash);
  printf("insdex=%d\n", (p_find == NULL) ? -1 : p_find->index);
  delete_hash(hash, 555);
  get_page(555, &p_find, hash);
  printf("insdex=%d\n", (p_find == NULL) ? -1 : p_find->index);
  clear_hash(&hash);
#if 0
  for (int i = 0; i < 10000000; i++) {
    i *= 2;
    printf("collition %d = %d\n", i, hash_int(i, 23111, 123453));
  }
#endif
}

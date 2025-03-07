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
  set_param(&value, 117657, 16777216, 8);
  hash_init(&hash, &value);

  for (int i = 0; i < 10000; i++) {
    insert_hash(hash, &value, &p[i]);
  }
  int c = search_hash(hash, &value, &p[6511]);
  printf("collition =%d", c);
#if 0
  for (int i = 0; i < 10000000; i++) {
    i *= 2;
    printf("collition %d = %d\n", i, hash_int(i, 23111, 123453));
  }
#endif
}

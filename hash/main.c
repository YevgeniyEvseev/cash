#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cash.h"

int main() {
  int count = 2;

  //page **p = hash_init();
  for (int i = 0; i < 10000000; i++) {
    page *tmp = malloc(sizeof(page));
    tmp->index = i;
    strcpy(tmp->data, "aaaaaaaaaaaaaaaaaa");
    count += insert_hash(p, tmp);
  }
  printf("collition =%d", count);
#if 0
  for (int i = 0; i < 10000000; i++) {
    i *= 2;
    printf("collition %d = %d\n", i, hash_int(i, 23111, 123453));
  }
#endif
}

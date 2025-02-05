#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cash.h"

int main() {
  int count = 0;
  page **p = hash_init();
  for (int i = 0; i < 100000000; i++) {
    page *tmp = malloc(sizeof(page));
    tmp->index = i;
    strcpy(tmp->data, "aaaaaaaaaaaaaaaaaa");
    count += insert_hash(p, tmp);
  }
  printf("collition =%d", count);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../cash.h"

page **hash_init() {
  int lenght = 1 << HASH_SIZE_BIT;
  return malloc(lenght * sizeof(page *));
}

int hash_str(char *str, unsigned a, unsigned b) {
  int l_str = strlen(str);
  int sum_hash = 0;
  int pow_i = POLINOM;
  for (int i = 0; i < l_str; ++i) {
    if (pow_i == 0) pow_i = POLINOM;
    sum_hash = sum_hash + ((*(str + i) - 'a' + 1) << pow_i);
    pow_i--;
    // printf("%d\n", sum_hash);
  }
  return (sum_hash * a + b) >> (32 - HASH_SIZE_BIT);
}

int insert_hash(page **hash, page *p) {
  if (search_hash(hash, p)) {
    // fprintf(stderr, "collition");
    
    return 1;
  }
  return 0;
}

int search_hash(page **hash, page *p) {
  int id = hash_int(p->index, K1_HASH, K2_HASH);
  if (hash[id] != NULL) {
    return id;
  }
  hash[id] = p;
  return 0;
}

void drop_hash(page **hash, page *p) {
  int id = hash_int(p->index, K1_HASH, K2_HASH);
  if (hash[id] == NULL) {
    printf("hash id is empty");
    abort();
  }
  hash[id] = NULL;
}

int hash_int(int n, unsigned a, unsigned b) {
  return (a * n + b) >> (32 - HASH_SIZE_BIT);
}
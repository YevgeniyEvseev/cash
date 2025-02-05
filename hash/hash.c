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

// int insert_hash(int **hash, int id, page *p) {

//}

int search_hash(page **hash, page *p) {
  int id_new = hash_int(p->index, 231, 1210432);
  if (hash[id_new] != NULL) {
    return 1;
  }
  hash[id_new] = p;
}

int hash_int(int n, unsigned a, unsigned b) {
  return (a * n + b) >> (32 - HASH_SIZE_BIT);
}
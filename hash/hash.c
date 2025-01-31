#include <stdio.h>
#include <string.h>

#include "../cash.h"

int hash_str(char *str, unsigned a, unsigned b) {
  int l_str = strlen(str);
  int sum_hash = 0;
  int pow_i = POLINOM;
  for (int i = 0; i < l_str; ++i) {
    if (pow_i == 0) pow_i = POLINOM;
    sum_hash = sum_hash + ((*(str + i) - 'a' + 1) << pow_i);
    pow_i--;
    printf("%d\n", sum_hash);
  }
  return (sum_hash * a + b) >> (32 - HASH_POWER);
}
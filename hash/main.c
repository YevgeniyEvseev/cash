#include <stdio.h>

#include "../cash.h"

int main() {
  char *tmp = "abcdefgh";
  int cash1 = hash_str(tmp, 29, 31);
  int cash2 = hash_str(tmp, 29, 31);
  printf("%d %d", cash1, cash2);
}
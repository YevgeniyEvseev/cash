#ifndef CASH_H
#define CASH_H

#define HASH_SIZE_BIT 20
#define POLINOM 23
#define SIZE_INT 32

struct page {
  int index;
  char data[60];
};

void slow_get_page(int n, struct page *p);
void get_page(int id, struct page *p);

int insert_hash(char *str);
int search_hash(char *str);
int hash_str(char *str, unsigned a, unsigned b);

#endif
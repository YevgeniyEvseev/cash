#ifndef CASH_H
#define CASH_H

#define HASH_SIZE_BIT 20
#define POLINOM 23
#define SIZE_INT 32

typedef struct {
  int index;
  char data[60];
} page;

typedef struct {
  cash_page *next;
  cash_page *prev;
  page data;
} cash_page;

void slow_get_page(int n, page *p);
void get_page(int id, page *p);

// search page by id. return
int insert_hash(int **hash, page *p);
int search_hash(page **hash, page *p);
int hash_str(char *str, unsigned a, unsigned b);
int hash_int(int n, unsigned a, unsigned b);

#endif
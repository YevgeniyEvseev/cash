#ifndef CASH_H
#define CASH_H

#define HASH_SIZE_BIT 20
#define POLINOM 23
#define SIZE_INT 32

int insert_hash(char *str);
int search_hash(char *str);
int hash_str(char *str, unsigned a, unsigned b);

#endif
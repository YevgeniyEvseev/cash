#include <stdio.h>
#include <stdlib.h>

#include "../cash.h"

void create_cash(cash_page **root, page *p) {
  *root = malloc(sizeof(cash_page));
  (*root)->data = p;
  (*root)->next = NULL;
  (*root)->prev = NULL;
}

void insert_list(cash_page **root, page *p) {
  if (root == NULL) {
    create_cash(root, p);
    return;
  }
  while ((*root)->prev != NULL) {
    *root = (*root)->prev;
  }
  cash_page *tmp = malloc(sizeof(cash_page));
  tmp->data = p;
  tmp->prev = NULL;
  tmp->next = *root;
  (*root)->prev = tmp;
  *root = tmp;
}
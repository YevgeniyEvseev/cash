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
  if (*root == NULL) {
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

void swap_list(cash_page **root, cash_page *p_list) {
  if (p_list == *root) return;

  cash_page *tmp = *root;
  *root = p_list;
  (*root)->data = p_list->data;
  (*root)->next->prev = p_list;
  (*root)->next = p_list->next;
  (*root)->prev = p_list->prev;

  if (p_list->next != NULL) p_list->next->prev = tmp;
  p_list->data = tmp->data;
  p_list->prev->next = tmp;
  p_list->next = tmp->next;
  p_list->prev = tmp->prev;
}
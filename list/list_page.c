#include <stdio.h>
#include <stdlib.h>

#include "../cash.h"

void list_init(cash_page **root, page *p) {
  if (*root != NULL) {
    fprintf(stderr, "constructor Alarm!!! cash list is not NULL");
    return;
  }
  *root = malloc(sizeof(cash_page));
  (*root)->data = p;
  (*root)->next = NULL;
  (*root)->prev = NULL;
}

void insert_list(cash_page **root, page *p) {
  if (*root == NULL) {
    list_init(root, p);
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
  cash_page *next_l = p_list->next;
  cash_page *prev_l = p_list->prev;
  *root = p_list;
  tmp->next->prev = p_list;
  (*root)->next = tmp->next;
  (*root)->prev = tmp->prev;

  if (next_l != NULL) next_l->prev = tmp;
  prev_l->next = tmp;
  tmp->next = next_l;
  tmp->prev = prev_l;
}

void delete_list(cash_page **root, cash_page *list) {
  if (list->next == NULL && list->prev == NULL) {
    free(list);
    *root = NULL;
    return;
  }
  if (list->next != NULL) list->next->prev = list->prev;
  if (list->prev != NULL)
    list->prev->next = list->next;
  else
    *root = list->next;
  free(list);
}

void clear_list(cash_page **root) {
  while ((*root) != NULL) {
    delete_list(root, *root);
  }
}
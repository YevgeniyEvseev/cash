#include "list_page.h"

#include <stdio.h>
#include <stdlib.h>



void list_init(list_page **root, page *p) {
  if (*root != NULL) {
    fprintf(stderr, "constructor Alarm!!! cash list is not NULL");
    return;
  }
  *root = malloc(sizeof(list_page));
  (*root)->data = p;
  (*root)->next = NULL;
  (*root)->prev = NULL;
}

void insert_list(list_page **root, page *p) {
  if (*root == NULL) {
    list_init(root, p);
    return;
  }
  while ((*root)->prev != NULL) {
    *root = (*root)->prev;
  }
  list_page *tmp = malloc(sizeof(list_page));
  tmp->data = p;
  tmp->prev = NULL;
  tmp->next = *root;
  (*root)->prev = tmp;
  *root = tmp;
}

void swap_list(list_page **root, list_page *p_list) {
  if (p_list == *root) return;

  list_page *tmp = *root;
  list_page *next_l = p_list->next;
  list_page *prev_l = p_list->prev;
  *root = p_list;
  tmp->next->prev = p_list;
  (*root)->next = tmp->next;
  (*root)->prev = tmp->prev;

  if (next_l != NULL) next_l->prev = tmp;
  prev_l->next = tmp;
  tmp->next = next_l;
  tmp->prev = prev_l;
}

void delete_list(list_page **root, list_page *list) {
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

void clear_list(list_page **root) {
  while ((*root) != NULL) {
    delete_list(root, *root);
  }
}

void print_list(list_page *root, int count) {
  list_page *tmp = root;
  int i = 0;
  while (tmp != NULL && i++ < count) {
    printf("%d ", tmp->data->index);
    tmp = tmp->next;
  }
  printf("\n");
}

void move_node(list_page **root, list_page *p_list) {
  if (p_list == *root) return;
  if (p_list->next != NULL) p_list->next->prev = p_list->prev;
  p_list->prev->next = p_list->next;
  (*root)->prev = p_list;
  p_list->next = (*root);
  p_list->prev = NULL;
  *root = p_list;
}

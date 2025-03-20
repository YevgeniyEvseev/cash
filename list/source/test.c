#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list_page.h"

START_TEST(INSERT_LIST) {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  ck_assert_int_eq(5, root->data->index);
  for (int i = 4; i > 0; --i) {
    root = root->next;
    ck_assert_int_eq(i, root->data->index);
  }
  for (int i = 2; i < 6; ++i) {
    root = root->prev;
    ck_assert_int_eq(i, root->data->index);
  }
  clear_list(&root);
}
END_TEST

START_TEST(SWAP_LIST) {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  list_page *node = root->next->next;
  swap_list(&root, node);
  ck_assert_int_eq(3, root->data->index);

  root = root->next;
  ck_assert_int_eq(4, root->data->index);
  root = root->next;
  ck_assert_int_eq(5, root->data->index);
  root = root->next;
  ck_assert_int_eq(2, root->data->index);
  root = root->next;
  ck_assert_int_eq(1, root->data->index);

  root = root->prev;
  ck_assert_int_eq(2, root->data->index);
  root = root->prev;
  ck_assert_int_eq(5, root->data->index);
  root = root->prev;
  ck_assert_int_eq(4, root->data->index);
  root = root->prev;
  ck_assert_int_eq(3, root->data->index);
  clear_list(&root);
}
END_TEST

START_TEST(SWAP_LIST2) {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  list_page *node = root;
  while (node->next != NULL) {
    node = node->next;
  }

  swap_list(&root, node);
  ck_assert_int_eq(1, root->data->index);
  clear_list(&root);
}
END_TEST

START_TEST(SWAP_LIST3) {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  list_page *node = root;

  swap_list(&root, node);
  ck_assert_int_eq(5, root->data->index);
  clear_list(&root);
}
END_TEST

START_TEST(delete_LIST) {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  list_page *node = root->next;

  delete_list(&root, node);
  ck_assert_int_eq(3, root->next->data->index);
  ck_assert_int_eq(5, root->next->prev->data->index);
  clear_list(&root);
}
END_TEST

START_TEST(delete_LIST2) {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  list_page *node = root;

  delete_list(&root, node);
  ck_assert_int_eq(3, root->next->data->index);
  ck_assert_int_eq(4, root->next->prev->data->index);
  clear_list(&root);
}
END_TEST

START_TEST(delete_LIST3) {
  page p[5] = {0};
  list_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  list_page *node = root;
  while (node->next != NULL) {
    node = node->next;
  }

  delete_list(&root, node);
  node = root;

  while (node->next != NULL) {
    node = node->next;
  }
  ck_assert_int_eq(2, node->data->index);
  clear_list(&root);
}
END_TEST

Suite *tree_d_suite() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("LIST ");

  /*Core test case*/
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, INSERT_LIST);
  tcase_add_test(tc_core, SWAP_LIST);
  tcase_add_test(tc_core, SWAP_LIST2);
  tcase_add_test(tc_core, SWAP_LIST3);
  tcase_add_test(tc_core, delete_LIST);
  tcase_add_test(tc_core, delete_LIST2);
  tcase_add_test(tc_core, delete_LIST3);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = tree_d_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? 1 : 0;
}
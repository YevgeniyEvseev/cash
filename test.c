#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "cash.h"

START_TEST(CASH_TRUE) {
  page p[300] = {0};
  Cash_t *cash = NULL;
  create_cash(&cash);

  for (int i = 0; i < 300; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  cash_cstr(cash, p);
  for (int i = 0; i < 300; ++i) {
    manager_cash(cash, p + i);
  }
  page *p_find;
  get_page(299, &p_find, cash->list);
  ck_assert_int_eq(299, (p_find == NULL) ? -1 : p_find->index);
}
END_TEST

START_TEST(CASH_TRUE2) {
  page p[300] = {0};
  Cash_t *cash = NULL;
  create_cash(&cash);

  for (int i = 0; i < 300; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  cash_cstr(cash, p);
  for (int i = 0; i < 300; ++i) {
    manager_cash(cash, p + i);
  }
  page *p_find;
  get_page(2, &p_find, cash->list);
  ck_assert_int_eq(-1, (p_find == NULL) ? -1 : p_find->index);
}
END_TEST

START_TEST(CASH_TRUE3) {
  page p[300] = {0};
  Cash_t *cash = NULL;
  create_cash(&cash);

  for (int i = 0; i < 300; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  cash_cstr(cash, p);
  for (int i = 0; i < 300; ++i) {
    manager_cash(cash, p + i);
  }
  manager_cash(cash, p + 297);
  manager_cash(cash, p + 295);
  page *p_find;
  get_page(2, &p_find, cash->list);
  ck_assert_int_eq(-1, (p_find == NULL) ? -1 : p_find->index);
  ck_assert_int_eq(295, cash->root->data->index);
  cash_page *tmp = cash->root->next;
  ck_assert_int_eq(297, tmp->data->index);
  tmp = tmp->next;
  ck_assert_int_eq(299, tmp->data->index);
  tmp = tmp->next;
  ck_assert_int_eq(298, tmp->data->index);
  tmp = tmp->next;
  ck_assert_int_eq(296, tmp->data->index);
  tmp = tmp->next;
  ck_assert_int_eq(294, tmp->data->index);
}
END_TEST

START_TEST(CASH_TRUE4) {
  page p[300] = {0};
  Cash_t *cash = NULL;
  create_cash(&cash);

  for (int i = 0; i < 300; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  cash_cstr(cash, p);
  for (int i = 0; i < 300; ++i) {
    manager_cash(cash, p + i);
  }
  manager_cash(cash, p + 297);
  manager_cash(cash, p + 295);
  cash_page *last = cash->root->next;
  while (last->next != NULL) {
    last = last->next;
  }
  ck_assert_int_eq(44, last->data->index);
}
END_TEST

START_TEST(CASH_TRUE5) {
  page p[300] = {0};
  Cash_t *cash = NULL;
  create_cash(&cash);

  for (int i = 0; i < 300; ++i) {
    strcpy(p[i].data, "aaaaaaaaaaaaaaaaaa");
    p[i].index = i;
  }
  cash_cstr(cash, p);
  for (int i = 0; i < 300; ++i) {
    manager_cash(cash, p + i);
  }
  manager_cash(cash, p + 297);
  manager_cash(cash, p + 44);
  cash_page *last = cash->root->next;
  while (last->next != NULL) {
    last = last->next;
  }
  ck_assert_int_eq(45, last->data->index);
  ck_assert_int_eq(44, cash->root->data->index);
}
END_TEST

Suite *tree_d_suite() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("CASH");

  /*Core test case*/
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, CASH_TRUE);
  tcase_add_test(tc_core, CASH_TRUE2);
  tcase_add_test(tc_core, CASH_TRUE3);
  tcase_add_test(tc_core, CASH_TRUE4);
  tcase_add_test(tc_core, CASH_TRUE5);
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
  return (number_failed == 0) ? TRUE : FALSE;
}
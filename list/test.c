#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../cash.h"

START_TEST(INSERT_LIST) {
  page p[5] = {0};
  cash_page *root = NULL;
  for (int i = 1; i < 6; ++i) {
    p[i - 1].index = i;
    strcpy(p[i - 1].data, "aaaaaaaaaaaaaa");
    insert_list(&root, p + i - 1);
  }
  ck_assert_int_eq(5, root->data->index);
}
END_TEST

Suite *tree_d_suite() {
  Suite *s;
  TCase *tc_core;

  s = suite_create("LIST ");

  /*Core test case*/
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, INSERT_LIST);
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
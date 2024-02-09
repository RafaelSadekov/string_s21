#include "s21_string.h"

#include <check.h>
#include <string.h>
#include <stdlib.h>

START_TEST(s21_memcmp_1) {
  size_t n1 = 3;
  char b1[1024] = "";
  char b11[1024] = "";
  char str_1_2[1024] = "TEST TEST TEST";
  ck_assert_int_eq(memcmp(b1, str_1_2, n1), s21_memcmp(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_memcmp_2) {
  size_t n2 = 5;
  char b2[1024] = "";
  char b22[1024] = "";
  char str_2_2[1024] = "THE OF \0 THE...BEST!!";
  ck_assert_int_eq(memcmp(b2, str_2_2, n2), s21_memcmp(b22, str_2_2, n2));
}
END_TEST

START_TEST(s21_memcmp_3) {
  size_t n3 = 4;
  char b3[1024] = "777 ";
  char b33[1024] = "777 ";
  char str_3_2[1024] = "S!!111231";
  ck_assert_int_eq(memcmp(b3, str_3_2, n3), s21_memcmp(b33, str_3_2, n3));
}
END_TEST

START_TEST(s21_memcmp_4) {
  size_t n4 = 4;
  char b4[1024] = "KU KU KU $! ";
  char b44[1024] = "KU KU KU $! ";
  ck_assert_int_eq(memcmp(b4, b4 + 7, n4), s21_memcmp(b44, b44 + 7, n4));
}
END_TEST

Suite *s21_memcmp_test(void) {
  Suite *s = suite_create("s21_memcmp");
  TCase *tc = tcase_create("case_s21_memcmp");
  tcase_add_test(tc, s21_memcmp_1);
  tcase_add_test(tc, s21_memcmp_2);
  tcase_add_test(tc, s21_memcmp_3);
  tcase_add_test(tc, s21_memcmp_4);
  suite_add_tcase(s, tc);
  return s;
}


int main(void) {
  int number_failed;
  Suite *suite = s21_math_suite();
  SRunner *runner = srunner_create(suite);

  srunner_run_all(runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
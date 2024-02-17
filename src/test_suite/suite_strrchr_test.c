#include "test_suite.h"
START_TEST(strrchr_last_occurrence) {
  const char *str = "find the last occurrence of character";
  ck_assert_ptr_eq(s21_strrchr(str, 'c'), strrchr(str, 'c'));
}
END_TEST

START_TEST(strrchr_not_present) {
  const char *str = "no such character here";
  ck_assert_ptr_eq(s21_strrchr(str, 'z'), NULL);
}
END_TEST

START_TEST(strrchr_null_char) {
  const char *str = "searching for the end";
  ck_assert_ptr_eq(s21_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_empty_string) {
  const char *str = "";
  ck_assert_ptr_eq(s21_strrchr(str, 'a'), NULL);
}
END_TEST

START_TEST(strrchr_only_char) {
  const char *str = "aaaa";
  ck_assert_ptr_eq(s21_strrchr(str, 'a'), strrchr(str, 'a'));
}
END_TEST

Suite *suite_strrchr(void) {
  Suite *s9 = suite_create("s21_strrchrk");
  TCase *tc_strrchr = tcase_create("case_s21_strrchrp");

  tcase_add_test(tc_strrchr, strrchr_last_occurrence);
  tcase_add_test(tc_strrchr, strrchr_not_present);
  tcase_add_test(tc_strrchr, strrchr_null_char);
  tcase_add_test(tc_strrchr, strrchr_empty_string);
  tcase_add_test(tc_strrchr, strrchr_only_char);

  suite_add_tcase(s9, tc_strrchr);
  return s9;
}
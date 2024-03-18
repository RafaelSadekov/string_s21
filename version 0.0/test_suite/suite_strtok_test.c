#include "test_suite.h"

// Базовый тест на разделение строки
START_TEST(strtok_basic) {
  char str[] = "This,is a.test";
  const char delim[] = ", .";
  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "This");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "is");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "a");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "test");
  token = s21_strtok(NULL, delim);
  ck_assert_ptr_null(token);
}
END_TEST

// Тест на разделение строки без разделителей
START_TEST(strtok_no_delimiters) {
  char str[] = "NoDelimitersHere";
  const char delim[] = ", .";
  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "NoDelimitersHere");
  token = s21_strtok(NULL, delim);
  ck_assert_ptr_null(token);
}
END_TEST

// Тест на разделение пустой строки
START_TEST(strtok_empty_string) {
  char str[] = "";
  const char delim[] = ", .";
  char *token = s21_strtok(str, delim);
  ck_assert_ptr_null(token);
}
END_TEST

// Тест на разделение строки с пустым набором разделителей
START_TEST(strtok_empty_delimiters) {
  char str[] = "Normal string";
  const char delim[] = "";
  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "Normal string");
  token = s21_strtok(NULL, delim);
  ck_assert_ptr_null(token);
}
END_TEST

// Тест на разделение строки с подряд идущими разделителями
START_TEST(strtok_consecutive_delimiters) {
  char str[] = "Consecutive,,,delimiters";
  const char delim[] = ",";
  char *token = s21_strtok(str, delim);
  ck_assert_str_eq(token, "Consecutive");
  token = s21_strtok(NULL, delim);
  ck_assert_str_eq(token, "delimiters");
  token = s21_strtok(NULL, delim);
  ck_assert_ptr_null(token);
}
END_TEST

Suite *suite_strtok(void) {
  Suite *s11 = suite_create("s21_strtok");
  TCase *tc_strtok = tcase_create("case_s21_strtok");

  tcase_add_test(tc_strtok, strtok_basic);
  tcase_add_test(tc_strtok, strtok_no_delimiters);
  tcase_add_test(tc_strtok, strtok_empty_string);
  tcase_add_test(tc_strtok, strtok_empty_delimiters);
  tcase_add_test(tc_strtok, strtok_consecutive_delimiters);

  suite_add_tcase(s11, tc_strtok);
  return s11;
}
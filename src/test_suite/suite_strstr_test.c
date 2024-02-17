#include "test_suite.h"
// Тест на поиск подстроки внутри строки
START_TEST(strstr_normal) {
  char *haystack = "The quick brown fox jumps over the lazy dog";
  char *needle = "brown";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест на отсутствие подстроки
START_TEST(strstr_not_found) {
  char *haystack = "Simple string for testing";
  char *needle = "complex";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест на пустую подстроку
START_TEST(strstr_empty_needle) {
  char *haystack = "Non-empty string";
  ck_assert_ptr_eq(s21_strstr(haystack, ""), haystack);
  // Сравниваем с началом haystack
}
END_TEST

// Тест на полностью пустые строки
START_TEST(strstr_all_empty) {
  ck_assert_ptr_eq(s21_strstr("", ""), "");
  // Ожидаем указатель на начало haystack
}
END_TEST

// Тест на частично совпадающую подстроку
START_TEST(strstr_partial_match) {
  char *haystack = "Partial match test";
  char *needle = "testy";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест на поиск подстроки в пустой строке
START_TEST(strstr_empty_haystack_nonempty_needle) {
  char *haystack = "";
  char *needle = "any";
  char *result = s21_strstr(haystack, needle);
  ck_assert_ptr_null(result);
}
END_TEST

Suite *suite_strstr(void) {
  Suite *s10 = suite_create("s21_strstr");
  TCase *tc_strstr = tcase_create("case_s21_strstr");

  tcase_add_test(tc_strstr, strstr_normal);
  tcase_add_test(tc_strstr, strstr_not_found);
  tcase_add_test(tc_strstr, strstr_empty_needle);
  tcase_add_test(tc_strstr, strstr_all_empty);
  tcase_add_test(tc_strstr, strstr_partial_match);
  tcase_add_test(tc_strstr, strstr_empty_haystack_nonempty_needle);

  suite_add_tcase(s10, tc_strstr);
  return s10;
}
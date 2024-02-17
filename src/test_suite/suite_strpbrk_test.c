#include "test_suite.h"
// Тест на нахождение первого вхождения одного из символов str2 в str1
START_TEST(strpbrk_found) {
  const char *str1 = "Example string";
  const char *str2 = "xyzs";
  char *result = s21_strpbrk(str1, str2);
  ck_assert_ptr_nonnull(result);
  ck_assert_ptr_eq(result, strpbrk(str1, str2));
  ck_assert_int_eq(*result, 's');
}
END_TEST

// Тест, когда символы из str2 не найдены в str1
START_TEST(strpbrk_not_found) {
  const char *str1 = "Hello, world!";
  const char *str2 = "xyz";
  char *result = s21_strpbrk(str1, str2);
  ck_assert_ptr_null(result);
}
END_TEST

// Тест с пустой строкой str1
START_TEST(strpbrk_empty_str1) {
  const char *str1 = "";
  const char *str2 = "abc";
  char *result = s21_strpbrk(str1, str2);
  ck_assert_ptr_null(result);
}
END_TEST

// Тест с пустой строкой str2
START_TEST(strpbrk_empty_str2) {
  const char *str1 = "Hello";
  const char *str2 = "";
  char *result = s21_strpbrk(str1, str2);
  ck_assert_ptr_null(result);
}
END_TEST

// Тест на нахождение первого вхождения символа из str2, когда str2 длиннее str1
START_TEST(strpbrk_long_str2) {
  const char *str1 = "abc";
  const char *str2 = "abcdefghijklmnopqrstuvwxyz";
  char *result = s21_strpbrk(str1, str2);
  ck_assert_ptr_nonnull(result);
  ck_assert_ptr_eq(result, strpbrk(str1, str2));
  ck_assert_int_eq(*result, 'a');
}
END_TEST

Suite *suite_strpbrk(void) {
  Suite *s8 = suite_create("s21_strpbrk");
  TCase *tc_strpbrk = tcase_create("case_s21_strncmp");

  tcase_add_test(tc_strpbrk, strpbrk_found);
  tcase_add_test(tc_strpbrk, strpbrk_not_found);
  tcase_add_test(tc_strpbrk, strpbrk_empty_str1);
  tcase_add_test(tc_strpbrk, strpbrk_empty_str2);
  tcase_add_test(tc_strpbrk, strpbrk_long_str2);

  suite_add_tcase(s8, tc_strpbrk);
  return s8;
}
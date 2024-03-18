#include "test_suite.h"
START_TEST(memchr_found) {
  const char str[] = "Hello, world!";
  int c = 'w';
  ck_assert_ptr_eq(s21_memchr(str, c, strlen(str)),
                   memchr(str, c, strlen(str)));
}
END_TEST

// использование strlen для определения длины строки в аргументах функций
// s21_memchr и memchr является предпочтительным. Это обеспечивает, что обе
// функции работают с одинаковым диапазоном памяти при сравнении, минимизируя
// влияние внешних факторов на результаты теста.

START_TEST(memchr_not_found) {
  const char str[] = "Hello, world!";
  int c = 'x';
  ck_assert_ptr_eq(s21_memchr(str, c, strlen(str)),
                   memchr(str, c, strlen(str)));
}
END_TEST

START_TEST(memchr_zero_length) {
  const char str[] = "Hello, world!";
  int c = 'H';
  ck_assert_ptr_eq(s21_memchr(str, c, 0), memchr(str, c, 0));
}
END_TEST

START_TEST(memchr_first_char) {
  const char str[] = "Hello, world!";
  int c = 'H';
  ck_assert_ptr_eq(s21_memchr(str, c, strlen(str)),
                   memchr(str, c, strlen(str)));
}
END_TEST

START_TEST(memchr_last_char) {
  const char str[] = "Hello, world!";
  int c = '!';
  ck_assert_ptr_eq(s21_memchr(str, c, strlen(str)),
                   memchr(str, c, strlen(str)));
}
END_TEST

Suite *suite_memchr(void) {
  Suite *s3 = suite_create("s21_memchr");
  TCase *tc_memchr = tcase_create("case_s21_memchr");

  tcase_add_test(tc_memchr, memchr_found);
  tcase_add_test(tc_memchr, memchr_not_found);
  tcase_add_test(tc_memchr, memchr_zero_length);
  tcase_add_test(tc_memchr, memchr_first_char);
  tcase_add_test(tc_memchr, memchr_last_char);

  suite_add_tcase(s3, tc_memchr);
  return s3;
}
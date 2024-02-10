#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(s21_strlen_1) {
  const char str[] = "";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_2) {
  const char str[] = "Hello";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_3) {
  const char str[] = "A";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_4) {
  const char str[] = "This is a test.";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_5) {
  const char str[] = "Another test with spaces";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_6) {
  const char str[] = "1234567890";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_7) {
  const char str[] = "Line\nNew line";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_8) {
  const char str[] = "\0Hidden";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_9) {
  char str[1024] = "Long string with a lot of characters...";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

START_TEST(s21_strlen_10) {
  const char str[] = "Ends with space ";
  ck_assert_uint_eq(s21_strlen(str), strlen(str));
}
END_TEST

Suite *s21_strle_test(void) {
  Suite *s = suite_create("s21_strlen");
  TCase *tc = tcase_create("case_s21_strlen");
  tcase_add_test(tc, s21_strlen_1);
  tcase_add_test(tc, s21_strlen_2);
  tcase_add_test(tc, s21_strlen_3);
  tcase_add_test(tc, s21_strlen_4);
  tcase_add_test(tc, s21_strlen_5);
  tcase_add_test(tc, s21_strlen_6);
  tcase_add_test(tc, s21_strlen_7);
  tcase_add_test(tc, s21_strlen_8);
  tcase_add_test(tc, s21_strlen_9);
  tcase_add_test(tc, s21_strlen_10);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(s21_memcmp_1) {
  size_t n1 = 3;
  char b1[1024] = "Hello,";
  char b11[1024] = "Hello,";
  char str_1_2[1024] = "Hello, World!";
  ck_assert_int_eq(memcmp(b1, str_1_2, n1), s21_memcmp(b11, str_1_2, n1));
}
END_TEST

START_TEST(s21_memcmp_2) {
  size_t n2 = 4;
  char b2[1024] = "1234";
  char str_2_2[1024] = "1235";
  ck_assert_int_lt(s21_memcmp(b2, str_2_2, n2), 0);
}
END_TEST

START_TEST(s21_memcmp_3) {
  size_t n3 = 4;
  char b3[1024] = "SB SB SB $! ";
  char str_3_3[1024] = "SB SB SB $! ";
  ck_assert_int_eq(memcmp(b3, b3 + 7, n3),
                   s21_memcmp(str_3_3, str_3_3 + 7, n3));
}
END_TEST

START_TEST(s21_memcmp_4) {
  size_t n4 = 6;
  char b4[1024] = "abcdef";
  char str_4_4[1024] = "abcDef";
  ck_assert_int_gt(s21_memcmp(b4, str_4_4, n4), 0);
}
END_TEST

START_TEST(s21_memcmp_5) {
  size_t n5 = 8;
  char b5[1024] = "a\0b\0c\0";
  char b55[1024] = "a\0b\0c\0";
  ck_assert_int_eq(s21_memcmp(b5, b55, n5), 0);
}
END_TEST

Suite *s21_string_suite(void) {
  Suite *suite = suite_create("s21_string");
  TCase *tc_strlen = tcase_create("s21_strlen");
  TCase *tc_memcmp = tcase_create("s21_memcmp");

  tcase_add_test(tc_strlen, s21_strlen_1);
  tcase_add_test(tc_strlen, s21_strlen_2);
  tcase_add_test(tc_strlen, s21_strlen_3);
  tcase_add_test(tc_strlen, s21_strlen_4);
  tcase_add_test(tc_strlen, s21_strlen_5);
  tcase_add_test(tc_strlen, s21_strlen_6);
  tcase_add_test(tc_strlen, s21_strlen_7);
  tcase_add_test(tc_strlen, s21_strlen_8);
  tcase_add_test(tc_strlen, s21_strlen_9);
  tcase_add_test(tc_strlen, s21_strlen_10);

  tcase_add_test(tc_memcmp, s21_memcmp_1);
  tcase_add_test(tc_memcmp, s21_memcmp_2);
  tcase_add_test(tc_memcmp, s21_memcmp_3);
  tcase_add_test(tc_memcmp, s21_memcmp_4);
  tcase_add_test(tc_memcmp, s21_memcmp_5);

  suite_add_tcase(suite, tc_strlen);
  suite_add_tcase(suite, tc_memcmp);

  return suite;
}

int main(void) {
  int number_failed;
  Suite *s = s21_string_suite();
  SRunner *sr = srunner_create(s);  //  Создаем объект для запуска тестов
  srunner_run_all(sr, CK_NORMAL);  // Запускаем все тесты в сюите
  number_failed =
      srunner_ntests_failed(sr);  // Получаем количество проваленных тестов
  srunner_free(sr);  // Освобождаем ресурсы
  return (number_failed == 0) ? EXIT_SUCCESS
                              : EXIT_FAILURE;  // Возвращаем статус выполнения
}
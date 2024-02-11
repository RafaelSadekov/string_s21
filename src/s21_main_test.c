#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_s21_strlen) {
  const char str1[] = "";
  const char str2[] = "Hello";
  const char str3[] = "A";
  const char str4[] = "This is a test.";
  const char str5[] = "Another test with spaces";
  const char str6[] = "1234567890";
  const char str7[] = "Line\nNew line";
  const char str8[] = "\0Hidden";
  char str9[1024] = "Long string with a lot of characters...";
  const char str10[] = "Ends with space ";
  ck_assert_uint_eq(s21_strlen(str1), strlen(str1));
  ck_assert_uint_eq(s21_strlen(str2), strlen(str2));
  ck_assert_uint_eq(s21_strlen(str3), strlen(str3));
  ck_assert_uint_eq(s21_strlen(str4), strlen(str4));
  ck_assert_uint_eq(s21_strlen(str5), strlen(str5));
  ck_assert_uint_eq(s21_strlen(str6), strlen(str6));
  ck_assert_uint_eq(s21_strlen(str7), strlen(str7));
  ck_assert_uint_eq(s21_strlen(str8), strlen(str8));
  ck_assert_uint_eq(s21_strlen(str9), strlen(str9));
  ck_assert_uint_eq(s21_strlen(str10), strlen(str10));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s1 = suite_create("s21_strlen");
  TCase *tc_strlen = tcase_create("case_s21_strlen");
  tcase_add_test(tc_strlen, test_s21_strlen);
  suite_add_tcase(s1, tc_strlen);
  return s1;
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

Suite *s21_memcmp_test(void) {
  Suite *suite = suite_create("s21_memcmp");
  TCase *tc_memcmp = tcase_create("case_s21_memcmp");

  tcase_add_test(tc_memcmp, s21_memcmp_1);
  tcase_add_test(tc_memcmp, s21_memcmp_2);
  tcase_add_test(tc_memcmp, s21_memcmp_3);
  tcase_add_test(tc_memcmp, s21_memcmp_4);
  tcase_add_test(tc_memcmp, s21_memcmp_5);

  suite_add_tcase(suite, tc_memcmp);

  return suite;
}

START_TEST(test_memchr_found) {
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

START_TEST(test_memchr_not_found) {
  const char str[] = "Hello, world!";
  int c = 'x';
  ck_assert_ptr_eq(s21_memchr(str, c, strlen(str)),
                   memchr(str, c, strlen(str)));
}
END_TEST

START_TEST(test_memchr_zero_length) {
  const char str[] = "Hello, world!";
  int c = 'H';
  ck_assert_ptr_eq(s21_memchr(str, c, 0), memchr(str, c, 0));
}
END_TEST

START_TEST(test_memchr_first_char) {
  const char str[] = "Hello, world!";
  int c = 'H';
  ck_assert_ptr_eq(s21_memchr(str, c, strlen(str)),
                   memchr(str, c, strlen(str)));
}
END_TEST

START_TEST(test_memchr_last_char) {
  const char str[] = "Hello, world!";
  int c = '!';
  ck_assert_ptr_eq(s21_memchr(str, c, strlen(str)),
                   memchr(str, c, strlen(str)));
}
END_TEST

Suite *s21_memchr_test(void) {
  Suite *s = suite_create("s21_memchr");
  TCase *tc_memchr = tcase_create("case_s21_memchr");

  tcase_add_test(tc_memchr, test_memchr_found);
  tcase_add_test(tc_memchr, test_memchr_not_found);
  tcase_add_test(tc_memchr, test_memchr_zero_length);
  tcase_add_test(tc_memchr, test_memchr_first_char);
  tcase_add_test(tc_memchr, test_memchr_last_char);

  suite_add_tcase(s, tc_memchr);
  return s;
}

START_TEST(test_memcpy_normal_string) {
  char src[] = "Test string";
  char dest[20];
  s21_memcpy(dest, src,
             strlen(src) + 1);  // +1 для копирования нуль-терминатора
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(test_memcpy_without_overlap) {
  char src[] = "Example text";
  char dest[20];
  s21_memcpy(dest, src,
             strlen(src) + 1);  // +1 для копирования нуль-терминатора
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(test_memcpy_zero_bytes) {
  char src[] = "Non-empty";
  char dest[20] = "Initial";
  s21_memcpy(dest, src, 0);  // Копирование 0 байтов
  ck_assert_str_eq(dest, "Initial");
}
END_TEST

START_TEST(test_memcpy_large_data) {
  char src[1024];
  char dest[1024];
  // Инициализация src некоторыми данными
  for (int i = 0; i < 1024; i++) {
    src[i] = (char)(i % 256);
  }
  s21_memcpy(dest, src, sizeof(src));
  ck_assert_mem_eq(dest, src, sizeof(src));
}
END_TEST

START_TEST(test_memcpy_binary_data) {
  unsigned char src[] = {0xDE, 0xAD, 0xBE, 0xEF};
  unsigned char dest[4];
  s21_memcpy(dest, src, sizeof(src));
  ck_assert_mem_eq(dest, src, sizeof(src));
}
END_TEST

Suite *s21_memcpy_test(void) {
  Suite *s = suite_create("s21_memcpy");
  TCase *tc_memcpy = tcase_create("case_s21_memcpy");

  tcase_add_test(tc_memcpy, test_memcpy_normal_string);
  tcase_add_test(tc_memcpy, test_memcpy_without_overlap);
  tcase_add_test(tc_memcpy, test_memcpy_zero_bytes);
  tcase_add_test(tc_memcpy, test_memcpy_large_data);
  tcase_add_test(tc_memcpy, test_memcpy_binary_data);

  suite_add_tcase(s, tc_memcpy);
  return s;
}

int main(void) {
  int number_failed;
  SRunner *sr = srunner_create(NULL);  //  Создаем объект для запуска тестов

  srunner_add_suite(sr, suite_strlen());
  srunner_add_suite(sr, s21_memcmp_test());
  srunner_add_suite(sr, s21_memchr_test());
  srunner_add_suite(sr, s21_memcpy_test());
  srunner_run_all(sr, CK_NORMAL);  // Запускаем все тесты в сюите
  number_failed =
      srunner_ntests_failed(sr);  // Получаем количество проваленных тестов
  srunner_free(sr);  // Освобождаем ресурсы
  return (number_failed == 0) ? EXIT_SUCCESS
                              : EXIT_FAILURE;  // Возвращаем статус выполнения
}
#include <check.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

START_TEST(test_strlen) {
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
  tcase_add_test(tc_strlen, test_strlen);
  suite_add_tcase(s1, tc_strlen);
  return s1;
}

// Тест на сравнение начала строк
START_TEST(memcmp_compare_start) {
  size_t n1 = 3;
  char b1[1024] = "Hello,";
  char b11[1024] = "Hello,";
  char str_1_2[1024] = "Hello, World!";
  ck_assert_int_eq(memcmp(b1, str_1_2, n1), s21_memcmp(b11, str_1_2, n1));
}
END_TEST
// Тест на сравнение строк с одним различающимся символом
START_TEST(memcmp_minimal_difference) {
  size_t n2 = 4;
  char b2[1024] = "1234";
  char str_2_2[1024] = "1235";
  ck_assert_int_lt(s21_memcmp(b2, str_2_2, n2), 0);
}
END_TEST
// Тест на сравнение одинаковых участков в строках
START_TEST(memcmp_identical_parts) {
  size_t n3 = 4;
  char b3[1024] = "SB SB SB $! ";
  char str_3_3[1024] = "SB SB SB $! ";
  ck_assert_int_eq(memcmp(b3, b3 + 7, n3),
                   s21_memcmp(str_3_3, str_3_3 + 7, n3));
}
END_TEST
// Тест на сравнение строк с учётом регистра
START_TEST(memcmp_case_sensitivity) {
  size_t n4 = 6;
  char b4[1024] = "abcdef";
  char str_4_4[1024] = "abcDef";
  ck_assert_int_gt(s21_memcmp(b4, str_4_4, n4), 0);
}
END_TEST
// Тест на сравнение строк с нулевыми символами
START_TEST(memcmp_zero_chars) {
  size_t n5 = 8;
  char b5[1024] = "a\0b\0c\0";
  char b55[1024] = "a\0b\0c\0";
  ck_assert_int_eq(s21_memcmp(b5, b55, n5), 0);
}
END_TEST

Suite *suite_memcmp(void) {
  Suite *s2 = suite_create("s21_memcmp");
  TCase *tc_memcmp = tcase_create("case_s21_memcmp");

  tcase_add_test(tc_memcmp, memcmp_compare_start);
  tcase_add_test(tc_memcmp, memcmp_minimal_difference);
  tcase_add_test(tc_memcmp, memcmp_identical_parts);
  tcase_add_test(tc_memcmp, memcmp_case_sensitivity);
  tcase_add_test(tc_memcmp, memcmp_zero_chars);

  suite_add_tcase(s2, tc_memcmp);

  return s2;
}

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

START_TEST(memcpy_normal_string) {
  char src[] = "Test string";
  char dest[20];
  s21_memcpy(dest, src,
             strlen(src) + 1);  // +1 для копирования нуль-терминатора
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(memcpy_without_overlap) {
  char src[] = "Example text";
  char dest[20];
  s21_memcpy(dest, src,
             strlen(src) + 1);  // +1 для копирования нуль-терминатора
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(memcpy_zero_bytes) {
  char src[] = "Non-empty";
  char dest[20] = "Initial";
  s21_memcpy(dest, src, 0);  // Копирование 0 байтов
  ck_assert_str_eq(dest, "Initial");
}
END_TEST

START_TEST(memcpy_large_data) {
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

START_TEST(memcpy_binary_data) {
  unsigned char src[] = {0xDE, 0xAD, 0xBE, 0xEF};
  unsigned char dest[4];
  s21_memcpy(dest, src, sizeof(src));
  ck_assert_mem_eq(dest, src, sizeof(src));
}
END_TEST

Suite *suite_memspy(void) {
  Suite *s4 = suite_create("s21_memcpy");
  TCase *tc_memcpy = tcase_create("case_s21_memcpy");

  tcase_add_test(tc_memcpy, memcpy_normal_string);
  tcase_add_test(tc_memcpy, memcpy_without_overlap);
  tcase_add_test(tc_memcpy, memcpy_zero_bytes);
  tcase_add_test(tc_memcpy, memcpy_large_data);
  tcase_add_test(tc_memcpy, memcpy_binary_data);

  suite_add_tcase(s4, tc_memcpy);
  return s4;
}

START_TEST(memset_basic_fill) {
  char buffer[10];
  s21_memset(buffer, 'A', sizeof(buffer));
  for (size_t i = 0; i < sizeof(buffer); i++) {
    ck_assert_msg(buffer[i] == 'A', "Buffer[%zu] != 'A'", i);
  }
}
END_TEST

START_TEST(memset_zero_length) {
  char buffer[10] = "1234567890";
  s21_memset(buffer, 'A', 0);
  ck_assert_str_eq(buffer, "1234567890");
}
END_TEST

START_TEST(memset_partial_fill) {
  char buffer[10] = "1234567890";
  s21_memset(buffer, 'B', 5);
  ck_assert_str_eq(buffer, "BBBBB67890");
}
END_TEST

START_TEST(memset_various_chars) {
  char buffer[5];
  s21_memset(buffer, '\0', sizeof(buffer));
  for (size_t i = 0; i < sizeof(buffer); i++) {
    ck_assert_msg(buffer[i] == '\0', "Buffer[%zu] != '\\0'", i);
  }
  s21_memset(buffer, 'Z', sizeof(buffer));
  for (size_t i = 0; i < sizeof(buffer); i++) {
    ck_assert_msg(buffer[i] == 'Z', "Buffer[%zu] != 'Z'", i);
  }
}
END_TEST

START_TEST(memset_large_buffer) {
  size_t size = 1024;  // Используем меньший размер для экономии памяти
  char *buffer = (char *)malloc(size);
  memset(buffer, 'C', size);
  for (size_t i = 0; i < size; i++) {
    ck_assert_msg(buffer[i] == 'C', "Buffer[%zu] != 'C'", i);
  }
  free(buffer);
}
END_TEST

Suite *suite_memset(void) {
  Suite *s5 = suite_create("s21_memset");
  TCase *tc_memset = tcase_create("case_s21_memset");

  tcase_add_test(tc_memset, memset_basic_fill);
  tcase_add_test(tc_memset, memset_zero_length);
  tcase_add_test(tc_memset, memset_partial_fill);
  tcase_add_test(tc_memset, memset_various_chars);
  tcase_add_test(tc_memset, memset_large_buffer);

  suite_add_tcase(s5, tc_memset);
  return s5;
}

// Тест на нахождение символа в начале строки
START_TEST(strchr_start) {
  char str[] = "Test string";
  int ch = 'T';
  char *result = s21_strchr(str, ch);
  char *expected = strchr(str, ch);
  ck_assert_ptr_eq(result, expected);  // Сравнивает два указателя на равенство.
  ck_assert_str_eq(
      result, expected);  // Сравнивает две строки на идентичность содержимого.
}
END_TEST

// Тест на нахождение символа в середине строки
START_TEST(strchr_middle) {
  char str[] = "Example string";
  int ch = 'm';
  char *result = s21_strchr(str, ch);
  char *expected = strchr(str, ch);
  ck_assert_ptr_eq(result, expected);
  ck_assert_str_eq(result, expected);
}
END_TEST

// Тест на отсутствие символа в строке
START_TEST(strchr_not_found) {
  char str[] = "Another example";
  int ch = 'z';
  char *result = s21_strchr(str, ch);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

// Тест на поиск нулевого символа (терминатор строки)
START_TEST(strchr_null_char) {
  char str[] = "Null terminator test";
  int ch = '\0';
  char *result = s21_strchr(str, ch);
  char *expected = strchr(str, ch);
  ck_assert_ptr_eq(result, expected);
  ck_assert_str_eq(result, expected);
}
END_TEST

Suite *suite_strchr(void) {
  Suite *s6 = suite_create("s21_strchr");
  TCase *tc_strchr = tcase_create("case_s21_strchr");

  tcase_add_test(tc_strchr, strchr_start);
  tcase_add_test(tc_strchr, strchr_middle);
  tcase_add_test(tc_strchr, strchr_not_found);
  tcase_add_test(tc_strchr, strchr_null_char);

  suite_add_tcase(s6, tc_strchr);
  return s6;
}

// Тест на полное сравнение идентичных строк
START_TEST(strncmp_full_equal) {
  const char *str1 = "abcdef";
  const char *str2 = "abcdef";
  ck_assert_int_eq(s21_strncmp(str1, str2, strlen(str1)), 0);
}
END_TEST

// Тест на частичное сравнение идентичных строк
START_TEST(strncmp_partial_equal) {
  const char *str1 = "abcdef";
  const char *str2 = "abcdef";
  ck_assert_int_eq(s21_strncmp(str1, str2, 3),
                   0);  // Сравниваем только первые 3 символа
}
END_TEST

// Тест на сравнение с длиной n равной 0
START_TEST(strncmp_zero_length) {
  const char *str1 = "abcdef";
  const char *str2 = "xyz";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0),
                   0);  // Сравнение с n=0 должно всегда возвращать 0
}
END_TEST

// Тест на сравнение строк, когда n больше длины строк
START_TEST(strncmp_length_exceeds) {
  const char *str1 = "abc";
  const char *str2 = "abc";
  ck_assert_int_eq(s21_strncmp(str1, str2, 10),
                   0);  // n больше длины строк, строки равны
}
END_TEST

// Тест на сравнение строк различной длины
START_TEST(strncmp_diff_length) {
  const char *str1 = "abc";
  const char *str2 = "abcd";
  int result = s21_strncmp(str1, str2, strlen(str2));
  ck_assert(result < 0);  // str1 короче str2, должно быть < 0
}
END_TEST

// Тест на сравнение непустой строки с пустой при n=0
START_TEST(strncmp_empty_vs_nonempty) {
  const char *str1 = "";
  const char *str2 = "abc";
  ck_assert_int_eq(s21_strncmp(str1, str2, 0),
                   0);  // Сравнение с n=0, ожидается 0
}
END_TEST

Suite *suite_strncmp(void) {
  Suite *s7 = suite_create("s21_strncmp");
  TCase *tc_strncmp = tcase_create("case_s21_strncmp");

  tcase_add_test(tc_strncmp, strncmp_full_equal);
  tcase_add_test(tc_strncmp, strncmp_partial_equal);
  tcase_add_test(tc_strncmp, strncmp_zero_length);
  tcase_add_test(tc_strncmp, strncmp_length_exceeds);
  tcase_add_test(tc_strncmp, strncmp_diff_length);
  tcase_add_test(tc_strncmp, strncmp_empty_vs_nonempty);

  suite_add_tcase(s7, tc_strncmp);
  return s7;
}

#ifdef S21_Disabled
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

// Базовая объединением строк с ограниченной длиной
START_TEST(strncat_basic_concat) {
  char dest[50] = "Initial ";
  const char src[] = "concatenation";
  size_t n = 5;  // Ограничение до первых 5 символов src
  s21_strncat(dest, src, n);
  ck_assert_str_eq(dest, "Initial conc");
}
END_TEST

// Объединением строк, уважающая нулевой терминатор строки
START_TEST(strncat_full_concat) {
  char dest[50] = "Full ";
  const char src[] = "concatenation";
  s21_strncat(dest, src, strlen(src));  // Использование полной длины src
  ck_assert_str_eq(dest, "Full concatenation");
}
END_TEST

// Попытка объединением пустой строки
START_TEST(strncat_empty_src) {
  char dest[50] = "Empty source ";
  const char src[] = "";
  s21_strncat(dest, src, 5);  // Попытка с 5 символами пустого src
  ck_assert_str_eq(dest, "Empty source ");
}
END_TEST

// Объединением строки в пустую целевую строку
START_TEST(strncat_to_empty_dest) {
  char dest[50] = "";
  const char src[] = "Non-empty source";
  s21_strncat(dest, src, strlen(src));  // Полная длина не пустого src
  ck_assert_str_eq(dest, "Non-empty source");
}
END_TEST

// Объединением строк нулевой длины
START_TEST(strncat_zero_length) {
  char dest[50] = "Zero length ";
  const char src[] = "ignored";
  s21_strncat(dest, src,
              0);  // n равно 0, поэтому src не должен быть конкатенирован
  ck_assert_str_eq(dest, "Zero length ");
}
END_TEST

// Объединением строк с перекрытием строк (неопределённое поведение, но часто
// тестируется)
START_TEST(strncat_overlap) {
  char buffer[50] = "Overlap";
  s21_strncat(buffer, buffer, 5);
  // Попытка объединением строк buffer самого с собой
  // Примечание: Ожидаемое поведение не определено, этот тест иллюстрирует общее
  // неправильное использование. ck_assert_*() зависит от конкретного поведения
  // вашей реализации.
}
END_TEST

Suite *suite_strncat(void) {
  Suite *s12 = suite_create("s21_strncat");
  TCase *tc_strncat = tcase_create("case_s21_strncat");

  tcase_add_test(tc_strncat, strncat_basic_concat);
  tcase_add_test(tc_strncat, strncat_full_concat);
  tcase_add_test(tc_strncat, strncat_empty_src);
  tcase_add_test(tc_strncat, strncat_to_empty_dest);
  tcase_add_test(tc_strncat, strncat_zero_length);
  tcase_add_test(tc_strncat, strncat_overlap);

  suite_add_tcase(s12, tc_strncat);
  return s12;
}

#endif

int main(void) {
  int number_failed;
  SRunner *sr = srunner_create(NULL);  //  Создаем объект для запуска тестов

  srunner_add_suite(sr, suite_strlen());
  srunner_add_suite(sr, suite_memcmp());
  srunner_add_suite(sr, suite_memchr());
  srunner_add_suite(sr, suite_memspy());
  srunner_add_suite(sr, suite_memset());
  srunner_add_suite(sr, suite_strchr());
  srunner_add_suite(sr, suite_strncmp());
  // srunner_add_suite(sr, suite_strpbrk());
  // srunner_add_suite(sr, suite_strrchr());
  // srunner_add_suite(sr, suite_strstr());
  // srunner_add_suite(sr, suite_strtok());
  // srunner_add_suite(sr, suite_strncat());

  srunner_run_all(sr, CK_SUBUNIT);  // Запускаем все тесты в сюите
  number_failed =
      srunner_ntests_failed(sr);  // Получаем количество проваленных тестов
  srunner_free(sr);  // Освобождаем ресурсы
  return (number_failed == 0) ? EXIT_SUCCESS
                              : EXIT_FAILURE;  // Возвращаем статус выполнения
}
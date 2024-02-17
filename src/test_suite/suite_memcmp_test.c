#include "test_suite.h"

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
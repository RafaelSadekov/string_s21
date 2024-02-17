#include <check.h>
#include <stdlib.h>
#include <string.h>

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
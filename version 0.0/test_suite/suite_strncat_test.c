#include "test_suite.h"

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
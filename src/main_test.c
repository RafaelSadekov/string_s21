#include <stdio.h>
#include <string.h>

#include "s21_string.h"

void test_s21_strncmp(const char *s1, const char *s2, size_t n) {
  int result1 = s21_strncmp(s1, s2, n);
  int result2 = strncmp(s1, s2, n);

  if ((result1 == 0 && result2 == 0) || (result1 < 0 && result2 < 0) ||
      (result1 > 0 && result2 > 0)) {
    printf("Test passed: s21_strncmp(\"%s\", \"%s\", %zu) = %d, strncmp = %d\n",
           s1, s2, n, result1, result2);
  } else {
    printf("Test failed: s21_strncmp(\"%s\", \"%s\", %zu) = %d, strncmp = %d\n",
           s1, s2, n, result1, result2);
  }
}
int main() {
  // Пример тестирования функции s21_strlen
  char testString[] = "Hello, World!";
  size_t my_strlen = s21_strlen(testString);
  size_t original_strlen = strlen(testString);

  if (my_strlen == original_strlen) {
    printf("s21_strlen works correctly\n");
  } else {
    printf("s21_strlen does not work correctly\n");
  }

  test_s21_strncmp("Hello", "Hello", 5);
  test_s21_strncmp("ABC", "ABD", 3);
  test_s21_strncmp("short", "longer", 5);
  test_s21_strncmp("same", "same", 4);
  test_s21_strncmp("lower", "lowercase", 5);
  test_s21_strncmp("", "", 0);
  return 0;
}
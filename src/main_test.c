#include <stdio.h>
#include <string.h>

#include "s21_string.h"

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

  // Здесь добавьте дополнительные тесты для других функций

  return 0;
}
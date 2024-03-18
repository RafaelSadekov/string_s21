#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

// Выделение памяти
void* add_memory(char** str, size_t n) {
  int error_flag = 1;
  char* temp = realloc(*str, sizeof(char) * n);
  if (temp != NULL) {
    *str = temp;
    error_flag = 0;
  }
  if (error_flag == 1) {
    perror("Error");
  }
  return *str;
}
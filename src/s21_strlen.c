#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t length = 0;

  while (str[length] != '\0') {
    length++;
  }

  return length;
}

// используем цикл для подсчета символов до тех пор, пока не встретим
// завершающий нулевой символ ('\0').
// https://www.youtube.com/watch?v=skRm_VS_HKc
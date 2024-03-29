#include "s21_string.h"

//@gylberdo
void *s21_memset(void *str, int c, size_t n) {
  char *temp = str;
  for (size_t i = 0; i < n; ++i) {
    temp[i] = (char)c;
  }
  return temp;
}

// dejaelen

// void *s21_memset(void *str, int c, size_t n) {
//   unsigned char *s = (unsigned char *)str;
//   for (size_t i = 0; i < n; i++) {
//     s[i] = (unsigned char)c;
//   }
//   return str;
// }

/*
спользование unsigned char * является предпочтительным для работы с бинарными
данными, поскольку это избегает потенциальных проблем с знаковым расширением при
работе со значениями байтов.

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.
// устанавливаем значение c в каждый байт, на который указывает s[i]

*/
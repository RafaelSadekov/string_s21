#include <stdio.h>

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
//@gylberdo
void* s21_memchr(const void* str, int c, size_t count) {
  char* out = NULL;
  char* temp = (char*)str;
  for (size_t i = 0; i < count; i++) {
    if (c == temp[i]) {
      out = &temp[i];
    }
  }
  return out;
}

// возвращает указатель. В вашем случае, она возвращает указатель типа void *,
// что соответствует типу, используемому в стандартной функции memchr.

/*
void *s21_memchr(const void *str, int c, size_t count) {
    const unsigned char *p = str;
    for (size_t i = 0; i < count; i++) {
        if (p[i] == (unsigned char)c) {
            return (void *)(p + i);
        }
    }
    return NULL;
}
*/
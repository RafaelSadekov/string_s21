#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  unsigned char *d = dest;
  const unsigned char *s = src;

  for (size_t i = 0; i < n; ++i) {
    d[i] = s[i];
  }

  return dest;
}

/*
копирует n байтов из строки src в строку dest. Мы используем цикл для
копирования байтов один за другим. После завершения копирования мы возвращаем
указатель на начало строки dest.
*/
#include "s21_string.h"

// dejaelen
// void *s21_memcpy(void *dest, const void *src, size_t n) {
//   unsigned char *d = dest;
//   const unsigned char *s = src;

//   for (size_t i = 0; i < n; ++i) {
//     d[i] = s[i];
//   }

//   return dest;
// }

//@gylberdo
// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, size_t n) {
  char *temp = (char *)add_memory(dest, (n + 1));
  char *temp2 = (char *)src;
  for (size_t i = 0; i < n; ++i) {
    temp[i] = temp2[i];
  }
  dest = temp;
  return dest;
}

/*
копирует n байтов из строки src в строку dest. Мы используем цикл для
копирования байтов один за другим. После завершения копирования мы возвращаем
указатель на начало строки dest.

MEMPCPY (void *dest, const void *src, size_t len)
  34 {
  35   return memcpy (dest, src, len) + len;
  36 }

*/

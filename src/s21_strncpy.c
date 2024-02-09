#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
    size_t size = s21_strlen(dest);
    if (size < n){
      n = size;
    }
    if (src){

    }
}

// char *strncpy(char *dest, const char *src, size_t n)	
// принимает нп вход адреса на 2 строки и количество символов которое 
// будем копировать
// Копирует до n символов из строки, на которую указывает src, в dest.

/*
char *
  27 STRNCPY (char *s1, const char *s2, size_t n)
  28 {
  29   size_t size = __strnlen (s2, n);
  30   if (size != n)
  31     memset (s1 + size, '\0', n - size);
  32   return memcpy (s1, s2, size);
  33 }
*/
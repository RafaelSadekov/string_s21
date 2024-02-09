#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n){
    
}

/*
Добавляет строку, на которую указывает src, в конец строки, 
на которую указывает dest, длиной до n символов.


char *
  27 STRNCAT (char *s1, const char *s2, size_t n)
  28 {
  29   char *s = s1;
  30 
  31   //Find the end of S1. 
  32   s1 += strlen (s1);
  33 
  34   size_t ss = __strnlen (s2, n);
  35 
  36   s1[ss] = '\0';
  37   memcpy (s1, s2, ss);
  38 
  39   return s;
  40 }

*/
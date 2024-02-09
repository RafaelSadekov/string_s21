#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last = s21_NULL;
  const char *p;

  // Функция strchr ищет последнее вхождения символа, код которого указан в
  // аргументе ch, в строке, на которую указывает аргумент str.
  //  Возвращаемое значение: Указатель на искомый символ, если он найден в
  //  строке str, иначе NULL.

  while ((p = s21_strchr(str, c)) != s21_NULL) {
    last = p;  // Сохраняем последнее найденное вхождение
    str = p + 1;  // Сдвигаем начало поиска
  }

  return (char *)last;
}

/* Find the last occurrence of C in S.
  27 char *
  28 STRRCHR (const char *s, int c)
  29 {
  30   const char *found, *p;
  31
  32   c = (unsigned char) c;
  33
  34   /// Since strchr is fast, we use it rather than the obvious loop.
  35
  36   if (c == '\0')
  37     return strchr (s, '\0');
  38
  39   found = NULL;
  40   while ((p = strchr (s, c)) != NULL)
  41     {
  42       found = p;
  43       s = p + 1;
  44     }
  45
  46   return (char *) found;
  47 }
  */
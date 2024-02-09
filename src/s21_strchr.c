#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  for (; *str != '\0'; str++) {  // Простой проход по строке
    if (*str == (char)c) {
      return (char *)str;  // Возвращаем указатель на найденный символ
    }
  }
  if (c == '\0') {
    return (char *)
        str;  // Учет возвращения указателя на терминирующий нулевой символ
  }
  return s21_NULL;
}

/*
char *s21_strchr(const char *str, int c){
int Length = s21_strlen(str) + 1;
  char *answer = s21_NULL;

  for (int i = 0; i < Length && answer == s21_NULL; i += 1)
    if (str[i] == c) answer = (char *)str;

  return answer;
}
Вызов s21_strlen требует прохода по всей строке для определения её длины, даже
если искомый символ находится в начале строки. Это приводит к лишним операциям,
если символ будет найден до конца строки.

Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
на которую указывает аргумент str.
*/

/* Find the first occurrence of C in S.
  28 char *
  29 strchr (const char *s, int c_in)
  30 {
  31   char *r = __strchrnul (s, c_in);
  32   return (*(unsigned char *)r == (unsigned char)c_in) ? r : NULL;
  33 }

  strchrnul
  Find the first occurrence of C in S or the final NUL byte.
  33 char *
  34 __strchrnul (const char *str, int c_in)
  35 {
  36  //////Align pointer to sizeof op_t.
  37   uintptr_t s_int = (uintptr_t) str;
  38   const op_t *word_ptr = (const op_t *) PTR_ALIGN_DOWN (str, sizeof
  (op_t)); 39 40   op_t repeated_c = repeat_bytes (c_in); 41 42   op_t word =
  *word_ptr; 43   find_t mask = shift_find (find_zero_eq_all (word, repeated_c),
  s_int); 44   if (mask != 0) 45     return (char *) str + index_first (mask);
  46
  47   do
  48     word = *++word_ptr;
  49   while (! has_zero_eq (word, repeated_c));
  50
  51   return (char *) word_ptr + index_first_zero_eq (word, repeated_c);
  52 }

*/
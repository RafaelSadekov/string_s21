#include "s21_string.h"

int s21_strcmp(const char* str1, const char* str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  return *str1 - *str2;
}

/*
// Сравнивает не более первых n байтов str1 и str2.
https://www.youtube.com/watch?v=skRm_VS_HKc
*/

/*
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int flag = 0;
    int result = 0;

    // Если n равно 0, считаем строки равными.
    if (n == 0) {
        flag = 1;
        result = 0;
    }

    // Если n не равно 0, сравниваем строки посимвольно до n или до конца
строки. if (!flag) { s21_size_t i = 0; while (*(str1 + i) && *(str2 + i) && i <
n - 1 && *(str1 + i) == *(str2 + i)) i++;

        // Если строки отличаются, вычисляем разницу между символами.
        if (*(str1 + i) != *(str2 + i))
            result = *(unsigned char *)(str1 + i) - *(unsigned char *)(str2 +
i);
    }

    return result;
}

сравнивает не более первых n символов строк str1 и str2. Если n равно 0, функция
считает строки равными. В противном случае, она сравнивает строки посимвольно до
n или до конца одной из строк. Если строки отличаются, функция вычисляет разницу
между символами и возвращает результат.

*/

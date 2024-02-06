#include "s21_string.h"

// Сравнивает первые n байтов str1 и str2.
// @gylberdo
int s21_memcmp(const void* str1, const void* str2, size_t n) {
  char* temp1 = (char*)str1;
  char* temp2 = (char*)str2;
  int num = 0;
  for (size_t i = 0; i < n; i++) {
    if (temp1[i] != temp2[i]) {
      num = (int)temp1[i] - (int)temp2[i];
      break;
    }
  }
  return num;
}

/*
    const unsigned char *s1 = str1;
    const unsigned char *s2 = str2;

    for (size_t i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }

    return 0;
}

*/
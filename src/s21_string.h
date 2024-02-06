#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0

size_t s21_strlen(const char *str);

int main();
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memchr(const void *str, int c, size_t count);
void *s21_memcpy(void *dest, const void *src, size_t n);

#endif
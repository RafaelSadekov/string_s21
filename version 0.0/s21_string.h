#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
typedef long unsigned s21_size_t;
void *add_memory(char **str, size_t n);

int main();
/* Функции копирования */
void *s21_memcpy(void *dest, const void *src, size_t n);
// 3 Скопировать блок данных из памяти.
// memmove	Переместить блок данных в память.
// strcpy	Скопировать строку.
char *s21_strncpy(char *dest, const char *src, size_t n);
// 8 strncpy	Скопировать n символов строки.

/*  Функции объединения (конкатенации) */
// strcat	Объединение строк.
char *s21_strncat(char *dest, const char *src, size_t n);
// 5 strncat	Добавление n символов к строке.

/* Функции отношения (сравнения) */
int s21_memcmp(const void *str1, const void *str2, size_t n);
// 2 Сравнение двух блоков памяти.
// strcmp	Сравнение двух строк
// strcoll	Сравнение двух строк по категориям.
int s21_strncmp(const char *str1, const char *str2, size_t n);
// 7 Сравнивает не более первых n байтов str1 и str2.
//  strxfrm	Преобразование строки, с учетом локали.

/* Функции поиска */
void *s21_memchr(const void *str, int c, size_t count);
// 1 Поиск символа в блоке памяти
char *s21_strchr(const char *str, int c);
// 6 strchr	Найти первое вхождение символа в строке.
size_t s21_strcspn(const char *str1, const char *str2);
// 9 strcspn	Выполняет поиск первого вхождения в строку str1 любого из
// символов строки str2, и возвращает количество символов до найденного первого
// вхождения.
char *s21_strpbrk(const char *str1, const char *str2);
// 12 strpbrk	Выполняет поиск первого вхождения в строку str1
// любого из символов строки str2, и возвращает указатель на  найденный символ.
char *s21_strrchr(const char *str, int c);
// 13 strrchr	Поиск последнего вхождения указанного символа.
// strspn	Поиск символов строки str2 в строке str1. Возвращает длину
// начального участка строки str1, который состоит только из символов строки
// str2.
char *s21_strstr(const char *haystack, const char *needle);
// 14 strstr	 Функция ищет первое вхождение подстроки str2 в строке str1.
char *s21_strtok(char *str, const char *delim);
// 15 strtok	Поиск лексем в строке, используя разделители.

/* Другие */
void *s21_memset(void *str, int c, size_t n);
// 4 Заполнить n байтов блока памяти указанным символом.
char *S21_strerror(int errnum);
// 10 Интерпретация кодов ошибок в понятные сообщения об ошибках
size_t s21_strlen(const char *str);
// 11 Вычисляет длину строки str, не включая завершающий нулевой символ.

#endif
#include "s21_string.h"

//определяет длину начального сегмента строки s1, содержащего те символы, которые не входят в строку s2
size_t s21_strcspn(const char *str1, const char *str2){
    size_t i, count = s21_strlen(str1);
    for(i = 0; i < count; i++){
        if(s21_strchr(str2,str1[i]) != NULL){
            break;
        }
    }
    return i;
}

/*
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  for (; *str1 && !s21_strchr(str2, *str1); str1++, count++)
    ;
  return count;
}
*/
/*
size_t
  31 STRCSPN (const char *str, const char *reject)
  32 {
  33   if (__glibc_unlikely (reject[0] == '\0')
  34       || __glibc_unlikely (reject[1] == '\0'))
  35     return __strchrnul (str, reject [0]) - str;
  36 
  37   //Use multiple small memsets to enable inlining on most targets.  
  38   unsigned char table[256];
  39   unsigned char *p = memset (table, 0, 64);
  40   memset (p + 64, 0, 64);
  41   memset (p + 128, 0, 64);
  42   memset (p + 192, 0, 64);
  43 
  44   unsigned char *s = (unsigned char*) reject;
  45   unsigned char tmp;
  46   do
  47     p[tmp = *s++] = 1;
  48   while (tmp);
  49 
  50   s = (unsigned char*) str;
  51   if (p[s[0]]) return 0;
  52   if (p[s[1]]) return 1;
  53   if (p[s[2]]) return 2;
  54   if (p[s[3]]) return 3;
  55 
  56   s = (unsigned char *) PTR_ALIGN_DOWN (s, 4);
  57 
  58   unsigned int c0, c1, c2, c3;
  59   do
  60     {
  61       s += 4;
  62       c0 = p[s[0]];
  63       c1 = p[s[1]];
  64       c2 = p[s[2]];
  65       c3 = p[s[3]];
  66     }
  67   while ((c0 | c1 | c2 | c3) == 0);
  68 
  69   size_t count = s - (unsigned char *) str;
  70   return (c0 | c1) != 0 ? count - c0 + 1 : count - c2 + 3;
  71 }

*/
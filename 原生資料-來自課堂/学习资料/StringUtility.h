#pragma once
#include<stdio.h>
#include<string.h>
#include<malloc.h>

int contains(char *str1, char *str2);
//动态分配，使用结束使用free函数释放空间,例如
//char *p = subString(str,0,2);
//free(p);
char* subString(char *str, int posLow, int posHig);
//这个就是在原数组部分改，不需要释放空间
void subStringLocal(char *str, int posLow, int posHig);
int equals(char *str1, char *str2);
int isEmpty(char *str);
//动态分配，使用结束使用free函数释放空间,例如
//char **p = split(str,'&');
//输出printf("%s",p[0]);
//释放free(p[i])
char** split(char *str,char spChar);


/*
string.h库中有这些常用的：
int strlen(const char * s);   返回字符串s中的字符数（末尾的空字符除外）
char *strstr(const char *s1, const char *s2);    返回一个指针，指向s1中首次出现s2中字符序列（不包括结束的空字符）的位置。如果未找到，函数返回NULL
char *strncat(char *restrict s1, const char * restrict s2, size_t n);    把s2指向字符串的n个字符拷贝到s1指向的字符串后面（或拷贝到s1的空字符为止）。s2字符串的第一个字符覆盖s1字符串的空字符。函数返回s1
void *memchr(const void *s, int c, size_t n);   在s指向对象的前n个字符中查找是否有c。如果找到，则返回首次出现c处的指针，如果未找到则返回NULL
*/
#pragma once
#include<stdio.h>
#include<string.h>
#include<malloc.h>

int contains(char *str1, char *str2);
//��̬���䣬ʹ�ý���ʹ��free�����ͷſռ�,����
//char *p = subString(str,0,2);
//free(p);
char* subString(char *str, int posLow, int posHig);
//���������ԭ���鲿�ָģ�����Ҫ�ͷſռ�
void subStringLocal(char *str, int posLow, int posHig);
int equals(char *str1, char *str2);
int isEmpty(char *str);
//��̬���䣬ʹ�ý���ʹ��free�����ͷſռ�,����
//char **p = split(str,'&');
//���printf("%s",p[0]);
//�ͷ�free(p[i])
char** split(char *str,char spChar);


/*
string.h��������Щ���õģ�
int strlen(const char * s);   �����ַ���s�е��ַ�����ĩβ�Ŀ��ַ����⣩
char *strstr(const char *s1, const char *s2);    ����һ��ָ�룬ָ��s1���״γ���s2���ַ����У������������Ŀ��ַ�����λ�á����δ�ҵ�����������NULL
char *strncat(char *restrict s1, const char * restrict s2, size_t n);    ��s2ָ���ַ�����n���ַ�������s1ָ����ַ������棨�򿽱���s1�Ŀ��ַ�Ϊֹ����s2�ַ����ĵ�һ���ַ�����s1�ַ����Ŀ��ַ�����������s1
void *memchr(const void *s, int c, size_t n);   ��sָ������ǰn���ַ��в����Ƿ���c������ҵ����򷵻��״γ���c����ָ�룬���δ�ҵ��򷵻�NULL
*/
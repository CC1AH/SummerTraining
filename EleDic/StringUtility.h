#ifndef STRINGUTILITY_H_INCLUDED
#define STRINGUTILITY_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<malloc.h>

/**
* 该文件描述了电子辞典的一个实用工具模块（字符串的包含，截取，相等，为空，分割的判断）
* @author 贾聪（本组成员）
* 2019/7/20
* copyright reserved
*/

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

//包含函数原型的基本内容
int contains(char *str1, char *str2) {
	char *p;
	p = strstr(str1, str2);

	if (p == NULL)
		return 0;
	else
		return 1;
}


char* subString(char *str, int posLow, int posHig) {
	int len = strlen(str),y=0;
	if (posLow > posHig || posHig > len)
		return NULL;

	char *sub = (char*)malloc(sizeof(char)*(posHig - posLow + 2));
	memset(sub, '\0', sizeof(char)*(posHig - posLow + 2));

	int i;
	for (i = posLow; i <= posHig; i++,y++) {
		*(sub + y) = *(str + i);
	}
	*(sub + y) = '\0';
	return sub;
}


void subStringLocal(char *str, int posLow, int posHig) {
	int y = 0;
	int i;
	for (i = posLow; i < posHig; i++,y++) {
		str[y] = str[i];
	}
	str[y] = '\0';
}

int equals(char *str1, char *str2) {
	int res = strcmp(str1, str2);
	if (res == 0)
		return 1;
	else
		return 0;
}

int isEmpty(char *str) {
	int len = strlen(str);
	if (len == 0)
		return 1;
	else
		return 0;
}

char** split(char *str,char spChar) {
	int row=0,y=0,ii=0;

	int i;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == spChar) {
			row++;
		}
	}
	row++;
	char **res = (char **)malloc(sizeof(char)*row);
	int *each = (int *)malloc(sizeof(int)*row);
	for (i = 0; i < row; i++) {
		each[i] = 0;
	}

	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '\0' || str[i] == spChar) {
			res[y] = (char*)malloc(sizeof(char)*(each[y] + 1));
			y++;
		}
		else
		{
			each[y]++;
		}
	}
	res[y] = (char*)malloc(sizeof(char)*(each[y] + 1));

	y = 0;
	ii = 0;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == '\0' || str[i] == spChar) {
			res[y][ii] = '\0';
			y++;
			ii = 0;
		}
		else
		{
			res[y][ii] = str[i];
			ii++;
		}
	}
	res[y][ii] = '\0';

	return res;
}



#endif // STRINGUTILITY_H_INCLUDED

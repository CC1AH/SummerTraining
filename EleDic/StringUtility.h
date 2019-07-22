#ifndef STRINGUTILITY_H_INCLUDED
#define STRINGUTILITY_H_INCLUDED
#include<stdio.h>
#include<string.h>
#include<malloc.h>

/**
* ���ļ������˵��Ӵǵ��һ��ʵ�ù���ģ�飨�ַ����İ�������ȡ����ȣ�Ϊ�գ��ָ���жϣ�
* @author �ִϣ������Ա��
* 2019/7/20
* copyright reserved
*/

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

//��������ԭ�͵Ļ�������
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

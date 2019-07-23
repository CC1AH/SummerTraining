#include<stdio.h>
#include<string.h>
#include<malloc.h>


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

	for (int i = posLow; i <= posHig; i++,y++) {
		*(sub + y) = *(str + i);
	}
	*(sub + y) = '\0';
	return sub;
}


void subStringLocal(char *str, int posLow, int posHig) {
	int y = 0;
	for (int i = posLow; i < posHig; i++,y++) {
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

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == spChar) {
			row++;
		}	
	}
	row++;
	char **res = (char **)malloc(sizeof(char)*row);
	int *each = (int *)malloc(sizeof(int)*row);
	for (int i = 0; i < row; i++) {
		each[i] = 0;
	}

	for (int i = 0; i < strlen(str); i++) {
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
	for (int i = 0; i < strlen(str); i++) {
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

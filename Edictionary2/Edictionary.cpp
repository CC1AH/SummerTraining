#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"Edhead.h"


int main()
{
	printf("Ӧ�ó���������.(����װ��)");
	Sleep(500); 
	system("cls");
	printf("Ӧ�ó���������..(����װ��)");
	Sleep(500);  
	system("cls");
	printf("Ӧ�ó���������...(����װ��)"); 
	Sleep(500); 
	
	wordsNumber = loadSql(dicSql,"dictionary.txt");
	int action =-1; //���嶯������ 
	printf("s");
	while(action!=11)
	{
		action =printAction();
		dealAction(action);
	}
	return 0;
}
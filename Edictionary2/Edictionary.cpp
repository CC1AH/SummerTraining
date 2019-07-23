#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"Edhead.h"


int main()
{
	printf("应用程序启动中.(纯属装比)");
	Sleep(500); 
	system("cls");
	printf("应用程序启动中..(纯属装比)");
	Sleep(500);  
	system("cls");
	printf("应用程序启动中...(纯属装比)"); 
	Sleep(500); 
	
	wordsNumber = loadSql(dicSql,"dictionary.txt");
	int action =-1; //定义动作变量 
	printf("s");
	while(action!=11)
	{
		action =printAction();
		dealAction(action);
	}
	return 0;
}
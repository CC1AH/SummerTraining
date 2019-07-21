#ifndef BASICINPUT_H_INCLUDED
#define BASICINPUT_H_INCLUDED
#include "WordOperate.h"
/**
* @author 邢国浩
* 2019/7/21
* 定义用户界面的进入和选择
* 定义辞典文件的初始化
*/

int choseMenu();
void initial(nodeptr);

//使用choseMenu函数定义用户界面的进入和基本操作 返回用户的选择
int choseMenu(){

    printf("\n\n\n                        欢迎-----^-^-----------^-^------------^-^-----欢迎\n");
	printf("                            ____________________________________________________\n");
	printf("                        |------------------(0)英译汉搜索-----------------------|\n");
	printf("                        |------------------(1)汉译英搜索-----------------------|\n");
	printf("                        |------------------(2)增加单词-------------------------|\n");
	printf("                        |------------------(3)删除单词-------------------------|\n");
	printf("                        |------------------(4)修改释义-------------------------|\n");
	printf("                        |------------------(5)收藏夹---------------------------|\n");
	printf("                        |------------------(6)听写-----------------------------|\n");
	printf("                        |__________________________________________________|\n");
	printf("\n");

	int choose;
	//清除缓冲区
	fflush(stdin);
	//接收用户的选择
	printf("请根据需求输入数字(0-6)：");

	//当用户的选择在0-1之外的范围则提示用户输入错误，请重新输入
	while((scanf("%d", &choose)!=1) || (choose<0||choose>6))
	{
		printf("输入错误，请重新输入(0-1)：");
		//清除缓冲区
		fflush(stdin);
	}
    return choose;
}

void initial(nodeptr list){
    //创建链表结构体辅助词条数据的读取的功能
	nodeptr add;
	//释放已创建链表
	FreeList(list);
	//重新创建链表结构体
	list=(struct listNode *)malloc(sizeof(struct listNode));
	if(list!=NULL)
	{
		//把list的下一个结点指向NULL
		list->next=NULL;
	}

	//定义一个整形作为统计词条数量
	int num;
	//初始化统计数据为0
	num=0;
	//自定义readFile以读取的方式打开dictionary.txt
	FILE *readFile = fopen("dictionary.txt","r");
	//当readFile创建不成功，即不存在dictionary.txt文件
	if(readFile==NULL)
    {
        printf("辞典文件打开失败\n");
        return;
    }
	else
	{
		//当读取文件不为文件结束符
		while(!feof(readFile))
		{
			//创建链表结构体辅助数据的读取功能
			add=(struct listNode *)malloc(sizeof(struct listNode));
			if(add!=NULL)
			{
				//num统计文件所传值到add的数据个数
				num=fscanf(readFile,"%10s %10s %10s\n",(add->data).word,(add->data).mean,(add->data).format);
				//当传值到add的数据个数小于3则跳出循环
				if(num<3)
				{
					break;
				}
				//英文单词首字母按字母表的顺序把add的数据插入到list中
				InsertList(list,add);
			}
		}
		//打印读取成功
		printf("dictionary.txt中的所有词条已保存在字典中");
	}
}

#endif // BASICINPUT_H_INCLUDED

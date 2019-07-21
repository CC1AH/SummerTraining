#include <stdio.h>
#include <stdlib.h>
//单词长度（词性长度）和中文释义长度的最大值
#define WORDNUM 30
#define MEANNUM 30

//数据内容
struct content
{
    //设置英文单词长度
    char word[WORDNUM+1];
    //设置中文释义长度
    char mean[MEANNUM+1];
    //设置单词词性长度
    char format[WORDNUM+1];
};

//链表
struct listNode
{
    //数据域，存放数据
    struct content data;
    //指向下一个链表节点
    struct listNode *next;
};

typedef struct listNode node;
typedef struct listNode* nodeptr;

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

int main(){
    int choose = choseMenu();
    switch(choose){
    case 0:
        syst
    }
}

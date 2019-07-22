#ifndef OTHEROPERATION_H_INCLUDED
#define OTHEROPERATION_H_INCLUDED
#include <time.h>
#include "BasicStructrue.h"
#include "BasicFunctions.h"
#include "WordOperation.h"
/**
* 该文件描述了电子辞典的额外功能模块（听写和收藏夹）
* @author 邢国浩
* 2019/7/22
* copyright reserved
*/

//包含的函数原型
void dictation(int choose,nodeptr list);
int executeDictation(nodeptr list,int n);//"听写"的子功能函数 执行
void saveDictationInfo(int dicWordNum,int wrongNum);//"听写"的子功能函数 保存
void getCurrentTime(char info[]);//"听写"的子功能函数”保存“的子功能函数 获取当前日期时间

void collections(nodeptr list);
nodeptr initialCollections(nodeptr list);//"收藏夹"的子功能函数,读取collections.txt初始化到以list为头的指针
void readToCollections(nodeptr list);//"收藏夹"的子功能函数,读取以list为头的指针初始化到collections.txt


//包含函数原型的基本内容
/**
* 听写
* 可以从list为头的链表中随机选出用户指定的
* 单词个数进行听写,并报告听写的个数。
* 建立一个文件记录听写的总次数并显示
* list可以是主分支或者是收藏夹指针
* @param choose:int list:nodeptr
*/
void dictation(int choose,nodeptr list){
	if(choose == 3){
        FILE* file;
        if((file = fopen("dictationInfo.txt","r"))==NULL){
            printf("听写文件打开失败\n");
            return;
        }
        while(!feof(file)){
            char tmp[80];
            fgets(tmp,80,file);
            puts(tmp);
        }
        return;
	}

    while(choose!=1&&choose!=2){
        printf("没有这个选择，请重新输入选择：");
        scanf("%d",&choose);
    }

    int dicWordNum;
    fflush(stdin);
    printf("请输入你想要听写的单词的个数，并确保这个数字小于你所选择的文件的总单词个数\n");
    scanf("%d",&dicWordNum);
    int wrongNum = executeDictation(list,dicWordNum);
    saveDictationInfo(dicWordNum,wrongNum);
}

/*
"听写"的子功能函数 执行
用于抽取n个单词进行听写 返回错误个数
*/
int executeDictation(nodeptr list,int n){
    //统计链表总节点个数；
    nodeptr tmp = list->next;
    int count = 0;
    while(tmp!=NULL){
        (tmp->data).isDictated = 0;
        tmp = tmp->next;
        count++;
    }
    printf("即将在%d个单词中抽取%d个发起听写\n",count,n);

    //随机生成n个不同的单词并统计错误个数
    int wrongNum = 0;
    int i;
    for(i=0;i<n;++i){
        srand(time(NULL));
        int num = rand()%count+1;
        int j;
        tmp = list;
        for(j=0;j<num;++j){
            tmp = tmp->next;
        }

        //如果已经被听写过，重新选一个
        if((tmp->data).isDictated){
            i--;
            break;
        }

        //否则开启听写
        else{
        (tmp->data).isDictated = 1;
        fflush(stdin);
        printf("\n单词%d :请输入\"%s\"释义对应的单词\n",i+1,(tmp->data).mean);
        char inputWord[WORDNUM+1];
        scanf("%s",inputWord);
        if(strcmp(inputWord,(tmp->data).word)==0){
            printf("单词书写正确\n");
        }
        else{
            printf("单词书写错误,正确的单词应该是：%s\n",(tmp->data).word);
            wrongNum++;
        }
    }
    }
    printf("\n单词听写完毕，错误个数为%d个\n",wrongNum);
    return wrongNum;
}

/*
"听写"的子功能函数 保存
*将听写日期 听写个数 错误个数保存到dictation.txt文件夹中
*/
void saveDictationInfo(int dicWordNum,int wrongNum){
    FILE* file;
    if((file = fopen("dictationInfo.txt","a+"))==NULL){
        printf("听写文件打开失败\n");
        return;
    }

    char info[200];
    getCurrentTime(info);
    fprintf(file,"\n在%s:共听写了%d个单词，错误个数是%d个",info,dicWordNum,wrongNum);
    printf("  听写信息保存完毕");
    fclose(file);//必须要有 没有就不保存
}

/*
*"听写"的子功能函数”保存“的子功能函数 获取当前日期时间
*获取年份 月份 日期 小时 分钟并保存在一个字符串里
*/
void getCurrentTime(char info[]){
    time_t t;
    struct tm* lt;
    time(&t);
    lt = localtime(&t);

    sprintf(info,"%d年%d月%d日_%d时%d分",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min);
    printf(info);
}


/**
* 收藏夹
* 将list为头的指针初始化collections.txt的文件内容
* 并提供删除，增加，修改操作，操作将在文件中被反映
* @param list:nodeptr
*/
void collections(nodeptr list){
    list = initialCollections(list);
    printf("\n\n\n\t\t\t\t   欢迎-----^-^------收藏夹----^-^-----欢迎\n");
	printf("                        ____________________________________________________________\n");
	printf("                        |------------------(0)列出收藏夹内容-----------------------|\n");
	printf("                        |------------------(1)清空全部收藏-------------------------|\n");
	printf("                        |------------------(2)增加收藏夹单词-----------------------|\n");
	printf("                        |------------------(3)删除收藏夹单词-----------------------|\n");
	printf("                        |------------------(4)修改收藏夹单词释义-------------------|\n");
	printf("                        |__________________________________________________________|\n");
	int choose;
	fflush(stdin);
	printf("请根据需求输入数字(0-4)：");

	//当用户的选择在0-4之外的范围则提示用户输入错误，请重新输入
	while((scanf("%d", &choose)!=1) || (choose<0||choose>8))
	{
		printf("输入错误，请重新输入(0-4)：");
		fflush(stdin);
	}

	switch(choose){
    case 0:
        listAll(list);
        break;
    case 1:
        list = NULL;
        initialCollections(list);
        FILE *readFile = fopen("collections.txt","w");
        if(readFile==NULL)
        {
            printf("收藏夹文件打开失败\n");
            return;
        }
        fprintf(readFile,"");
        puts("收藏夹文件已经是空的了");
        break;
    case 2:
        addWord(list);
        readToCollections(list);
        break;
    case 3:
        deleteWord(list);
        readToCollections(list);
        break;
    case 4:
        modifyWord(list);
        readToCollections(list);
        break;
	}
}
/*
*"收藏夹"的子功能函数
*读取collections.txt初始化到以list为头的指针链表
*/
nodeptr initialCollections(nodeptr list){
    nodeptr add;
	list=(struct listNode *)malloc(sizeof(struct listNode));
	if(list!=NULL)
	{
		list->next=NULL;
	}

	//统计词条数量
	int num=0;

	FILE *readFile = fopen("collections.txt","r");
	if(readFile==NULL)
    {
        printf("收藏夹文件打开失败\n");
        return list;
    }
	else
	{
	    printf("-----------收藏夹启动中----------");
		while(!feof(readFile))
		{
			add=(struct listNode *)malloc(sizeof(struct listNode));
			if(add!=NULL)
			{
				num=fscanf(readFile,"%s\t%s\n",(add->data).word,(add->data).mean);
				//当传值到add的数据个数小于2则跳出循环
				if(num<2)
				{
				    printf("\n词数读入错误\n");
					break;
				}
				//英文单词首字母按字母表的顺序把add的数据插入到list中
				InsertList(list,add);
			}
		}
		printf("\n收藏夹加载已完成\n");
	}
	return list;
}
void readToCollections(nodeptr list){
    nodeptr tmp = list;
	FILE *writeFile = fopen("collections.txt","w");
	if(writeFile==NULL)
    {
        printf("收藏夹文件打开失败\n");
        return;
    }
	else
	{
	    printf("-----------收藏夹更新中----------");
		while(tmp!=NULL)
		{
            fprintf(writeFile,"%s\t%s\n",(tmp->data).word,(tmp->data).mean);
			tmp = tmp->next;
		}
		printf("\n收藏夹更新已完成\n");
	}
	fclose(writeFile);
}
#endif // OTHEROPERATION_H_INCLUDED

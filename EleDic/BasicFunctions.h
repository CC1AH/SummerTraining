#ifndef BASICFUNCTIONS_H_INCLUDED
#define BASICFUNCTIONS_H_INCLUDED
/**
* 该文件描述了电子辞典的基本功能模块（初始化，菜单，全部列表，中英文搜索）
* @author 邢国浩
* 2019/7/21
* copyright reserved
*/

//包含的函数原型
nodeptr initial(nodeptr list);
int choseMenu();
void listAll(nodeptr list);

void searchInEnglish(nodeptr list);
void searchInChinese(nodeptr list);



//包含函数原型的基本内容
/**
* 初始化
* 以接受的指针为头建立一个单词链表
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr initial(nodeptr list){
	nodeptr add;
	list=(struct listNode *)malloc(sizeof(struct listNode));
	if(list!=NULL)
	{
		list->next=NULL;
	}

	//统计词条数量
	int num=0;

	FILE *readFile = fopen("dictionary.txt","r");
	if(readFile==NULL)
    {
        printf("辞典文件打开失败\n");
        return list;
    }
	else
	{
	    printf("-----------应用程序启动中----------");
		while(!feof(readFile))
		{
			add=(struct listNode *)malloc(sizeof(struct listNode));
			if(add!=NULL)
			{
				num=fscanf(readFile,"%s\t%s\n",(add->data).word,(add->data).mean);
				//当传值到add的数据个数小于2则跳出循环
				if(num<2)
				{
				    printf("词数读入错误");
					break;
				}
				//英文单词首字母按字母表的顺序把add的数据插入到list中
				InsertList(list,add);
			}
		}
		printf("\n字典加载已完成");
	}
	return list;
}

/**
* 选择菜单
* 展示菜单，接受用户的选择并且返回选择
* @return int
*/
int choseMenu(){

    printf("\n\n\n                      欢迎-----^-^-----------^-^------------^-^-----欢迎\n");
	printf("                           ____________________________________________________\n");
	printf("                        |------------------(0)英译汉搜索-----------------------|\n");
	printf("                        |------------------(1)汉译英搜索-----------------------|\n");
	printf("                        |------------------(2)增加单词-------------------------|\n");
	printf("                        |------------------(3)删除单词-------------------------|\n");
	printf("                        |------------------(4)修改释义-------------------------|\n");
	printf("                        |------------------(5)收藏夹---------------------------|\n");
	printf("                        |------------------(6)听写-----------------------------|\n");
	printf("                        |------------------(7)列出词库中全部单词及其释义-------|\n");
	printf("                        |------------------(8)退出程序-------------------------|\n");
	printf("                        |__________________________________________________|\n");
	printf("\n");

	int choose;
	fflush(stdin);
	printf("请根据需求输入数字(0-8)：");

	//当用户的选择在0-1之外的范围则提示用户输入错误，请重新输入
	while((scanf("%d", &choose)!=1) || (choose<0||choose>8))
	{
		printf("输入错误，请重新输入(0-8)：");
		fflush(stdin);
	}
    return choose;
}

/**
* 列出全部
* 列出list为头链表下的全部单词信息
* @param list:nodeptr
*/
void listAll(nodeptr list){
    nodeptr tmp = list->next;
    while(tmp!=NULL){
        printf("%s %s\n",(tmp->data).word,(tmp->data).mean);
        tmp = tmp->next;
    }
}

/**
* 英文搜索
* 在list为头链表下搜索所有单词开头包含给定输入关键字的单词及释义
* @param list:nodeptr
*/
void searchInEnglish(nodeptr list)
{
	nodeptr listNext;
	//接收用户输入的英文字符（串）
	char input[WORDNUM+1];
	//接收用户输入的英文字符（串）的长度
	int inputLen = 0;
	//接收英文单词与用户输入的字符（串）的匹配个数
	int matchNum = 0;

	listNext=list->next;

	fflush(stdin);
	printf("请输入英文单词的关键词：");
	scanf("%s", &input);

	//接收用户输入英文单词的关键词的长度
	inputLen=strlen(input);

	printf("|-------------------搜索结果如下-------------------|\n");
	printf("%10s %10s\n","英文单词","中文解释");

	while(listNext!=NULL)
	{
		matchNum=memcmp((listNext->data).word,input,inputLen);
		if(matchNum==0)
		{
		    printf("%10s %10s\n",(listNext->data).word,(listNext->data).mean);

		}
		listNext=listNext->next;
	}
}

/**
* 中文搜索
* 在list为头链表下搜索所有释义包含给定输入关键字的单词及释义
* @param list:nodeptr
*/
void searchInChinese(nodeptr list){
	nodeptr listNext;
	//接收用户输入的中文字符（串）
	char input[WORDNUM+1];
	//标记是否找到了对应项目
    int count = 0;

	listNext=list->next;

	fflush(stdin);
	printf("请输入中文单词的关键词：");
	scanf("%s", &input);

	printf("|-------------------搜索结果如下-------------------|\n");
	printf("%10s %10s\n","英文单词","中文解释");

	while(listNext!=NULL)
	{
		if(contains((listNext->data).mean,input)){
            printf("%10s %10s\n",(listNext->data).word,(listNext->data).mean);
            count++;
		}
        listNext=listNext->next;
	}
	if(count == 0){
        printf("么有找到你想要找的单词");
	}
}
#endif // BASICFUNCTIONS_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int wordsNumber =0;//单词总数目 

typedef struct dictionary
{
	char word[20];
	char cn[80];
}data;

data dicSql[8000];//单词库 
int loadSql(data *sql,char path[100]);/*加载单词库数据*/
int printAction();/*输出用户提示函数*/
void dealAction(int action);/*定义指令处理函数*/
void dictation();/*听写单词函数*/
int searchWord(char word[20]);/*返回单词在单词库中的位置*/
void searchCn(char cn[80]);/*返回中文翻译在单词库中的位置*/
void saveSql();/*保存文件函数*/
void wordsBook();


/*主函数*/
int main()
{
	srand(time(NULL));
	wordsNumber = loadSql(dicSql,"dictionary.txt");
	int action =-1; //定义动作变量 
	
	while(action!=9)
	{
		action =printAction();
		dealAction(action);
	}
	return 0;
}

/*加载单词库数据*/
int loadSql(data *sql,char path[100])
{
	int i =0;
	for(i =0;i<1;i++)
	{
		printf("应用程序启动中.(纯属装比)");
		Sleep(500); 
		system("cls");
		printf("应用程序启动中..(纯属装比)");
		Sleep(500);  
		system("cls");
		printf("应用程序启动中...(纯属装比)"); 
		Sleep(500); 
	}
	i =0;
	FILE *fp =NULL;
	if((fp = fopen(path,"r"))==NULL)
	{
		printf("文件读取失败！\n");
		return 0;
	}
	while(fscanf(fp,"%s\t%s",(sql+i)->word,(sql+i)->cn)!=EOF)
	{
		i++;
	}
	fclose(fp);
	printf("\n"); 
	return i;
}

/*输出用户提示函数*/
int printAction()
{
	int n =0;
	system("cls");
	printf("              电子英汉词典设计\n\n");
	printf("菜单：\n"); 
	printf("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("   |            1、英译汉              |\n"); 
	printf("   *            2、汉译英              *\n");
	printf("   |            3、单词本              |\n");
	printf("   *            4、词条录入            *\n"); 
	printf("   |            5、词条修改            |\n");
	printf("   *            6、词条删除            *\n"); 
	printf("   |            7、听写单词            |\n");
	printf("   *            8、信息保存            *\n");
	printf("   |            9、退出系统            |\n"); 
	printf("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("请输入指令进行操作：");
	scanf("%d",&n);
	printf("\n"); 
	return n;
}

/*定义指令处理函数*/
void dealAction(int action)
{
	switch(action)
	{
		int pos;//单词位置 
		char word[20];
		char cn[80];
		case 1:
			printf("请输入您要查询的单词：");
			scanf("%s",word);
			printf("\n"); 
			pos = searchWord(word);
			if(pos!=-1)
			{
				printf("单词\'%s\'的意思是：%s\n",word,dicSql[pos].cn);
				printf("\n"); 
				system("pause");
			} 
			else
			{
				printf("对不起，没有找到你所需要的单词!\n");
				printf("\n"); 
				Sleep(3500);
			}
			break;
		
		case 2:
			printf("请您输入汉语词意（关键词即可)：");
			scanf("%s",cn);
			printf("\n"); 
			searchCn(cn);
			break;
			
		case 3:
		    wordsBook();
		    break;
		
		case 4:
			printf("请您输入需要录入的单词(此处只需输入英文单词)：");
			scanf("%s",word);
			printf("\n"); 
			strcpy(dicSql[wordsNumber].word,word);
			printf("请您输入该单词的中文翻译：");	
			scanf("%s",cn);
			printf("\n"); 
			strcpy(dicSql[wordsNumber].cn,cn);
			wordsNumber++;
			saveSql(); 
			printf("补充词条完成!\n");
			printf("\n"); 
			system("pause");
			break;
		
		case 5:
			printf("请您输入需要修改的单词(此处只需输入英文单词)：");
			scanf("%s",word);
			printf("\n"); 
			pos =searchWord(word);
			if(pos!=-1)
			{
				printf("该词条现在为：%s\t%s\n\n",dicSql[pos].word,dicSql[pos].cn);
				printf("请您输入该单词新的中文翻译：");
				scanf("%s",cn);
				printf("\n"); 
				strcpy(dicSql[pos].word,word);
				strcpy(dicSql[pos].cn,cn);
				saveSql(); 
				printf("修改词条完成!\n");
				printf("\n"); 
				printf("修改后该词条为：%s\t%s\n\n",dicSql[pos].word,dicSql[pos].cn);
				system("pause");
			}
			else
			{
				printf("未找到您要修改的单词！\n");
				printf("\n"); 
				Sleep(3500);
			}
			break;
		
		case 6:
			printf("请输入您要删除的单词：");
			scanf("%s",word);
			printf("\n"); 
			pos =searchWord(word);
			if(pos!=-1)
			{
				char a[5] ="#";
				strcpy(dicSql[pos].word,a);
				strcpy(dicSql[pos].cn,a);
				saveSql();
				printf("删除成功！\n");
				printf("\n"); 
				system("pause");
			}
			else
			    printf("对不起，没有找到您所需要的单词！\n"); 
			    printf("\n"); 
			    Sleep(3500);
			break;
			
		case 7:
		    dictation();
			break; 
			    
		case 8:
			saveSql();
			printf("信息保存成功！\n");
			printf("\n"); 
			system("pause");
			break;
			
		case 9:
			printf("谢谢您的使用，再见！\n");
			break;
			
	}
} 

/*返回单词在单词库中的位置*/
int searchWord(char word[20])
{
	/*用二分法查找*/
	int low,mid,high;
	low =0;
	high = wordsNumber;
	while(low<=high)
	{
		mid =(low+high)/2;
		if(strcmp(dicSql[mid].word,word)>0)
		    high = mid-1;
		else if(strcmp(dicSql[mid].word,word)<0)
		    low = mid+1;
		else
		    return mid;
	}
	/*用顺序查找法查找*/ 
	int i=0;
    for(i=0;i<wordsNumber;i++)
    {
        if(strcmp(dicSql[i].word,word)==0)
            return i;
    }
    return -1;//如果找不到就返回-1 
} 

/*查找中文翻译对应的英文单词*/
void searchCn(char cn[80])
{
	//用顺序查找法
	int i =0,judge =-1;
	for(;i<wordsNumber;i++)
	{
		if(strstr(dicSql[i].cn,cn)!=NULL){
			printf("%s\t%s\n",dicSql[i].word,dicSql[i].cn);
			judge =1;
		}	    
	}
	printf("\n");
	system("pause"); 
	if(judge==-1)
	{
		printf("对不起，未找到该中文对应的单词！\n\n");
	    Sleep(2500);
	} 
}

/*单词听写函数*/ 
void dictation()
{
	system("cls");
	int interval,i,randnum,numOfWords,judge;
	printf("请设置听写单词个数："); 
	scanf("%d",&numOfWords); 
	printf("请设置间隔秒数：");
	scanf("%d",&interval); 
	interval *=1000;
	printf("请选择听写类型（1->汉英听写  2->英汉听写):");
	scanf("%d",&judge);
	printf("\n");
	char *word[numOfWords];
	char *cn[numOfWords];
	switch(judge)
	{
		case 1:
			for(i=0;i<numOfWords;i++)
	        {
		        randnum = rand()%wordsNumber+1;
		        printf("Number %d:   %s\n",i+1,dicSql[randnum].cn);
		        word[i] = dicSql[randnum].word;
		        cn[i] = dicSql[randnum].cn;
		        Sleep(interval);
	        }
	        printf("\n听写结束！答案如下：\n");
	        for(i=0;i<numOfWords;i++)
	        {
		        printf("Number %d:   %s\t%s\n",i+1,word[i],cn[i]);
	        } 
	        printf("\n");
	        system("pause");
	        printf("\n");
	        break;
	        
	    case 2:
	    	for(i=0;i<numOfWords;i++)
	        {
		        randnum = rand()%wordsNumber+1;
		        printf("Number %d:   %s\n",i+1,dicSql[randnum].word);
		        word[i] = dicSql[randnum].word;
		        cn[i] = dicSql[randnum].cn;
		        Sleep(interval);
	        }
	        printf("\n听写结束！答案如下：\n");
	        for(i=0;i<numOfWords;i++)
	        {
		        printf("Number %d:   %s\t%s\n",i+1,word[i],cn[i]);
	        } 
	        printf("\n");
	        system("pause");
	        printf("\n");
	        break;
	}
}

/*保存文件函数*/
void saveSql()
{
	int i =0;
	FILE *fp =NULL;
	if((fp =fopen("dictionary.txt","w"))==NULL)
	{
		printf("文件保存失败！\n");
		printf("\n"); 
	}
	else
	{
	    for(;i<wordsNumber;i++)
	    {
		    if(strcmp(dicSql[i].word,"#")!=0)
		    {
			    fprintf(fp,"%s\t%s\n",dicSql[i].word,dicSql[i].cn);
		    }
	    }   
	}
	fclose(fp);
}

/*单词本函数*/
void wordsBook()
{
	data wordsBook[500];
	int i =0,numOfWords,judge =-1;
	char word[20];
	FILE *wf1 =NULL;
	FILE *wf =NULL;
	if((wf1 =fopen("wordsBook.txt","r"))==NULL)
	{
		printf("单词本打开失败！\n\n");
		system("pause");
	}
	else
	{
		//从单词本文件中读取单词 并存放在结构体数组中 
		while(fscanf(wf1,"%s\t%s",wordsBook[i].word,wordsBook[i].cn)!=EOF)
	    {
	        i++;
	    }
	    numOfWords = i;
	    fclose(wf1);
	}
	if((wf =fopen("wordsBook.txt","w"))==NULL)
	{
		printf("单词本打开失败！\n\n");
		system("pause");
	}
	else{
		printf("1、打开单词本\n");
		printf("2、添加新单词\n");
		printf("3、删除单词\n");
		printf("请输入序号进行操作：");
		int n;
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\n单词本内容如下：\n"); 
			    for(i =0;i<numOfWords;i++)
			    {
				    printf("%s\t%s\n",wordsBook[i].word,wordsBook[i].cn);
			    }
			    for(i =0;i<numOfWords;i++)
			    {
					fprintf(wf,"%s\t%s\n",wordsBook[i].word,wordsBook[i].cn);	
				}
				printf("\n");
				system("pause");
				break;
			
			case 2:
			    printf("\n请输入要添加的英文单词：");
			    scanf("%s",&wordsBook[numOfWords].word);
			    printf("请输入该单词的中文翻译：");
			    scanf("%s",&wordsBook[numOfWords].cn);
			    printf("\n");
			    numOfWords++;
			    for(i =0;i<numOfWords;i++)
			    {
					fprintf(wf,"%s\t%s\n",wordsBook[i].word,wordsBook[i].cn);	
				}
			    printf("添加成功！");
			    printf("\n");
			    system("pause");
			    break;
			    
			case 3:
				judge =1;//用于判断单词本中是否有用户输入的单词 
				printf("\n请输入您要删除的单词：");
				scanf("%s",word);
				printf("\n"); 
				for(i =0;i<numOfWords;i++)
				{
					if(strcmp(wordsBook[i].word,word)==0)
					{
						char a[5] ="#";
						strcpy(wordsBook[i].word,a);
						judge =0;//如果单词本中有用户需要删除的单词，则改变judge的值 	
					}
				}
				for(i =0;i<numOfWords;i++)
	            {
		            if(strcmp(wordsBook[i].word,"#")!=0)
		            {
			            fprintf(wf,"%s\t%s\n",wordsBook[i].word,wordsBook[i].cn);
		            }
	            }
				
				if(judge)
			    	printf("对不起，没有找到您所需要的单词！\n\n");
				else
				    printf("删除成功！\n\n");
			    
			    system("pause");
				break;
		}
	} 
	fclose(wf);
} 

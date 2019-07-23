#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct dict
{
    char en[40];
    char cn[80];
};
struct dict dictionary[20000];

void save(int sum)
{
    FILE *fp=NULL;
    fp=fopen("dictionary1.txt","w");
    int i=0;
    for(i=0;i<sum;i++)
    {
        if(dictionary[i].en[0]!=EOF)
        {
            fprintf(fp,"%s\t%s\n",dictionary[i].en,dictionary[i].cn);
        }
    }
    fclose(fp);
}

int search(char word[50],int sum)
{
    int low, mid, high;
    low = 0;
    high = sum;
    while(low<=high)
    {
        mid = (low+high)/2;
        if(strcmp(dictionary[mid].en,word)>0)
            high = mid-1;
        else if(strcmp(dictionary[mid].en,word)<0)
            low = mid+1;
        else
        {
            return mid;
        }
    }
    int i=0;
    for(i=0;i<sum;i++)
    {
        if(strcmp(dictionary[i].en,word)==0)
            return i;
    }
    return -1;
}

 void searchcn(char wordcn[50],int sum)
 {
 	 int i=0;
 	 int count=0;
 	printf("中文\'%s\'的英文意思可能是如下\n",wordcn);
    for(i=0;i<sum;i++)
    {
        if(strstr(dictionary[i].cn,wordcn)!=NULL)		
     	{ 
			 printf("%s\t%s\n",dictionary[i].en,dictionary[i].cn);
			 count++;
		}        
    }
    if(count==0)
    {
    	printf("未找到对应的英文词汇");
	}
 }
 
void printall(int sum)
{
	for(int i=0;i<sum;i++)
	{
		printf("%s\t%s\n",dictionary[i].en,dictionary[i].cn);
	}
}
void add(int sum)
	{
		char en[50];
        char cn[80];
        printf("输入补充的单词：");
        scanf("%s",en);
        strcpy(dictionary[sum].en,en);
        printf("输入汉语翻译：");
        scanf("%s",cn);
        strcpy(dictionary[sum].cn,cn);
        sum++;
        save(sum);
        printf("已添加\n");
    }
void del(int sum)
{
		char word[50];
        int pos;
        printf("请输入您要删除的单词：");
        scanf("%s",word);
        pos = search(word,sum);
        if(pos!=-1)
        {
            char a[5] = "#";
            strcpy(dictionary[pos].cn,a);
            strcpy(dictionary[pos].en,a);
            save(sum);
            printf("已删除\n");
        }
        else
        {
		    printf("未找到\n");
		} 
}
void modify(int sum)
{
 		char word[50];
        int pos;
        printf("请输入您要修正的单词：");
        scanf("%s",word);
        pos = search(word,sum);
        if(pos!=-1)
        {
            printf("请输入新的汉语翻译：");
            char cn[60];
            scanf("%s",cn);
            strcpy(dictionary[pos].cn,cn);
            save(sum);
            printf("已修正\n");
        }
        else
        {
        	  printf("未找到\n");
		}
       
}
void dictation(int sum)
{
	int falsenum=0;
	printf("请输入要听写的单词数目:");
	int totalnum;
	scanf("%d",&totalnum);
	int count=0;
	int i=0;
	while(count<totalnum)
	{
		i=rand()%sum;
		printf("%s\n",dictionary[i].en);
	    char a[50];
		scanf("%s",a);
	 	if(strcmp(dictionary[i].cn,a)!=0)
		 {
	 		printf("错误\n");
	 		falsenum++;
		 }	
		 else
		 {
		 	printf("正确\n");
		 }
		count++;
	}
	float trueper;
	if(falsenum==totalnum)
	{
		trueper=0.00;
	}
	else
	{
		trueper=1.00-(float)totalnum/falsenum;
	}
	printf("总计%d个单词,正确率为%.2f,继续努力！\n",totalnum,trueper);	 
}
        
  
int main(void)
{
	int option=0;
	do
	{
		int sum=0;
	FILE *fp;
    fp = fopen("dictionary1.txt","r");  
    if(fp==NULL)    
    {
        printf("open error!\n");
        exit(1);
    }
    while(!feof(fp)) 
    {
        fscanf(fp,"%s %s", dictionary[sum].en, dictionary[sum].cn);
        ++sum;
    }
    fclose(fp);
		printf("\t电子英汉词典设计\n");
		printf("*********************************************\n");
		printf("*               1.中/英查询                 *\n");      
		printf("*               2.词条录入                  *\n");
		printf("*               3.词条删除                  *\n");
		printf("*               4.词条修改                  *\n");
		printf("*               5.信息显示                  *\n");
		printf("*               6.信息保存                  *\n");
		printf("*               7.进行听写                  *\n");
		printf("*               8.退出系统                  *\n");
		printf("*********************************************\n");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			printf("中-->英(0) OR 英-->中(1)？请输入对应编号\n");
			int choice;
			scanf("%d",&choice);
			if(choice==1) 
			{
				printf("输入所要查询的英文单词:\n");
				char worden[50];
     			scanf("%s",worden);
     			int a;
				 a=search(worden,sum);
     		   if(a!=-1)
     			    { 
					 printf("单词\'%s\'的中文意思是： %s\n",worden,dictionary[a].cn);
					}
          
       			 else
      			    {
        			 printf("未找到\n");
					}    
			}
			else if(choice==0)
			{
				printf("输入所要查询的中文释义(支持模糊查询):\n");
				char wordcn[50];
     			scanf("%s",wordcn); 
				searchcn(wordcn,sum);		  
			}
				break;
        case 2:
			add(sum);
			break;
		case 3:
			del(sum);
			break;
		case 4:
			modify(sum);
		    break;
		case 5:
			printall(sum);
			break;
		case 6:
			save(sum);
			break; 
		case 7:
			dictation(sum);
			break;
		case 8:
			printf("感谢使用本词典！\n");
			return 0;
			break;
		default:
			break;
		}
	}while(option!=0);
	return 0;
}

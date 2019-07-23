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
 	printf("����\'%s\'��Ӣ����˼����������\n",wordcn);
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
    	printf("δ�ҵ���Ӧ��Ӣ�Ĵʻ�");
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
        printf("���벹��ĵ��ʣ�");
        scanf("%s",en);
        strcpy(dictionary[sum].en,en);
        printf("���뺺�﷭�룺");
        scanf("%s",cn);
        strcpy(dictionary[sum].cn,cn);
        sum++;
        save(sum);
        printf("�����\n");
    }
void del(int sum)
{
		char word[50];
        int pos;
        printf("��������Ҫɾ���ĵ��ʣ�");
        scanf("%s",word);
        pos = search(word,sum);
        if(pos!=-1)
        {
            char a[5] = "#";
            strcpy(dictionary[pos].cn,a);
            strcpy(dictionary[pos].en,a);
            save(sum);
            printf("��ɾ��\n");
        }
        else
        {
		    printf("δ�ҵ�\n");
		} 
}
void modify(int sum)
{
 		char word[50];
        int pos;
        printf("��������Ҫ�����ĵ��ʣ�");
        scanf("%s",word);
        pos = search(word,sum);
        if(pos!=-1)
        {
            printf("�������µĺ��﷭�룺");
            char cn[60];
            scanf("%s",cn);
            strcpy(dictionary[pos].cn,cn);
            save(sum);
            printf("������\n");
        }
        else
        {
        	  printf("δ�ҵ�\n");
		}
       
}
void dictation(int sum)
{
	int falsenum=0;
	printf("������Ҫ��д�ĵ�����Ŀ:");
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
	 		printf("����\n");
	 		falsenum++;
		 }	
		 else
		 {
		 	printf("��ȷ\n");
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
	printf("�ܼ�%d������,��ȷ��Ϊ%.2f,����Ŭ����\n",totalnum,trueper);	 
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
		printf("\t����Ӣ���ʵ����\n");
		printf("*********************************************\n");
		printf("*               1.��/Ӣ��ѯ                 *\n");      
		printf("*               2.����¼��                  *\n");
		printf("*               3.����ɾ��                  *\n");
		printf("*               4.�����޸�                  *\n");
		printf("*               5.��Ϣ��ʾ                  *\n");
		printf("*               6.��Ϣ����                  *\n");
		printf("*               7.������д                  *\n");
		printf("*               8.�˳�ϵͳ                  *\n");
		printf("*********************************************\n");
		scanf("%d",&option);
		switch(option)
		{
		case 1:
			printf("��-->Ӣ(0) OR Ӣ-->��(1)���������Ӧ���\n");
			int choice;
			scanf("%d",&choice);
			if(choice==1) 
			{
				printf("������Ҫ��ѯ��Ӣ�ĵ���:\n");
				char worden[50];
     			scanf("%s",worden);
     			int a;
				 a=search(worden,sum);
     		   if(a!=-1)
     			    { 
					 printf("����\'%s\'��������˼�ǣ� %s\n",worden,dictionary[a].cn);
					}
          
       			 else
      			    {
        			 printf("δ�ҵ�\n");
					}    
			}
			else if(choice==0)
			{
				printf("������Ҫ��ѯ����������(֧��ģ����ѯ):\n");
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
			printf("��лʹ�ñ��ʵ䣡\n");
			return 0;
			break;
		default:
			break;
		}
	}while(option!=0);
	return 0;
}

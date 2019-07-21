#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

int wordsNumber =0;//�������� Ŀ 

typedef struct dictionary
{
	char word[20];
	char cn[80];
}data;

data dicSql[5000];//���ʿ� 

int loadSql(data *sql,char path[100]);/*���ص��ʿ�����*/
int printAction();/*����û���ʾ����*/
void dealAction(int action);/*����ָ�����*/
int searchWord(char word[20]);/*���ص����ڵ��ʿ��е�λ��*/
int searchCn(char cn[80]);/*�������ķ����ڵ��ʿ��е�λ��*/
void saveSql();/*�����ļ�����*/


/*������*/
int main()
{
	printf("              ����Ӣ���ʵ����\n\n");
	wordsNumber = loadSql(dicSql,"dictionary.txt");
	int action =-1; //���嶯������ 
	
	while(action!=7)
	{
		action =printAction();
		dealAction(action);
	}
	return 0;
}

/*���ص��ʿ�����*/
int loadSql(data *sql,char path[100])
{
	FILE *fp =NULL;
	int i =0;
	if((fp = fopen(path,"r"))==NULL)
	{
		printf("�ļ���ȡʧ�ܣ�\n");
		return 0;
	}
	while(fscanf(fp,"%s\t%s",(sql+i)->word,(sql+i)->cn)!=EOF)
	{
		i++;
	}
	fclose(fp);
	printf("���ʼ������!\n");
	printf("����%d����������\n",i);
	printf("\n"); 
	return i;
}

/*����û���ʾ����*/
int printAction()
{
	int n =0;
	printf("�˵���\n"); 
	printf("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("   |            1��Ӣ�뺺              |\n"); 
	printf("   *            2������Ӣ              *\n");
	printf("   |            3������¼��            |\n"); 
	printf("   *            4�������޸�            *\n");
	printf("   |            5������ɾ��            |\n"); 
	printf("   *            6����Ϣ����            *\n");
	printf("   |            7���˳�ϵͳ            |\n"); 
	printf("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("������ָ����в�����");
	scanf("%d",&n);
	printf("\n"); 
	return n;
}

/*����ָ�����*/
void dealAction(int action)
{
	switch(action)
	{
		int pos;//����λ�� 
		char word[20];
		char cn[80];
		case 1:
			printf("��������Ҫ��ѯ�ĵ��ʣ�");
			scanf("%s",word);
			printf("\n"); 
			pos = searchWord(word);
			if(pos!=-1)
			{
				printf("����\'%s\'����˼�ǣ�%s\n",word,dicSql[pos].cn);
				printf("\n"); 
				Sleep(1500);
			} 
			else
			{
				printf("�Բ���û���ҵ�������Ҫ�ĵ���!\n");
				printf("\n"); 
				Sleep(1500);
			}
			break;
		
		case 2:
			printf("�������뺺����⣨�ؼ��ʼ���)��");
			printf("\n"); 
			scanf("%s",cn);
			pos = searchCn(cn);
			if(pos!=-1)
			{
				printf("�÷����Ӣ�ﵥ���ǣ�%s\n",dicSql[pos].word);
				printf("\n"); 
				Sleep(1500); 
			}
			else
			{
				printf("�Բ���û���ҵ�������Ҫ�ķ��룡\n");
				printf("\n"); 
				Sleep(1500);
			}
			break;
		
		case 3:
			printf("����������Ҫ¼��ĵ���(�˴�ֻ������Ӣ�ĵ���)��");
			scanf("%s",word);
			printf("\n"); 
			strcpy(dicSql[wordsNumber].word,word);
			printf("��������õ��ʵ����ķ��룺");	
			scanf("%s",cn);
			printf("\n"); 
			strcpy(dicSql[wordsNumber].cn,cn);
			wordsNumber++;
			saveSql(); 
			printf("����������!\n");
			printf("\n"); 
			Sleep(1500);
			break;
		
		case 4:
			printf("����������Ҫ�޸ĵĵ���(�˴�ֻ������Ӣ�ĵ���)��");
			scanf("%s",word);
			printf("\n"); 
			pos =searchWord(word);
			if(pos!=-1)
			{
				printf("�ô�������Ϊ��%s\t%s\n\n",dicSql[pos].word,dicSql[pos].cn);
				printf("��������õ����µ����ķ��룺");
				scanf("%s",cn);
				printf("\n"); 
				strcpy(dicSql[pos].word,word);
				strcpy(dicSql[pos].cn,cn);
				saveSql(); 
				printf("�޸Ĵ������!\n");
				printf("\n"); 
				printf("�޸ĺ�ô���Ϊ��%s\t%s\n\n",dicSql[pos].word,dicSql[pos].cn);
				Sleep(1500);
			}
			else
			{
				printf("δ�ҵ���Ҫ�޸ĵĵ��ʣ�\n");
				printf("\n"); 
				Sleep(1500);
			}
			break;
		
		case 5:
			printf("��������Ҫɾ���ĵ��ʣ�");
			scanf("%s",word);
			printf("\n"); 
			pos =searchWord(word);
			if(pos!=-1)
			{
				char a[5] ="#";
				strcpy(dicSql[pos].word,a);
				strcpy(dicSql[pos].cn,a);
				saveSql();
				printf("ɾ���ɹ���\n");
				printf("\n"); 
				Sleep(1500);
			}
			else
			    printf("�Բ���û���ҵ�������Ҫ�ĵ��ʣ�\n"); 
			    printf("\n"); 
			    Sleep(1500);
			break;
			    
		case 6:
			saveSql();
			printf("��Ϣ����ɹ���\n");
			printf("\n"); 
			Sleep(1500);
			break;
			
		case 7:
			printf("лл����ʹ�ã��ټ���\n");
			break;
			
	}
} 

/*���ص����ڵ��ʿ��е�λ��*/
int searchWord(char word[20])
{
	/*�ö��ַ�����*/
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
	/*��˳����ҷ�����*/ 
	int i=0;
    for(i=0;i<wordsNumber;i++)
    {
        if(strcmp(dicSql[i].word,word)==0)
            return i;
    }
    return -1;//����Ҳ����ͷ���-1 
} 

/*�������ķ����ڵ��ʿ��е�λ��*/
int searchCn(char cn[80])
{
	//��˳����ҷ�
	int i =0;
	for(;i<wordsNumber;i++)
	{
		if(strstr(dicSql[i].cn,cn)!=NULL)
		    return i;
	}
	return -1;// ����Ҳ����ͷ���-1 
}

/*�����ļ�����*/
void saveSql()
{
	FILE *fp =NULL;
	if((fp =fopen("dictionary.txt","w"))==NULL)
	{
		printf("�ļ�����ʧ�ܣ�\n");
		printf("\n"); 
	}
	int i =0;
	for(;i<wordsNumber;i++)
	{
		if(strcmp(dicSql[i].word,"#")!=0)
		{
			fprintf(fp,"%s\t%s\n",dicSql[i].word,dicSql[i].cn);
		}
	}
	fclose(fp);
}
 



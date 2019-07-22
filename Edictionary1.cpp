#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int wordsNumber =0;//��������Ŀ 

typedef struct dictionary
{
	char word[20];
	char cn[80];
}data;

data dicSql[8000];//���ʿ� 
int loadSql(data *sql,char path[100]);/*���ص��ʿ�����*/
int printAction();/*����û���ʾ����*/
void dealAction(int action);/*����ָ�����*/
void dictation();/*��д���ʺ���*/
int searchWord(char word[20]);/*���ص����ڵ��ʿ��е�λ��*/
void searchCn(char cn[80]);/*�������ķ����ڵ��ʿ��е�λ��*/
void saveSql();/*�����ļ�����*/
void wordsBook();


/*������*/
int main()
{
	srand(time(NULL));
	wordsNumber = loadSql(dicSql,"dictionary.txt");
	int action =-1; //���嶯������ 
	
	while(action!=9)
	{
		action =printAction();
		dealAction(action);
	}
	return 0;
}

/*���ص��ʿ�����*/
int loadSql(data *sql,char path[100])
{
	int i =0;
	for(i =0;i<1;i++)
	{
		printf("Ӧ�ó���������.(����װ��)");
		Sleep(500); 
		system("cls");
		printf("Ӧ�ó���������..(����װ��)");
		Sleep(500);  
		system("cls");
		printf("Ӧ�ó���������...(����װ��)"); 
		Sleep(500); 
	}
	i =0;
	FILE *fp =NULL;
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
	printf("\n"); 
	return i;
}

/*����û���ʾ����*/
int printAction()
{
	int n =0;
	system("cls");
	printf("              ����Ӣ���ʵ����\n\n");
	printf("�˵���\n"); 
	printf("   *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
	printf("   |            1��Ӣ�뺺              |\n"); 
	printf("   *            2������Ӣ              *\n");
	printf("   |            3�����ʱ�              |\n");
	printf("   *            4������¼��            *\n"); 
	printf("   |            5�������޸�            |\n");
	printf("   *            6������ɾ��            *\n"); 
	printf("   |            7����д����            |\n");
	printf("   *            8����Ϣ����            *\n");
	printf("   |            9���˳�ϵͳ            |\n"); 
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
				system("pause");
			} 
			else
			{
				printf("�Բ���û���ҵ�������Ҫ�ĵ���!\n");
				printf("\n"); 
				Sleep(3500);
			}
			break;
		
		case 2:
			printf("�������뺺����⣨�ؼ��ʼ���)��");
			scanf("%s",cn);
			printf("\n"); 
			searchCn(cn);
			break;
			
		case 3:
		    wordsBook();
		    break;
		
		case 4:
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
			system("pause");
			break;
		
		case 5:
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
				system("pause");
			}
			else
			{
				printf("δ�ҵ���Ҫ�޸ĵĵ��ʣ�\n");
				printf("\n"); 
				Sleep(3500);
			}
			break;
		
		case 6:
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
				system("pause");
			}
			else
			    printf("�Բ���û���ҵ�������Ҫ�ĵ��ʣ�\n"); 
			    printf("\n"); 
			    Sleep(3500);
			break;
			
		case 7:
		    dictation();
			break; 
			    
		case 8:
			saveSql();
			printf("��Ϣ����ɹ���\n");
			printf("\n"); 
			system("pause");
			break;
			
		case 9:
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

/*�������ķ����Ӧ��Ӣ�ĵ���*/
void searchCn(char cn[80])
{
	//��˳����ҷ�
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
		printf("�Բ���δ�ҵ������Ķ�Ӧ�ĵ��ʣ�\n\n");
	    Sleep(2500);
	} 
}

/*������д����*/ 
void dictation()
{
	system("cls");
	int interval,i,randnum,numOfWords,judge;
	printf("��������д���ʸ�����"); 
	scanf("%d",&numOfWords); 
	printf("�����ü��������");
	scanf("%d",&interval); 
	interval *=1000;
	printf("��ѡ����д���ͣ�1->��Ӣ��д  2->Ӣ����д):");
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
	        printf("\n��д�����������£�\n");
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
	        printf("\n��д�����������£�\n");
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

/*�����ļ�����*/
void saveSql()
{
	int i =0;
	FILE *fp =NULL;
	if((fp =fopen("dictionary.txt","w"))==NULL)
	{
		printf("�ļ�����ʧ�ܣ�\n");
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

/*���ʱ�����*/
void wordsBook()
{
	data wordsBook[500];
	int i =0,numOfWords,judge =-1;
	char word[20];
	FILE *wf1 =NULL;
	FILE *wf =NULL;
	if((wf1 =fopen("wordsBook.txt","r"))==NULL)
	{
		printf("���ʱ���ʧ�ܣ�\n\n");
		system("pause");
	}
	else
	{
		//�ӵ��ʱ��ļ��ж�ȡ���� ������ڽṹ�������� 
		while(fscanf(wf1,"%s\t%s",wordsBook[i].word,wordsBook[i].cn)!=EOF)
	    {
	        i++;
	    }
	    numOfWords = i;
	    fclose(wf1);
	}
	if((wf =fopen("wordsBook.txt","w"))==NULL)
	{
		printf("���ʱ���ʧ�ܣ�\n\n");
		system("pause");
	}
	else{
		printf("1���򿪵��ʱ�\n");
		printf("2������µ���\n");
		printf("3��ɾ������\n");
		printf("��������Ž��в�����");
		int n;
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\n���ʱ��������£�\n"); 
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
			    printf("\n������Ҫ��ӵ�Ӣ�ĵ��ʣ�");
			    scanf("%s",&wordsBook[numOfWords].word);
			    printf("������õ��ʵ����ķ��룺");
			    scanf("%s",&wordsBook[numOfWords].cn);
			    printf("\n");
			    numOfWords++;
			    for(i =0;i<numOfWords;i++)
			    {
					fprintf(wf,"%s\t%s\n",wordsBook[i].word,wordsBook[i].cn);	
				}
			    printf("��ӳɹ���");
			    printf("\n");
			    system("pause");
			    break;
			    
			case 3:
				judge =1;//�����жϵ��ʱ����Ƿ����û�����ĵ��� 
				printf("\n��������Ҫɾ���ĵ��ʣ�");
				scanf("%s",word);
				printf("\n"); 
				for(i =0;i<numOfWords;i++)
				{
					if(strcmp(wordsBook[i].word,word)==0)
					{
						char a[5] ="#";
						strcpy(wordsBook[i].word,a);
						judge =0;//������ʱ������û���Ҫɾ���ĵ��ʣ���ı�judge��ֵ 	
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
			    	printf("�Բ���û���ҵ�������Ҫ�ĵ��ʣ�\n\n");
				else
				    printf("ɾ���ɹ���\n\n");
			    
			    system("pause");
				break;
		}
	} 
	fclose(wf);
} 

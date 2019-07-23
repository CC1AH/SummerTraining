#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include"game2.h"
#define original 2000


typedef struct dictionary
{
	char word[20];
	char cn[80];
}data;

int wordsNumber =0;//��������Ŀ 
data dicSql[8000];//���ʿ� 

int loadSql(data *sql,char path[100]);/*���ص��ʿ�����*/
int printAction();/*����û���ʾ����*/
void dealAction(int action);/*����ָ�����*/
void dictation();/*��д���ʺ���*/
int searchWord(char word[20]);/*���ص����ڵ��ʿ��е�λ��*/
void searchCn(char cn[80]);/*�������ķ����ڵ��ʿ��е�λ��*/
void saveSql();/*�����ļ�����*/
void wordsBook();/*���ʱ�����*/ 
void game1();//Ͷ����С��Ϸ

/*���ص��ʿ�����*/
int loadSql(data *sql,char path[100])
{
	int i =0;
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
	printf("   |            9������С��Ϸ          |\n"); 
	printf("   *           10�����ʿ�����Github    *\n");
	printf("   |           11���˳�ϵͳ            |\n"); 
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
		case 1://��ѯӢ�ĵ��ʵ����ĺ���
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
				system("pause");
			}
			break;
		
		case 2://��ѯ��������Ӧ��Ӣ�ĵ���
			printf("�������뺺����⣨�ؼ��ʼ���)��");
			scanf("%s",cn);
			printf("\n"); 
			searchCn(cn);
			break;
			
		case 3://���ʱ�
		    wordsBook();
		    break;
		
		case 4://�򵥴ʿ�����Ӵ���
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
		
		case 5://�޸ĵ��ʿ��еĴ���
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
		
		case 6://ɾ��ָ������
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
			
		case 7://������д
		    dictation();
			break; 
			    
		case 8://������Ϣ
			saveSql();
			printf("��Ϣ����ɹ���\n");
			printf("\n"); 
			system("pause");
			break;
			
		case 9: 
		    printf("1��Ͷ����С��Ϸ\n");
		    printf("2��Ƥ����С��Ϸ\n");
		    printf("��ѡ��");
		    int choice;
		    scanf("%d",&choice);
			system("cls");
		    switch(choice)
		    {
		    	case 1:
		    		game1();
		    		break;
		    	case 2:
		    		game2();
		    		break;
		    	default:
		    		printf("ѡ�����\n");
		    		break;
			}
		    break;
			
		case 10://Github
			printf("��ȷ���������糩ͨ��");
			puts("https://github.com/CC1AH/SummerTraining");
			Sleep(2000);
			ShellExecute(NULL,"open","https://github.com/CC1AH/SummerTraining",NULL,NULL,SW_NORMAL);
			break;
			
		case 11://�˳�ϵͳ
			printf("лл����ʹ�ã��ټ���\n");
			break;
			
		default:
			printf("����ָ���������������룡\n");
			break;
			
	}
} 

/*���ص����ڵ��ʿ��е�λ��*/
int searchWord(char word[20])
{
	wordsNumber =loadSql(dicSql,"dictionary.txt");
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
	wordsNumber =loadSql(dicSql,"dictionary.txt");
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
	if(judge==-1)
	{
		printf("�Բ���δ�ҵ������Ķ�Ӧ�ĵ��ʣ�\n\n");
	} 
	system("pause"); 
}

/*������д����*/ 
void dictation()
{
	wordsNumber =loadSql(dicSql,"dictionary.txt");
	srand(time(NULL));
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
	char *word[500];
	char *cn[500];
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
	wordsNumber =loadSql(dicSql,"dictionary.txt");
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
	system("cls");
	srand(time(NULL));
	data wordsBook[500];
	int i =0,numOfWords,judge =-1;
	numOfWords = loadSql(wordsBook,"wordsBook.txt");//�ӵ��ʱ��ж�ȡ��������ڽṹ��������
	char word[20];
	FILE *wf =NULL;
	if((wf =fopen("wordsBook.txt","w"))==NULL)
	{
		printf("���ʱ���ʧ�ܣ�\n\n");
		system("pause");
	}
	else{
		printf("���ʱ�:\n");
		printf("   * * * * * * * * * * * *\n");
		printf("   *   1���򿪵��ʱ�     *\n");
		printf("   *   2������µ���     *\n");
		printf("   *   3��ɾ������       *\n");
		printf("   *   4����д����       *\n");
		printf("   * * * * * * * * * * * *\n");
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
				//�����á�w����ʽд�ļ��ᶪ��֮ǰ�����ݣ��˴��ٰѵ���д�뵥�ʱ�
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

			case 4:
				char *word[500];
				char *cn[500];
				system("cls");
				int interval,randnum,round,type;
				printf("��������д���ʸ�����"); 
				scanf("%d",&round); //��д���ʵĸ���
				printf("�����ü��������");
				scanf("%d",&interval); //��д���ʵļ��ʱ��
				interval *=1000;//����ת���ɺ���
				printf("��ѡ����д���ͣ�1->��Ӣ��д  2->Ӣ����д):");
				scanf("%d",&type);
				printf("\n");
				//��type����ѡ���ж�
				switch(type)
				{
					case 1:
						for(i=0;i<round;i++)
	        			{
		        			randnum = rand()%numOfWords+1;//�ӵ��ʱ��������ȡ����
		        			printf("Number %d:   %s\n",i+1,wordsBook[randnum].cn);
		        			word[i] = wordsBook[randnum].word;
		        			cn[i] = wordsBook[randnum].cn;
		        			Sleep(interval);
	        			}
	        			printf("\n��д�����������£�\n");
						//forѭ�������д��
	       			    for(i=0;i<round;i++)
	        			{
		       			    printf("Number %d:   %s\t%s\n",i+1,word[i],cn[i]);
						} 
	        			printf("\n");
	        			system("pause");
	        			printf("\n");
	        			break;
	        
	    			case 2:
	    				for(i=0;i<round;i++)
	        			{
		        			randnum = rand()%numOfWords+1;//�ӵ��ʱ��������ȡ����
		       			    printf("Number %d:   %s\n",i+1,wordsBook[randnum].word);
		        			word[i] = wordsBook[randnum].word;
		        			cn[i] = wordsBook[randnum].cn;
		       			    Sleep(interval);
	        			}
	        			printf("\n��д�����������£�\n");
						//forѭ�������д��
	        			for(i=0;i<round;i++)
	        			{
		        			printf("Number %d:   %s\t%s\n",i+1,word[i],cn[i]);
	        			} 
	        			printf("\n");
	       			    system("pause");
	        			printf("\n");
	        			break;
					default:
						break;
				}
				//�����á�w����ʽд�ļ��ᶪ��֮ǰ�����ݣ��˴��ٰѵ���д�뵥�ʱ�
				for(i =0;i<numOfWords;i++)
			    {
					fprintf(wf,"%s\t%s\n",wordsBook[i].word,wordsBook[i].cn);	
				}
				break;
		}
	} 
	fclose(wf);
} 

//С��Ϸ1
void game1()
{
	srand(time(NULL));
	int total=0;
	int yue=original; 
	printf("�ǳ���л�����뱾��Ϸ��\n");
	printf("��Ϸ�������£�\n"); 
	Sleep(1000);
	printf("1������Ϸ��ʼ�׶Σ���ӵ�б���%dԪ\n\n",original);
	Sleep(2000);
	printf("2����ÿ����Ҫ��ǰѡ�񵥻�˫����ȷ����ע���\n\n");
	Sleep(2000);
	printf("3������ö��������֮�͵ĵ�˫��������ѡ�����ͬ,\n����������������Ӷ�Ӧ��ע��������, \n");
	printf("��������������п۳���Ӧ��ע��������\n\n"); 
	Sleep(2000);
	printf("���棬�����ǿ�ʼ��Ϸ�ɣ�\n") ;
	Sleep(2000);
	int judge=0;
	while(yue>0)
	{
		int n=0;
		int xiazhu=0;
		printf("����������ѡ��1-����2-˫����");
		scanf("%d",&n);
		printf("����������Ҫ��ע�Ľ�");
		scanf("%d",&xiazhu);
		if(xiazhu>yue){
			printf("�������㣡\n");
			break; 
		}
		total=(rand()%6+1)+(rand()%6+1);
		if(total%2==1&&n==1){
			yue+=xiazhu;
			printf("��ϲ��Ӯ�˱�����Ϸ���������%d,ʣ�����Ϊ��%d\n\n",xiazhu,yue);
			if(yue<=0)break;
			printf("������-1������Ϸ������1������Ϸ��");
		    scanf("%d",&judge);
		    if(judge==-1)break;
		}
		if(total%2==1&&n==2){
			yue-=xiazhu;
			printf("���ź���������Ϸ�����ˣ�������%d,ʣ�����Ϊ��%d\n\n",xiazhu,yue);
			if(yue<=0)break;
			printf("������-1������Ϸ������1������Ϸ��");
		    scanf("%d",&judge);
		    if(judge==-1)break;
		}
		if(total%2==0&&n==1){
			yue-=xiazhu;
			printf("���ź���������Ϸ�����ˣ�������%d,ʣ�����Ϊ��%d\n\n",xiazhu,yue);
			if(yue<=0)break;
			printf("������-1������Ϸ������1������Ϸ��");
		    scanf("%d",&judge);
		    if(judge==-1)break;
		}
		if(total%2==0&&n==2){
			yue+=xiazhu;
			printf("��ϲ��Ӯ�˱�����Ϸ���������%d,ʣ�����Ϊ��%d\n\n",xiazhu,yue);
			if(yue<=0)break;
			printf("������-1������Ϸ������1������Ϸ��");
		    scanf("%d",&judge);
		    if(judge==-1)break;
		}
	}
	printf("��Ϸ�������������Ϊ:%d!�ٴθ�л���Ĳ��룡",yue);
	system("pause"); 
}


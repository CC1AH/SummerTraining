#ifndef OTHEROPERATION_H_INCLUDED
#define OTHEROPERATION_H_INCLUDED
#include <time.h>
#include "BasicStructrue.h"
#include "BasicFunctions.h"
#include "WordOperation.h"
/**
* ���ļ������˵��Ӵǵ�Ķ��⹦��ģ�飨��д���ղؼУ�
* @author �Ϲ���
* 2019/7/22
* copyright reserved
*/

//�����ĺ���ԭ��
void dictation(int choose,nodeptr list);
int executeDictation(nodeptr list,int n);//"��д"���ӹ��ܺ��� ִ��
void saveDictationInfo(int dicWordNum,int wrongNum);//"��д"���ӹ��ܺ��� ����
void getCurrentTime(char info[]);//"��д"���ӹ��ܺ��������桰���ӹ��ܺ��� ��ȡ��ǰ����ʱ��

void collections(nodeptr list);
nodeptr initialCollections(nodeptr list);//"�ղؼ�"���ӹ��ܺ���,��ȡcollections.txt��ʼ������listΪͷ��ָ��
void readToCollections(nodeptr list);//"�ղؼ�"���ӹ��ܺ���,��ȡ��listΪͷ��ָ���ʼ����collections.txt


//��������ԭ�͵Ļ�������
/**
* ��д
* ���Դ�listΪͷ�����������ѡ���û�ָ����
* ���ʸ���������д,��������д�ĸ�����
* ����һ���ļ���¼��д���ܴ�������ʾ
* list����������֧�������ղؼ�ָ��
* @param choose:int list:nodeptr
*/
void dictation(int choose,nodeptr list){
	if(choose == 3){
        FILE* file;
        if((file = fopen("dictationInfo.txt","r"))==NULL){
            printf("��д�ļ���ʧ��\n");
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
        printf("û�����ѡ������������ѡ��");
        scanf("%d",&choose);
    }

    int dicWordNum;
    fflush(stdin);
    printf("����������Ҫ��д�ĵ��ʵĸ�������ȷ���������С������ѡ����ļ����ܵ��ʸ���\n");
    scanf("%d",&dicWordNum);
    int wrongNum = executeDictation(list,dicWordNum);
    saveDictationInfo(dicWordNum,wrongNum);
}

/*
"��д"���ӹ��ܺ��� ִ��
���ڳ�ȡn�����ʽ�����д ���ش������
*/
int executeDictation(nodeptr list,int n){
    //ͳ�������ܽڵ������
    nodeptr tmp = list->next;
    int count = 0;
    while(tmp!=NULL){
        (tmp->data).isDictated = 0;
        tmp = tmp->next;
        count++;
    }
    printf("������%d�������г�ȡ%d��������д\n",count,n);

    //�������n����ͬ�ĵ��ʲ�ͳ�ƴ������
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

        //����Ѿ�����д��������ѡһ��
        if((tmp->data).isDictated){
            i--;
            break;
        }

        //��������д
        else{
        (tmp->data).isDictated = 1;
        fflush(stdin);
        printf("\n����%d :������\"%s\"�����Ӧ�ĵ���\n",i+1,(tmp->data).mean);
        char inputWord[WORDNUM+1];
        scanf("%s",inputWord);
        if(strcmp(inputWord,(tmp->data).word)==0){
            printf("������д��ȷ\n");
        }
        else{
            printf("������д����,��ȷ�ĵ���Ӧ���ǣ�%s\n",(tmp->data).word);
            wrongNum++;
        }
    }
    }
    printf("\n������д��ϣ��������Ϊ%d��\n",wrongNum);
    return wrongNum;
}

/*
"��д"���ӹ��ܺ��� ����
*����д���� ��д���� ����������浽dictation.txt�ļ�����
*/
void saveDictationInfo(int dicWordNum,int wrongNum){
    FILE* file;
    if((file = fopen("dictationInfo.txt","a+"))==NULL){
        printf("��д�ļ���ʧ��\n");
        return;
    }

    char info[200];
    getCurrentTime(info);
    fprintf(file,"\n��%s:����д��%d�����ʣ����������%d��",info,dicWordNum,wrongNum);
    printf("  ��д��Ϣ�������");
    fclose(file);//����Ҫ�� û�оͲ�����
}

/*
*"��д"���ӹ��ܺ��������桰���ӹ��ܺ��� ��ȡ��ǰ����ʱ��
*��ȡ��� �·� ���� Сʱ ���Ӳ�������һ���ַ�����
*/
void getCurrentTime(char info[]){
    time_t t;
    struct tm* lt;
    time(&t);
    lt = localtime(&t);

    sprintf(info,"%d��%d��%d��_%dʱ%d��",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour,lt->tm_min);
    printf(info);
}


/**
* �ղؼ�
* ��listΪͷ��ָ���ʼ��collections.txt���ļ�����
* ���ṩɾ�������ӣ��޸Ĳ��������������ļ��б���ӳ
* @param list:nodeptr
*/
void collections(nodeptr list){
    list = initialCollections(list);
    printf("\n\n\n\t\t\t\t   ��ӭ-----^-^------�ղؼ�----^-^-----��ӭ\n");
	printf("                        ____________________________________________________________\n");
	printf("                        |------------------(0)�г��ղؼ�����-----------------------|\n");
	printf("                        |------------------(1)���ȫ���ղ�-------------------------|\n");
	printf("                        |------------------(2)�����ղؼе���-----------------------|\n");
	printf("                        |------------------(3)ɾ���ղؼе���-----------------------|\n");
	printf("                        |------------------(4)�޸��ղؼе�������-------------------|\n");
	printf("                        |__________________________________________________________|\n");
	int choose;
	fflush(stdin);
	printf("�����������������(0-4)��");

	//���û���ѡ����0-4֮��ķ�Χ����ʾ�û������������������
	while((scanf("%d", &choose)!=1) || (choose<0||choose>8))
	{
		printf("�����������������(0-4)��");
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
            printf("�ղؼ��ļ���ʧ��\n");
            return;
        }
        fprintf(readFile,"");
        puts("�ղؼ��ļ��Ѿ��ǿյ���");
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
*"�ղؼ�"���ӹ��ܺ���
*��ȡcollections.txt��ʼ������listΪͷ��ָ������
*/
nodeptr initialCollections(nodeptr list){
    nodeptr add;
	list=(struct listNode *)malloc(sizeof(struct listNode));
	if(list!=NULL)
	{
		list->next=NULL;
	}

	//ͳ�ƴ�������
	int num=0;

	FILE *readFile = fopen("collections.txt","r");
	if(readFile==NULL)
    {
        printf("�ղؼ��ļ���ʧ��\n");
        return list;
    }
	else
	{
	    printf("-----------�ղؼ�������----------");
		while(!feof(readFile))
		{
			add=(struct listNode *)malloc(sizeof(struct listNode));
			if(add!=NULL)
			{
				num=fscanf(readFile,"%s\t%s\n",(add->data).word,(add->data).mean);
				//����ֵ��add�����ݸ���С��2������ѭ��
				if(num<2)
				{
				    printf("\n�����������\n");
					break;
				}
				//Ӣ�ĵ�������ĸ����ĸ���˳���add�����ݲ��뵽list��
				InsertList(list,add);
			}
		}
		printf("\n�ղؼм��������\n");
	}
	return list;
}
void readToCollections(nodeptr list){
    nodeptr tmp = list;
	FILE *writeFile = fopen("collections.txt","w");
	if(writeFile==NULL)
    {
        printf("�ղؼ��ļ���ʧ��\n");
        return;
    }
	else
	{
	    printf("-----------�ղؼи�����----------");
		while(tmp!=NULL)
		{
            fprintf(writeFile,"%s\t%s\n",(tmp->data).word,(tmp->data).mean);
			tmp = tmp->next;
		}
		printf("\n�ղؼи��������\n");
	}
	fclose(writeFile);
}
#endif // OTHEROPERATION_H_INCLUDED

#ifndef BASICINPUT_H_INCLUDED
#define BASICINPUT_H_INCLUDED
#include "WordOperate.h"
/**
* @author �Ϲ���
* 2019/7/21
* �����û�����Ľ����ѡ��
* ����ǵ��ļ��ĳ�ʼ��
*/

int choseMenu();
void initial(nodeptr);

//ʹ��choseMenu���������û�����Ľ���ͻ������� �����û���ѡ��
int choseMenu(){

    printf("\n\n\n                        ��ӭ-----^-^-----------^-^------------^-^-----��ӭ\n");
	printf("                            ____________________________________________________\n");
	printf("                        |------------------(0)Ӣ�뺺����-----------------------|\n");
	printf("                        |------------------(1)����Ӣ����-----------------------|\n");
	printf("                        |------------------(2)���ӵ���-------------------------|\n");
	printf("                        |------------------(3)ɾ������-------------------------|\n");
	printf("                        |------------------(4)�޸�����-------------------------|\n");
	printf("                        |------------------(5)�ղؼ�---------------------------|\n");
	printf("                        |------------------(6)��д-----------------------------|\n");
	printf("                        |__________________________________________________|\n");
	printf("\n");

	int choose;
	//���������
	fflush(stdin);
	//�����û���ѡ��
	printf("�����������������(0-6)��");

	//���û���ѡ����0-1֮��ķ�Χ����ʾ�û������������������
	while((scanf("%d", &choose)!=1) || (choose<0||choose>6))
	{
		printf("�����������������(0-1)��");
		//���������
		fflush(stdin);
	}
    return choose;
}

void initial(nodeptr list){
    //��������ṹ�帨���������ݵĶ�ȡ�Ĺ���
	nodeptr add;
	//�ͷ��Ѵ�������
	FreeList(list);
	//���´�������ṹ��
	list=(struct listNode *)malloc(sizeof(struct listNode));
	if(list!=NULL)
	{
		//��list����һ�����ָ��NULL
		list->next=NULL;
	}

	//����һ��������Ϊͳ�ƴ�������
	int num;
	//��ʼ��ͳ������Ϊ0
	num=0;
	//�Զ���readFile�Զ�ȡ�ķ�ʽ��dictionary.txt
	FILE *readFile = fopen("dictionary.txt","r");
	//��readFile�������ɹ�����������dictionary.txt�ļ�
	if(readFile==NULL)
    {
        printf("�ǵ��ļ���ʧ��\n");
        return;
    }
	else
	{
		//����ȡ�ļ���Ϊ�ļ�������
		while(!feof(readFile))
		{
			//��������ṹ�帨�����ݵĶ�ȡ����
			add=(struct listNode *)malloc(sizeof(struct listNode));
			if(add!=NULL)
			{
				//numͳ���ļ�����ֵ��add�����ݸ���
				num=fscanf(readFile,"%10s %10s %10s\n",(add->data).word,(add->data).mean,(add->data).format);
				//����ֵ��add�����ݸ���С��3������ѭ��
				if(num<3)
				{
					break;
				}
				//Ӣ�ĵ�������ĸ����ĸ���˳���add�����ݲ��뵽list��
				InsertList(list,add);
			}
		}
		//��ӡ��ȡ�ɹ�
		printf("dictionary.txt�е����д����ѱ������ֵ���");
	}
}

#endif // BASICINPUT_H_INCLUDED

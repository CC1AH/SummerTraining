#include <stdio.h>
#include <stdlib.h>
//���ʳ��ȣ����Գ��ȣ����������峤�ȵ����ֵ
#define WORDNUM 30
#define MEANNUM 30

//��������
struct content
{
    //����Ӣ�ĵ��ʳ���
    char word[WORDNUM+1];
    //�����������峤��
    char mean[MEANNUM+1];
    //���õ��ʴ��Գ���
    char format[WORDNUM+1];
};

//����
struct listNode
{
    //�����򣬴������
    struct content data;
    //ָ����һ������ڵ�
    struct listNode *next;
};

typedef struct listNode node;
typedef struct listNode* nodeptr;

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

int main(){
    int choose = choseMenu();
    switch(choose){
    case 0:
        syst
    }
}

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct stu
{
	int  num;
	char name[20];
	char gender[5];
	char address[20];
	char call[11];
	char email[20];
}Stu;

int menu();
void input(Stu stu[]);
void dele(Stu stu[]);
void change(Stu stu[]);
void search(Stu stu[]);
void save(Stu stu[]);

int num =0;
Stu stu[50];

int main()
{	
	int judge =1;
	while(judge)
	{
		switch(menu()){
			case 1:input(stu);
			    break;
			case 2:dele(stu);
			    break;
			case 3:change(stu);
			    break;
			case 4:search(stu);
			    break;
			case 5:save(stu);
			    break;
			case 6:
				return 0;
		}
	}
}

int menu()
{
	int n; 
	printf("��ѡ�������\n");
	printf("1��¼��ѧ����Ϣ\t");
	printf("2��ɾ��ѧ����Ϣ\n");
	printf("3���޸�ѧ����Ϣ\t");
	printf("4������ѧ����Ϣ\n");
	printf("5������ѧ����Ϣ\n");
	printf("6���˳�\n"); 
	scanf("%d",&n);
	printf("\n");
	return n;
}

void input(Stu stu[])
{
	int i;
	int judge =1;
	while(judge)
	{
		printf("�Ƿ�����ѧ����Ϣ��1(��) OR 0����"); 
		scanf("%d",&judge);
		if(judge==0) break;
		else
		{
			stu[num].num =num+1;
			printf("�������%dλѧ����������",num+1);
			scanf("%s",stu[num].name);
			printf("�������%dλѧ�����Ա�",num+1);
			scanf("%s",stu[num].gender);
			printf("�������%dλѧ���ļ�ͥ��ַ��",num+1);
			scanf("%s",stu[num].address);
			printf("�������%dλѧ������ϵ�绰��",num+1);
			scanf("%s",stu[num].call);
			printf("�������%dλѧ���ĵ������䣺",num+1);
			scanf("%s",stu[num].email);
		}
		num++;
		printf("\n");
	}
	printf("������ϣ�ѧ����Ϣ���£�\n");
	printf("ѧ������ ����\t�Ա�\t��ַ\t�绰\t����\t\n");
	for(i =0;i<num;i++){
		printf("%d\t %s\t%s\t%s\t%s\t%s\t\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	}
	printf("\n");
	Sleep(1000);
}

void dele(Stu stu[])
{
	int n,i,j;
	printf("��������Ҫɾ����ѧ�����ţ�"); 
	scanf("%d",&n);
	for(i=1;i<=num;i++){
		if(i==n){
			for(j =i;j<num;j++){
				stu[j-1]=stu[j];
			}
		}
	}
	num--;
	for(int i=0;i<num;i++){
		stu[i].num--;
	}
	printf("ɾ���ɹ���ѧ����Ϣ���£�\n"); 
	printf("ѧ������ ����\t�Ա�\t��ַ\t�绰\t����\t\n");
	for(i =0;i<num;i++){
		printf("%d\t %s\t%s\t%s\t%s\t%s\t\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	}
	printf("\n");
}

void change(Stu stu[])
{
	printf("��������Ҫ�޸���Ϣ��ѧ�����ţ�");
	int n,i;
	scanf("%d",&n);
	for(i =1;i<=num;i++){
		if(i==n){
			stu[i-1].num =n; 
			printf("������ѧ��������") ;
			scanf("%s",stu[i-1].name); 
			printf("������ѧ���Ա�") ;
			scanf("%s",stu[i-1].gender); 
			printf("������ѧ����ͥ��ַ��") ;
			scanf("%s",stu[i-1].address); 
			printf("������ѧ����ϵ�绰��") ;
			scanf("%s",stu[i-1].call); 
			printf("������ѧ���������䣺") ;
			scanf("%s",stu[i-1].email); 
		}
	}
	printf("��Ϣ�޸ĳɹ���ѧ����Ϣ���£�\n");
	printf("ѧ������ ����\t�Ա�\t��ַ\t�绰\t����\t\n");
	for(i =0;i<num;i++){
		printf("%d\t %s\t%s\t%s\t%s\t%s\t\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	}
	printf("\n");
	Sleep(1000);
}

void search(Stu stu[])
{
	printf("��������Ҫ���ҵ�ѧ�����ţ�");
	int n,i;
	scanf("%d",&n);
	for(i =1;i<=num;i++){
		if(i ==n){
			printf("��ѧ����Ϣ���£�\n");
			printf("ѧ������ ����\t�Ա�\t��ַ\t�绰\t����\t\n");
			printf("%d\t %s\t%s\t%s\t%s\t%s\t\n",stu[i-1].num,stu[i-1].name,stu[i-1].gender,stu[i-1].address,stu[i-1].call,stu[i-1].email);
		}
	} 
	printf("\n");
	Sleep(1000);
}

void save(Stu stu[])
{
	FILE *Sf;
	int i;
	if((Sf = fopen("d:\\StudentInformation.text","a+"))==NULL)
	{
		printf("����ʧ�ܣ�");
	}
	else
	{
		for(i =0;i<num;i++){
		    fprintf(Sf,"%d\t%s\t%s\t%s\t%s\t%s\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	    }
	    printf("����ɹ�!\n");
	}
	
}




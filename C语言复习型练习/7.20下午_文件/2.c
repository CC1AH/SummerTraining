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
	printf("请选择操作：\n");
	printf("1、录入学生信息\t");
	printf("2、删除学生信息\n");
	printf("3、修改学生信息\t");
	printf("4、查找学生信息\n");
	printf("5、保存学生信息\n");
	printf("6、退出\n"); 
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
		printf("是否输入学生信息？1(是) OR 0（否）"); 
		scanf("%d",&judge);
		if(judge==0) break;
		else
		{
			stu[num].num =num+1;
			printf("请输入第%d位学生的姓名：",num+1);
			scanf("%s",stu[num].name);
			printf("请输入第%d位学生的性别：",num+1);
			scanf("%s",stu[num].gender);
			printf("请输入第%d位学生的家庭地址：",num+1);
			scanf("%s",stu[num].address);
			printf("请输入第%d位学生的联系电话：",num+1);
			scanf("%s",stu[num].call);
			printf("请输入第%d位学生的电子邮箱：",num+1);
			scanf("%s",stu[num].email);
		}
		num++;
		printf("\n");
	}
	printf("输入完毕！学生信息如下：\n");
	printf("学生代号 姓名\t性别\t地址\t电话\t邮箱\t\n");
	for(i =0;i<num;i++){
		printf("%d\t %s\t%s\t%s\t%s\t%s\t\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	}
	printf("\n");
	Sleep(1000);
}

void dele(Stu stu[])
{
	int n,i,j;
	printf("请输入需要删除的学生代号："); 
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
	printf("删除成功！学生信息如下：\n"); 
	printf("学生代号 姓名\t性别\t地址\t电话\t邮箱\t\n");
	for(i =0;i<num;i++){
		printf("%d\t %s\t%s\t%s\t%s\t%s\t\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	}
	printf("\n");
}

void change(Stu stu[])
{
	printf("请输入需要修改信息的学生代号：");
	int n,i;
	scanf("%d",&n);
	for(i =1;i<=num;i++){
		if(i==n){
			stu[i-1].num =n; 
			printf("请输入学生姓名：") ;
			scanf("%s",stu[i-1].name); 
			printf("请输入学生性别：") ;
			scanf("%s",stu[i-1].gender); 
			printf("请输入学生家庭地址：") ;
			scanf("%s",stu[i-1].address); 
			printf("请输入学生联系电话：") ;
			scanf("%s",stu[i-1].call); 
			printf("请输入学生电子邮箱：") ;
			scanf("%s",stu[i-1].email); 
		}
	}
	printf("信息修改成功！学生信息如下：\n");
	printf("学生代号 姓名\t性别\t地址\t电话\t邮箱\t\n");
	for(i =0;i<num;i++){
		printf("%d\t %s\t%s\t%s\t%s\t%s\t\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	}
	printf("\n");
	Sleep(1000);
}

void search(Stu stu[])
{
	printf("请输入需要查找的学生代号：");
	int n,i;
	scanf("%d",&n);
	for(i =1;i<=num;i++){
		if(i ==n){
			printf("该学生信息如下：\n");
			printf("学生代号 姓名\t性别\t地址\t电话\t邮箱\t\n");
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
		printf("保存失败！");
	}
	else
	{
		for(i =0;i<num;i++){
		    fprintf(Sf,"%d\t%s\t%s\t%s\t%s\t%s\n",stu[i].num,stu[i].name,stu[i].gender,stu[i].address,stu[i].call,stu[i].email);
	    }
	    printf("保存成功!\n");
	}
	
}




/*3、 编写一个程序实现学生成绩管理（人数不超过30人），每个学生信息包括学号、姓名、课程成绩，
要求：a.按照学生成绩由高到低排序，
b.在排序后的学生成绩表中插入一个学生的信息，要求插入后仍然保持成绩表有序，
c.要求输入指定的学生，从学生信息表中删除该学生，删除后的成绩表保持有序。
程序中使用结构体保存每个学生的信息，包括学号、姓名、课程的成绩,使用结构体数组保存所有学生的信息*/
#include "stdio.h"
struct stuscore
{
		int  num;			/* 学号 */
		char name[20];		/* 姓名 */
		float score;		/* 课程成绩 */
};
	struct stuscore stus[30]; /* 声明一个结构数组变量，为全局变量 */
	struct stuscore input(); /* 输入学生成绩信息函数，函数返回值为结构变量 */
	void display(struct stuscore stud[], int count);  /* 显示学生信息函数 */
	void sort(struct stuscore stud[], int count);     /* 学生成绩排序函数 */
	void insert(struct stuscore stud[], int count);    /* 插入函数 */
	void del(struct stuscore stud[], int count);       /* 删除函数 */
	int main( )
	{
		int i, count;
		char ch;
		printf("请输入学生成绩信息。");
		for (i = 0; i < 4; i++)
		{
			stus[i] = input();                        /* 调用录入信息函数 */
		}
		count = 4;
		printf("\n按成绩排序前的学生成绩信息如下：");
		display(stus, count);                          /* 调用显示信息函数 */
		sort(stus, count);                             /* 调用排序函数 */
		printf("\n按成绩排序后的学生成绩信息如下：");
		display(stus, count);
		printf("\n\n是否确认插入新学生信息?(y or n)");
		getchar();
		scanf("%c", &ch);
		if(ch == 'Y' || ch == 'y')
		{
			insert(stus, count);			/* 调用插入信息函数 */
			count++;
			printf("\n插入新学生信息后的学生成绩信息如下：");
			display(stus,count);
		}
		printf("\n\n是否要删除某个学生?(y or n)");
		getchar();
		scanf("%c", &ch);
		if(ch == 'Y' || ch == 'y')
		{
			del(stus,count);				/* 调用删除信息函数 */
			count--;
			printf("\n删除后学生成绩信息如下：");
			display(stus, count);
		}
		return 0;
	}

	struct stuscore input( )				/* 录入学生成绩信息函数 */
	{
        struct stuscore stu;
			/* 输入学生的基本信息*/
            printf("请输入学生的学号：");
            scanf("%d",&stu.num);
            getchar();
            printf("请输入学生的姓名：");
            gets(stu.name);
            printf("请输入学生的成绩：");
            scanf("%f",&stu.score);
		return stu;
	}

	/* 显示学生成绩信息函数 */
	void display(struct stuscore stud[], int count)
	{
	    int i;
		for(i=0;i<count;++i){
            printf("%d %s %f\n",stus[i].num,stus[i].name,stus[i].score);
		}
	}

	void sort(struct stuscore stud[], int count)		/* 排序函数 */
	{
		/*  冒泡排序法 */
		int pass,i;
		struct stuscore t;
        for(pass=1;pass<count;++pass){
            for(i=0;i<count-pass;++i){
                if(stus[i].score<stus[i+1].score){
                t = stus[i];
                stus[i] = stus[i+1];
                stus[i+1] = t;
                }
            }
        }

	}

	void insert(struct stuscore stud[], int count)		/* 插入函数 */
	{
	    struct stuscore stuCopy[count+1];
		/* 插入一个学生的信息，要求插入后的学生信息依然有序 */
		int j,i;
        printf("请插入新学生信息\n");
        struct stuscore aim = input();

		for(i=0;;++i){
           if(aim.score<stud[i].score)
                break;
           if(i>=count)
                break;
		}
		//此时的i代表了应该插入的索引

		//前i个不变
		for(j=0;j<i;++j)
            stuCopy[j] = stud[j];

            stuCopy[i] = aim;

		//后面每一个是前面一个
		for(j=i+1;j<count+1;++j)
            stuCopy[j] = stud[j-1];

        stud = stuCopy;
	}

	void del(struct stuscore stud[], int count)			/* 删除函数 */
	{
        int i,j;
        struct stuscore stuCopy[count-1];
        printf("请输入删除第几个学生\n");
        scanf("%d",&i);

		//i个（索引i-1）消失 其他不变序
		for(j=0;j<i-1;++j)
          	 		 stuCopy[j] = stud[j];
		for(j=i-1;j<count-1;++j)
           			 stuCopy[j] = stud[j+1];

        stud = stuCopy;
	}

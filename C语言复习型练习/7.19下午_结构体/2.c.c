//2 从键盘上输入30个学生的成绩信息（包括学号、姓名、成绩），按照学生成绩由高到低排序输出。
    #include "stdio.h"
	int main( )
	{
		struct stuscore
		{
			int num;			/* 学号 */
			char name[20];		/* 姓名 */
			float score;		/* 课程成绩 */
		};
		struct stuscore stus[30];	/* 声明一个结构体数组变量 */
		struct stuscore t;			/* 声明一个结构体变量用于交换数据 */
		int i, j;
		printf("请输入学生信息。");
		for(i = 1; i <= 30; i++)
		{
			/* 输入30个学生的基本信息*/
            printf("请输入第%d个学生的学号：",i);
            scanf("%d",&stus[i].num);
            getchar();
            printf("请输入第%d个学生的姓名：",i);
            gets(stus[i].name);
            printf("请输入第%d个学生的成绩：",i);
            scanf("%f",&stus[i].score);
		}
		/* 使用冒泡排序法对输入的30个学生信息按成绩由高到低排序 */
		int pass;
        for(pass=1;pass<30;++pass){
            for(i=0;i<30-pass;++i){
                if(stus[i].score>stus[i+1].score){
                t = stus[i];
                stus[i] = stus[i+1];
                stus[i+1] = t;
                }
            }
        }
		/* 输出排序后的学生成绩信息 */
		for(i=0;i<30;++i){
            printf("%d %s %f",stus[i].num,stus[i].name,stus[i].score);
		}
		return 0;
	}




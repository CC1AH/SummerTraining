//1、分配一块区域，输入一个学生数据。
#include "stdio.h"
#include "stdlib.h"					/* 包含malloc的头文件 */
	int main( )
	{
		struct stuscore
		{
			int num;
			char *name;
			float score;
		} *ps;
		ps = (struct stuscore*)malloc(sizeof(struct stuscore));

        printf("请输入学生学号\n");
        scanf("%d",&(ps->num));
        getchar();
        printf("请输入学生姓名\n");
        gets(ps->name);
        printf("请输入学生分数\n");
        scanf("%f",&(ps->score));

		free(ps);
		return 0;
	}


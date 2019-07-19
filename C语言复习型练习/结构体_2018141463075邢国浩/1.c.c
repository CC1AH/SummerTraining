//1、定义学生成绩的结构体类型，输入三个学生的信息，并将三个学生信息按照成绩由高到低的顺序输出。
#include "stdio.h"
int main()
{
    struct stuscore
    {
        int num;
        char name[20];
        float score;
    } ss1, ss2, ss3, temp;
        printf("请输入第1个学生的学号：");
        scanf("%d",&ss1.num);
        getchar();
        printf("请输入第1个学生的姓名：");
        gets(ss1.name);
        printf("请输入第1个学生的成绩：");
        scanf("%f",&ss1.score);

		printf("请输入第2个学生的学号：");
        scanf("%d",&ss2.num);
        getchar();
        printf("请输入第2个学生的姓名：");
        gets(ss2.name);
        printf("请输入第2个学生的成绩：");
        scanf("%f",&ss2.score);

        printf("请输入第3个学生的学号：");
        scanf("%d",&ss3.num);
        getchar();
        printf("请输入第3个学生的姓名：");
        gets(ss3.name);
        printf("请输入第3个学生的成绩：");
        scanf("%f",&ss3.score);

    //从高到低排序
    struct stuscore s[3] = {ss1,ss2,ss3};
    int pass,i;
    for(pass=1;pass<3;++pass){
        for(i=0;i<3-pass;++i){
            if(s[i].score<s[i+1].score){
                 temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
    }
		for(i=0;i<3;++i){
            printf("%d %s %f",s[i].num,s[i].name,s[i].score);
		}

    return 0;
}



#include "stdio.h"
#include "stdlib.h"
struct Stuscore
{
		int  num;			/* 学号 */
		char name[20];		/* 姓名 */
		float score;		/* 课程成绩 */
};
void sort(struct Stuscore stus[], int count)		/* 排序函数 */
	{
		/*  冒泡排序法 */
		int pass,i;
		struct Stuscore t;
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
int main( )
{
    FILE* file;
    if((file = fopen("scorein.dat","r")) == NULL){
        printf("文件打开失败");
        return 1;
    }

    int i;
    double sum = 0.0;
    struct Stuscore stuscore[50];
    for(i=0;;++i){
    if(fscanf(file,"%d %s %f",&stuscore[i].num,stuscore[i].name,&stuscore[i].score)==3){
        sum += stuscore[i].score;
    }
    else{
        break;
        }
    }
    int n = i;

    double ave = sum/n;
    printf("从高到低的排序是：\n");
    sort(stuscore,n);
     for(i=0;i<n;++i)
    printf("%d %s %f\n",stuscore[i].num,stuscore[i].name,stuscore[i].score);
    printf("平均分：%f",ave);

    int upper = 0;
    int lower = 0;
    for(i=0;i<n;++i){
        if(stuscore[i].score<ave)
            lower++;
        if(stuscore[i].score>ave)
            upper++;
    }

    FILE* outFile;
    if((outFile = fopen("scoreout.dat","w"))==NULL){
        printf("文件打开失败");
        return 1;
    }
    fprintf(outFile,"平均成绩是%f\n",ave);
    fprintf(outFile,"高于平均成绩的人数是%d\n",upper);
    fprintf(outFile,"低于平均成绩的人数是%d\n",lower);
    printf("\n文件操作完毕");
}



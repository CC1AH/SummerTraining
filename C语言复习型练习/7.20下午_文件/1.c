
#include "stdio.h"
#include "stdlib.h"
struct Stuscore
{
		int  num;			/* ѧ�� */
		char name[20];		/* ���� */
		float score;		/* �γ̳ɼ� */
};
void sort(struct Stuscore stus[], int count)		/* ������ */
	{
		/*  ð������ */
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
        printf("�ļ���ʧ��");
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
    printf("�Ӹߵ��͵������ǣ�\n");
    sort(stuscore,n);
     for(i=0;i<n;++i)
    printf("%d %s %f\n",stuscore[i].num,stuscore[i].name,stuscore[i].score);
    printf("ƽ���֣�%f",ave);

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
        printf("�ļ���ʧ��");
        return 1;
    }
    fprintf(outFile,"ƽ���ɼ���%f\n",ave);
    fprintf(outFile,"����ƽ���ɼ���������%d\n",upper);
    fprintf(outFile,"����ƽ���ɼ���������%d\n",lower);
    printf("\n�ļ��������");
}



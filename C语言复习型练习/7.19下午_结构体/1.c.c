//1������ѧ���ɼ��Ľṹ�����ͣ���������ѧ������Ϣ����������ѧ����Ϣ���ճɼ��ɸߵ��͵�˳�������
#include "stdio.h"
int main()
{
    struct stuscore
    {
        int num;
        char name[20];
        float score;
    } ss1, ss2, ss3, temp;
        printf("�������1��ѧ����ѧ�ţ�");
        scanf("%d",&ss1.num);
        getchar();
        printf("�������1��ѧ����������");
        gets(ss1.name);
        printf("�������1��ѧ���ĳɼ���");
        scanf("%f",&ss1.score);

		printf("�������2��ѧ����ѧ�ţ�");
        scanf("%d",&ss2.num);
        getchar();
        printf("�������2��ѧ����������");
        gets(ss2.name);
        printf("�������2��ѧ���ĳɼ���");
        scanf("%f",&ss2.score);

        printf("�������3��ѧ����ѧ�ţ�");
        scanf("%d",&ss3.num);
        getchar();
        printf("�������3��ѧ����������");
        gets(ss3.name);
        printf("�������3��ѧ���ĳɼ���");
        scanf("%f",&ss3.score);

    //�Ӹߵ�������
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


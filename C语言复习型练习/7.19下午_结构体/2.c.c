//2 �Ӽ���������30��ѧ���ĳɼ���Ϣ������ѧ�š��������ɼ���������ѧ���ɼ��ɸߵ������������
    #include "stdio.h"
	int main( )
	{
		struct stuscore
		{
			int num;			/* ѧ�� */
			char name[20];		/* ���� */
			float score;		/* �γ̳ɼ� */
		};
		struct stuscore stus[30];	/* ����һ���ṹ��������� */
		struct stuscore t;			/* ����һ���ṹ��������ڽ������� */
		int i, j;
		printf("������ѧ����Ϣ��");
		for(i = 1; i <= 30; i++)
		{
			/* ����30��ѧ���Ļ�����Ϣ*/
            printf("�������%d��ѧ����ѧ�ţ�",i);
            scanf("%d",&stus[i].num);
            getchar();
            printf("�������%d��ѧ����������",i);
            gets(stus[i].name);
            printf("�������%d��ѧ���ĳɼ���",i);
            scanf("%f",&stus[i].score);
		}
		/* ʹ��ð�����򷨶������30��ѧ����Ϣ���ɼ��ɸߵ������� */
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
		/* ���������ѧ���ɼ���Ϣ */
		for(i=0;i<30;++i){
            printf("%d %s %f",stus[i].num,stus[i].name,stus[i].score);
		}
		return 0;
	}




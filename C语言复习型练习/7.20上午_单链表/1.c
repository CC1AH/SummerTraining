//1������һ����������һ��ѧ�����ݡ�
#include "stdio.h"
#include "stdlib.h"					/* ����malloc��ͷ�ļ� */
	int main( )
	{
		struct stuscore
		{
			int num;
			char *name;
			float score;
		} *ps;
		ps = (struct stuscore*)malloc(sizeof(struct stuscore));

        printf("������ѧ��ѧ��\n");
        scanf("%d",&(ps->num));
        getchar();
        printf("������ѧ������\n");
        gets(ps->name);
        printf("������ѧ������\n");
        scanf("%f",&(ps->score));

		free(ps);
		return 0;
	}


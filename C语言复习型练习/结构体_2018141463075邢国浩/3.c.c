/*3�� ��дһ������ʵ��ѧ���ɼ���������������30�ˣ���ÿ��ѧ����Ϣ����ѧ�š��������γ̳ɼ���
Ҫ��a.����ѧ���ɼ��ɸߵ�������
b.��������ѧ���ɼ����в���һ��ѧ������Ϣ��Ҫ��������Ȼ���ֳɼ�������
c.Ҫ������ָ����ѧ������ѧ����Ϣ����ɾ����ѧ����ɾ����ĳɼ���������
������ʹ�ýṹ�屣��ÿ��ѧ������Ϣ������ѧ�š��������γ̵ĳɼ�,ʹ�ýṹ�����鱣������ѧ������Ϣ*/
#include "stdio.h"
struct stuscore
{
		int  num;			/* ѧ�� */
		char name[20];		/* ���� */
		float score;		/* �γ̳ɼ� */
};
	struct stuscore stus[30]; /* ����һ���ṹ���������Ϊȫ�ֱ��� */
	struct stuscore input(); /* ����ѧ���ɼ���Ϣ��������������ֵΪ�ṹ���� */
	void display(struct stuscore stud[], int count);  /* ��ʾѧ����Ϣ���� */
	void sort(struct stuscore stud[], int count);     /* ѧ���ɼ������� */
	void insert(struct stuscore stud[], int count);    /* ���뺯�� */
	void del(struct stuscore stud[], int count);       /* ɾ������ */
	int main( )
	{
		int i, count;
		char ch;
		printf("������ѧ���ɼ���Ϣ��");
		for (i = 0; i < 4; i++)
		{
			stus[i] = input();                        /* ����¼����Ϣ���� */
		}
		count = 4;
		printf("\n���ɼ�����ǰ��ѧ���ɼ���Ϣ���£�");
		display(stus, count);                          /* ������ʾ��Ϣ���� */
		sort(stus, count);                             /* ���������� */
		printf("\n���ɼ�������ѧ���ɼ���Ϣ���£�");
		display(stus, count);
		printf("\n\n�Ƿ�ȷ�ϲ�����ѧ����Ϣ?(y or n)");
		getchar();
		scanf("%c", &ch);
		if(ch == 'Y' || ch == 'y')
		{
			insert(stus, count);			/* ���ò�����Ϣ���� */
			count++;
			printf("\n������ѧ����Ϣ���ѧ���ɼ���Ϣ���£�");
			display(stus,count);
		}
		printf("\n\n�Ƿ�Ҫɾ��ĳ��ѧ��?(y or n)");
		getchar();
		scanf("%c", &ch);
		if(ch == 'Y' || ch == 'y')
		{
			del(stus,count);				/* ����ɾ����Ϣ���� */
			count--;
			printf("\nɾ����ѧ���ɼ���Ϣ���£�");
			display(stus, count);
		}
		return 0;
	}

	struct stuscore input( )				/* ¼��ѧ���ɼ���Ϣ���� */
	{
        struct stuscore stu;
			/* ����ѧ���Ļ�����Ϣ*/
            printf("������ѧ����ѧ�ţ�");
            scanf("%d",&stu.num);
            getchar();
            printf("������ѧ����������");
            gets(stu.name);
            printf("������ѧ���ĳɼ���");
            scanf("%f",&stu.score);
		return stu;
	}

	/* ��ʾѧ���ɼ���Ϣ���� */
	void display(struct stuscore stud[], int count)
	{
	    int i;
		for(i=0;i<count;++i){
            printf("%d %s %f\n",stus[i].num,stus[i].name,stus[i].score);
		}
	}

	void sort(struct stuscore stud[], int count)		/* ������ */
	{
		/*  ð������ */
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

	void insert(struct stuscore stud[], int count)		/* ���뺯�� */
	{
	    struct stuscore stuCopy[count+1];
		/* ����һ��ѧ������Ϣ��Ҫ�������ѧ����Ϣ��Ȼ���� */
		int j,i;
        printf("�������ѧ����Ϣ\n");
        struct stuscore aim = input();

		for(i=0;;++i){
           if(aim.score<stud[i].score)
                break;
           if(i>=count)
                break;
		}
		//��ʱ��i������Ӧ�ò��������

		//ǰi������
		for(j=0;j<i;++j)
            stuCopy[j] = stud[j];

            stuCopy[i] = aim;

		//����ÿһ����ǰ��һ��
		for(j=i+1;j<count+1;++j)
            stuCopy[j] = stud[j-1];

        stud = stuCopy;
	}

	void del(struct stuscore stud[], int count)			/* ɾ������ */
	{
        int i,j;
        struct stuscore stuCopy[count-1];
        printf("������ɾ���ڼ���ѧ��\n");
        scanf("%d",&i);

		//i��������i-1����ʧ ����������
		for(j=0;j<i-1;++j)
          	 		 stuCopy[j] = stud[j];
		for(j=i-1;j<count-1;++j)
           			 stuCopy[j] = stud[j+1];

        stud = stuCopy;
	}

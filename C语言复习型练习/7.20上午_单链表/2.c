//2������һ������������������в��ҡ����롢ɾ��������
/* ������������������� */
	#include "stdio.h"
	#include "string.h"
	#include "stdlib.h"						/* ����malloc��ͷ�ļ� */
	#define LEN sizeof (struct stuscore)
	struct  stuscore						/* ��������ṹ���� */
	{
		int  num;
		char  name[20];
		float  score;						/* ��������ṹ������ */
		struct  stuscore  *next;			/* ��������ṹָ���� */
	};
    typedef struct stuscore Stuscore;
    typedef struct stuscore* StuscorePtr;

    struct stuscore *creat(struct stuscore *head);		/* ���������� */
    void *search(struct stuscore *head);				/* ���������� */
    struct stuscore *insert(struct stuscore *head);		/* ���������� */
    struct stuscore *del (struct stuscore *head);		/* ɾ�������� */
    void output(struct stuscore *head);					/* ��������� */
	int main( )								/* ������ */
	{

		struct  stuscore  *head;			/* headΪ�����ͷָ�� */
		int c, flag = 1;
		head = NULL;
		while(flag)
		{
		/* ����Ļ�ϻ�һ�����˵� */
			printf("/**********����Ļ�������**********/\n\n");
			printf("  1:  creat\n\n");
			printf("  2:  search\n\n");
			printf("  3:  insert\n\n");
			printf("  4:  delete\n\n");
			printf("  5:  output\n\n");
			printf("  0:  exit\n\n");
			printf("/**********************************/\n\n");
			//printf("please select:");
			//scanf("%d",&c);				/* ����ѡ���� */
            head = creat(head);
            output(head);
            search(head);
            head = insert(head);
            output(head);
            head = del(head);
            output(head);
        }
	}
        struct stuscore *creat(struct stuscore *head)
        {/* ���������� */
            StuscorePtr ps = NULL;
            StuscorePtr now = NULL;

            ps = malloc(sizeof(Stuscore));
            ps->next = NULL;
            printf("������ѧ��ѧ�ţ�����ѧ��Ϊ0����ֹ������ѧ����������¼���ڣ�\n");
            scanf("%d",&(ps->num));
            getchar();
            printf("������ѧ������\n");
            gets(ps->name);
            printf("������ѧ������\n");
            scanf("%f",&(ps->score));
            //printf("%d %s %f\n",ps->num,ps->name,ps->score);
            while(ps->num!=0){
                if(head == NULL){
                    head = ps;
                }
                else{
                    now -> next = ps;
                }
                now = ps;
            ps = malloc(sizeof(Stuscore));
            ps->next = NULL;
            printf("������ѧ��ѧ��,����ѧ��Ϊ0����ֹ������ѧ����������¼���ڣ�\n");
            scanf("%d",&(ps->num));
            getchar();
            printf("������ѧ������\n");
            gets(ps->name);
            printf("������ѧ������\n");
            scanf("%f",&(ps->score));

            //printf("%d %s %f\n",ps->num,ps->name,ps->score);
           }
           return head;
        }
		void *search(struct stuscore *head){/* ���������� */
		    int num;
		    printf("����������Ҫ���ҵ�ѧ��ѧ��\n");
            scanf("%d",&num);

            StuscorePtr temp;
            temp = head;
                while(temp->num!=num&&temp->next!=NULL){
                    temp=temp->next;
                }
            printf("������Ϣ��%d %s %f\n",temp->num,temp->name,temp->score);
		}
		struct stuscore *insert(struct stuscore *head){/* ���������� */;
        //�û�������Ϣ ���뵽��i���ڵ��
        //ʾ�����Ǹ���struct node*������ ���˴����������鷳
        int n;
        printf("����������ѧ����Ϣ�ڵڼ���ѧ��֮ǰ");
        scanf("%d",&n);
        StuscorePtr ps = malloc(sizeof(Stuscore));
        ps->next = NULL;
            printf("������ѧ��ѧ��\n");
            scanf("%d",&(ps->num));
            getchar();
            printf("������ѧ������\n");
            gets(ps->name);
            printf("������ѧ������\n");
            scanf("%f",&(ps->score));

		    StuscorePtr last,aim;
		    aim = head;
		    int i;
		    for(i=1;i<n;++i){
                last = aim;
                aim = aim->next;
		    }

        if(n==1){
            ps->next=head;
            head=ps;
        }
        else{
            last->next=ps;
            ps->next=aim;
        }
        return head;
    }
struct stuscore *del (struct stuscore *head){/* ɾ�������� */
                int n;
        printf("����������ɾ����ѧ���ǵڼ���:");
        scanf("%d",&n);

        //�ҵ�Ŀ��ڵ�temp ��һ���ڵ��Ϊlast
        StuscorePtr temp,last;
        temp = head;
        int i;
        for(i=1;i<n;++i){
            last=temp;
            temp=temp->next;
        }


        //ͷ�ڵ�ֱ�Ӹı�Ϊ���
        if(temp==head){
            head = head->next;
        }
        //������һ���ڵ��ǰ��ָ�򱾽ڵ�ĺ��
        else{
            last->next=temp->next;
        }
        //�ͷű��ڵ�ռ�
        free(temp);
            return head;
		}		
	void output(struct stuscore *head)			/* ��������� */
		{
		    StuscorePtr temp = head;
		    while(temp!=NULL){
                printf("%d %s %f ->\n",temp->num,temp->name,temp->score);
                temp = temp->next;
		    }
   }


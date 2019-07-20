//2、创建一个单向链表，并对其进行查找、插入、删除操作。
/* 链表基本操作的主函数 */
	#include "stdio.h"
	#include "string.h"
	#include "stdlib.h"						/* 包含malloc的头文件 */
	#define LEN sizeof (struct stuscore)
	struct  stuscore						/* 定义链表结构类型 */
	{
		int  num;
		char  name[20];
		float  score;						/* 定义链表结构数据域 */
		struct  stuscore  *next;			/* 定义链表结构指针域 */
	};
    typedef struct stuscore Stuscore;
    typedef struct stuscore* StuscorePtr;

    struct stuscore *creat(struct stuscore *head);		/* 创建链表函数 */
    void *search(struct stuscore *head);				/* 查找链表函数 */
    struct stuscore *insert(struct stuscore *head);		/* 插入链表函数 */
    struct stuscore *del (struct stuscore *head);		/* 删除链表函数 */
    void output(struct stuscore *head);					/* 输出链表函数 */
	int main( )								/* 主函数 */
	{

		struct  stuscore  *head;			/* head为链表的头指针 */
		int c, flag = 1;
		head = NULL;
		while(flag)
		{
		/* 在屏幕上画一个主菜单 */
			printf("/**********链表的基本操作**********/\n\n");
			printf("  1:  creat\n\n");
			printf("  2:  search\n\n");
			printf("  3:  insert\n\n");
			printf("  4:  delete\n\n");
			printf("  5:  output\n\n");
			printf("  0:  exit\n\n");
			printf("/**********************************/\n\n");
			//printf("please select:");
			//scanf("%d",&c);				/* 输入选择项 */
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
        {/* 创建链表函数 */
            StuscorePtr ps = NULL;
            StuscorePtr now = NULL;

            ps = malloc(sizeof(Stuscore));
            ps->next = NULL;
            printf("请输入学生学号，输入学号为0以终止链表（该学生将不被记录在内）\n");
            scanf("%d",&(ps->num));
            getchar();
            printf("请输入学生姓名\n");
            gets(ps->name);
            printf("请输入学生分数\n");
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
            printf("请输入学生学号,输入学号为0以终止链表（该学生将不被记录在内）\n");
            scanf("%d",&(ps->num));
            getchar();
            printf("请输入学生姓名\n");
            gets(ps->name);
            printf("请输入学生分数\n");
            scanf("%f",&(ps->score));

            //printf("%d %s %f\n",ps->num,ps->name,ps->score);
           }
           return head;
        }
		void *search(struct stuscore *head){/* 查找链表函数 */
		    int num;
		    printf("请输入你想要查找的学生学号\n");
            scanf("%d",&num);

            StuscorePtr temp;
            temp = head;
                while(temp->num!=num&&temp->next!=NULL){
                    temp=temp->next;
                }
            printf("基本信息：%d %s %f\n",temp->num,temp->name,temp->score);
		}
		struct stuscore *insert(struct stuscore *head){/* 插入链表函数 */;
        //用户输入信息 插入到第i个节点后
        //示例中是给了struct node*参数的 但此处传参略显麻烦
        int n;
        printf("请输入插入的学生信息在第几个学生之前");
        scanf("%d",&n);
        StuscorePtr ps = malloc(sizeof(Stuscore));
        ps->next = NULL;
            printf("请输入学生学号\n");
            scanf("%d",&(ps->num));
            getchar();
            printf("请输入学生姓名\n");
            gets(ps->name);
            printf("请输入学生分数\n");
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
struct stuscore *del (struct stuscore *head){/* 删除链表函数 */
                int n;
        printf("请输入你想删除的学生是第几个:");
        scanf("%d",&n);

        //找到目标节点temp 上一个节点记为last
        StuscorePtr temp,last;
        temp = head;
        int i;
        for(i=1;i<n;++i){
            last=temp;
            temp=temp->next;
        }


        //头节点直接改变为后继
        if(temp==head){
            head = head->next;
        }
        //否则上一个节点的前驱指向本节点的后继
        else{
            last->next=temp->next;
        }
        //释放本节点空间
        free(temp);
            return head;
		}		
	void output(struct stuscore *head)			/* 输出链表函数 */
		{
		    StuscorePtr temp = head;
		    while(temp!=NULL){
                printf("%d %s %f ->\n",temp->num,temp->name,temp->score);
                temp = temp->next;
		    }
   }


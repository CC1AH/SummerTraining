#ifndef BASICFUNCTIONS_H_INCLUDED
#define BASICFUNCTIONS_H_INCLUDED
/**
* ���ļ������˵��Ӵǵ�Ļ�������ģ�飨��ʼ�����˵���ȫ���б���Ӣ��������
* @author �Ϲ���
* 2019/7/21
* copyright reserved
*/

//�����ĺ���ԭ��
nodeptr initial(nodeptr list);
int choseMenu();
void listAll(nodeptr list);

void searchInEnglish(nodeptr list);
void searchInChinese(nodeptr list);



//��������ԭ�͵Ļ�������
/**
* ��ʼ��
* �Խ��ܵ�ָ��Ϊͷ����һ����������
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr initial(nodeptr list){
	nodeptr add;
	list=(struct listNode *)malloc(sizeof(struct listNode));
	if(list!=NULL)
	{
		list->next=NULL;
	}

	//ͳ�ƴ�������
	int num=0;

	FILE *readFile = fopen("dictionary.txt","r");
	if(readFile==NULL)
    {
        printf("�ǵ��ļ���ʧ��\n");
        return list;
    }
	else
	{
	    printf("-----------Ӧ�ó���������----------");
		while(!feof(readFile))
		{
			add=(struct listNode *)malloc(sizeof(struct listNode));
			if(add!=NULL)
			{
				num=fscanf(readFile,"%s\t%s\n",(add->data).word,(add->data).mean);
				//����ֵ��add�����ݸ���С��2������ѭ��
				if(num<2)
				{
				    printf("�����������");
					break;
				}
				//Ӣ�ĵ�������ĸ����ĸ���˳���add�����ݲ��뵽list��
				InsertList(list,add);
			}
		}
		printf("\n�ֵ���������");
	}
	return list;
}

/**
* ѡ��˵�
* չʾ�˵��������û���ѡ���ҷ���ѡ��
* @return int
*/
int choseMenu(){

    printf("\n\n\n                      ��ӭ-----^-^-----------^-^------------^-^-----��ӭ\n");
	printf("                           ____________________________________________________\n");
	printf("                        |------------------(0)Ӣ�뺺����-----------------------|\n");
	printf("                        |------------------(1)����Ӣ����-----------------------|\n");
	printf("                        |------------------(2)���ӵ���-------------------------|\n");
	printf("                        |------------------(3)ɾ������-------------------------|\n");
	printf("                        |------------------(4)�޸�����-------------------------|\n");
	printf("                        |------------------(5)�ղؼ�---------------------------|\n");
	printf("                        |------------------(6)��д-----------------------------|\n");
	printf("                        |------------------(7)�г��ʿ���ȫ�����ʼ�������-------|\n");
	printf("                        |------------------(8)�˳�����-------------------------|\n");
	printf("                        |__________________________________________________|\n");
	printf("\n");

	int choose;
	fflush(stdin);
	printf("�����������������(0-8)��");

	//���û���ѡ����0-1֮��ķ�Χ����ʾ�û������������������
	while((scanf("%d", &choose)!=1) || (choose<0||choose>8))
	{
		printf("�����������������(0-8)��");
		fflush(stdin);
	}
    return choose;
}

/**
* �г�ȫ��
* �г�listΪͷ�����µ�ȫ��������Ϣ
* @param list:nodeptr
*/
void listAll(nodeptr list){
    nodeptr tmp = list->next;
    while(tmp!=NULL){
        printf("%s %s\n",(tmp->data).word,(tmp->data).mean);
        tmp = tmp->next;
    }
}

/**
* Ӣ������
* ��listΪͷ�������������е��ʿ�ͷ������������ؼ��ֵĵ��ʼ�����
* @param list:nodeptr
*/
void searchInEnglish(nodeptr list)
{
	nodeptr listNext;
	//�����û������Ӣ���ַ�������
	char input[WORDNUM+1];
	//�����û������Ӣ���ַ��������ĳ���
	int inputLen = 0;
	//����Ӣ�ĵ������û�������ַ���������ƥ�����
	int matchNum = 0;

	listNext=list->next;

	fflush(stdin);
	printf("������Ӣ�ĵ��ʵĹؼ��ʣ�");
	scanf("%s", &input);

	//�����û�����Ӣ�ĵ��ʵĹؼ��ʵĳ���
	inputLen=strlen(input);

	printf("|-------------------�����������-------------------|\n");
	printf("%10s %10s\n","Ӣ�ĵ���","���Ľ���");

	while(listNext!=NULL)
	{
		matchNum=memcmp((listNext->data).word,input,inputLen);
		if(matchNum==0)
		{
		    printf("%10s %10s\n",(listNext->data).word,(listNext->data).mean);

		}
		listNext=listNext->next;
	}
}

/**
* ��������
* ��listΪͷ�����������������������������ؼ��ֵĵ��ʼ�����
* @param list:nodeptr
*/
void searchInChinese(nodeptr list){
	nodeptr listNext;
	//�����û�����������ַ�������
	char input[WORDNUM+1];
	//����Ƿ��ҵ��˶�Ӧ��Ŀ
    int count = 0;

	listNext=list->next;

	fflush(stdin);
	printf("���������ĵ��ʵĹؼ��ʣ�");
	scanf("%s", &input);

	printf("|-------------------�����������-------------------|\n");
	printf("%10s %10s\n","Ӣ�ĵ���","���Ľ���");

	while(listNext!=NULL)
	{
		if(contains((listNext->data).mean,input)){
            printf("%10s %10s\n",(listNext->data).word,(listNext->data).mean);
            count++;
		}
        listNext=listNext->next;
	}
	if(count == 0){
        printf("ô���ҵ�����Ҫ�ҵĵ���");
	}
}
#endif // BASICFUNCTIONS_H_INCLUDED

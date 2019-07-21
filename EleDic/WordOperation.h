#ifndef WORDOPERATION_H_INCLUDED
#define WORDOPERATION_H_INCLUDED
#define BASICSTRUCTRUE_H_INCLUDED
/**
* ���ļ������˵��Ӵǵ�ĵ��ʲ���ģ�飨���ʵ������ģ�ɾ��
* @author �Ϲ���
* 2019/7/21
* copyright reserved
*/

//�����ĺ���ԭ��
nodeptr addWord(nodeptr list);
nodeptr deleteWord(nodeptr list);
nodeptr modifyWord(nodeptr list);



//��������ԭ�͵Ļ�������
/**
* ������
* �Խ��ܵ�ָ��Ϊͷ����ĸ˳��������������һ������
* �������û����ӵĵ��ʣ������д�����֣����ļ���
* �����������֡�ֻ�������������ӡ�
* �����ղؼй����н������û����ļ�������Լ��ĵ���
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr addWord(nodeptr list){
    struct content input;
    nodeptr judge;
    nodeptr add;

	fflush(stdin);
    printf("������һ��Ӣ�ĵ��ʣ�");
    scanf("%s",&input.word);
    printf("���������Ӣ�ĵ��ʵĽ��ͣ�");
	scanf("%s", &input.mean);

    //���Ƿ��Ѿ�����
    if((judge=ExistOrNot(list,input.word))==NULL)
    {
		//�½�add
        add=(nodeptr)malloc(sizeof(node));
        if(add != NULL)
        {
            strcpy((add->data).word,input.word);
            strcpy((add->data).mean,input.mean);
            //��add�е�Ӣ�ĵ�������ĸ����ĸ��˳�����list������
            InsertList(list,add);
        }
    }
    else
    {
        printf("�ô����Ѵ���\n");
        printf("%10s %10s\n","Ӣ�ĵ���","���Ľ���");
        printf("%10s %10s\n",(judge->data).word,(judge->data).mean);
    }
    return list;
}

/**
* ɾ������
* �Խ��ܵ�ָ��Ϊͷ��������ɾ��һ����  �������û�ɾ��
* �ĵ��ʣ����ļ��н����������֡�ֻ�������������ӡ���
* ���ղؼй����н������û����ļ���ɾ���Լ��ĵ���
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr deleteWord(nodeptr list){
    char deleteWord[WORDNUM+1];

	fflush(stdin);
    printf("������Ҫɾ����Ӣ�ĵ��ʣ�");
	scanf("%s", &deleteWord);

	//Ѱ����Ҫɾ���ڵ��ǰ���ͺ��
	nodeptr aim,last;
	aim = list;
	while(strcmp((aim->data).word,deleteWord)!=0&&aim!=NULL){
        last = aim;
        aim = aim->next;
	}

	//���û��������ڵĽڵ�
	if(aim==NULL)
	{
		printf("�����ڸõ���\n");
	}
	//������ڷǿյĺϹ�ڵ�
	else{
        last->next = aim->next;
        free(aim);
        printf("����ɾ���ɹ���");
	}

	return list;
}

/**
* �޸ĵ���
* �Խ��ܵ�ָ��Ϊͷ���������޸�һ������  �������û���
* �ĵ��ʣ����ļ��н����������֡�ֻ�����������޸ġ���
* ���ղؼй����н������û����ļ����޸��Լ��ĵ���
* @param  list:nodeptr
* @return nodeptr
*/
nodeptr modifyWord(nodeptr list){
    struct content edit;
    nodeptr judge;
    char editWord[WORDNUM+1];

	fflush(stdin);
    printf("������Ҫ�޸ĵ�Ӣ�ĵ��ʣ�");
	scanf("%s", &editWord);

    //���Ƿ����
    if((judge=ExistOrNot(list,editWord))!=NULL)
    {
        fflush(stdin);
        printf("������Ҫ�޸ĳɵ�Ӣ�ĵ��ʣ�");
		scanf("%s", &edit.word);
        printf("������Ҫ�޸ĳɵ�Ӣ�ĵ��ʵ����Ľ��ͣ�");
		scanf("%s", &edit.mean);
        strcpy((judge->data).word,edit.word);
        strcpy((judge->data).mean,edit.mean);
		printf("�޸ĳɹ�");
    }
    else
        printf("�����ڸô���\n");
    return list;
}

#endif // WORDOPERATION_H_INCLUDED

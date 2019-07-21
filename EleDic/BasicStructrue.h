#ifndef BASICSTRUCTRUE_H_INCLUDED
#define BASICSTRUCTRUE_H_INCLUDED
/**
* ���ļ������˵��Ӵǵ�Ļ����ṹģ�飨���ʵ������ݴ洢ģ�鼰����ڵ㣩
* @author �Ϲ���
* 2019/7/21
* copyright reserved
*/


//���ʳ��ȣ����Գ��ȣ����������峤�ȵ����ֵ
#define WORDNUM 30
#define MEANNUM 30

//���ʽṹ����
struct content
{
    char word[WORDNUM+1];
    char mean[MEANNUM+1];
};

//����
struct listNode
{
    struct content data;
    struct listNode *next;
};

typedef struct listNode node;
typedef struct listNode* nodeptr;

//�����ĺ���ԭ��
nodeptr ExistOrNot(nodeptr list,char* word);
void FreeList(nodeptr list);
void InsertList(nodeptr list,nodeptr insert);



//��������ԭ�͵Ļ�������
/**
* ��������
* ����ʵ����list����������в���ڶ����ڵ�Ĳ���
* �����λ����ѭ��ĸ����
* @param list:nodeptr, insert:nodeptr
*/
void InsertList(nodeptr list,nodeptr insert)
{
    nodeptr listHead=list;
    //���������ǰһ���������ʱȸô������ʵ�ASCIIС����һ���������ʱȸô������ʵ�ASCII��
    while(listHead->next!=NULL&&strcmp((listHead->next->data).word,(insert->data).word)<0)
    {
        listHead=listHead->next;
    }
    insert->next=listHead->next;
    listHead->next=insert;
}

/**
* �ͷ�����
* ��list����������ͷ�
* @param list:nodeptr
*/
void FreeList(nodeptr list)
{
    nodeptr listHead=list;

    //����ͷ�����ռ�
    while(listHead->next!=NULL)
    {
        listHead=listHead->next;
        free(list);
        list=listHead;
    }
    free(listHead);
}

/**
* �жϴ���
* �ж�list����������Ƿ����ָ�����ʡ�
* @param list:nodeptr,word:char*
*/
nodeptr ExistOrNot(nodeptr list,char* word){
    nodeptr temp;
    temp = list;
    //ѭ���Ƚ��жϴ�����
    while(temp!=NULL){
        if(strcmp((temp->data).word,word) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
#endif // BASICSTRUCTRUE_H_INCLUDED

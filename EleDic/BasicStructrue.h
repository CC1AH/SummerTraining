#ifndef BASICSTRUCTRUE_H_INCLUDED
#define BASICSTRUCTRUE_H_INCLUDED
/**
* 该文件描述了电子辞典的基本结构模块（单词单个内容存储模块及链表节点）
* @author 邢国浩
* 2019/7/21
* copyright reserved
*/


//单词长度（词性长度）和中文释义长度的最大值
#define WORDNUM 30
#define MEANNUM 30

//单词结构内容
struct content
{
    char word[WORDNUM+1];
    char mean[MEANNUM+1];
};

//链表
struct listNode
{
    struct content data;
    struct listNode *next;
};

typedef struct listNode node;
typedef struct listNode* nodeptr;

//包含的函数原型
nodeptr ExistOrNot(nodeptr list,char* word);
void FreeList(nodeptr list);
void InsertList(nodeptr list,nodeptr insert);



//包含函数原型的基本内容
/**
* 插入链表
* 可以实现向list代表的链表中插入第二个节点的操作
* 插入的位置遵循字母排序
* @param list:nodeptr, insert:nodeptr
*/
void InsertList(nodeptr list,nodeptr insert)
{
    nodeptr listHead=list;
    //插入词条（前一个词条单词比该词条单词的ASCII小，后一个词条单词比该词条单词的ASCII大）
    while(listHead->next!=NULL&&strcmp((listHead->next->data).word,(insert->data).word)<0)
    {
        listHead=listHead->next;
    }
    insert->next=listHead->next;
    listHead->next=insert;
}

/**
* 释放链表
* 向list代表的链表释放
* @param list:nodeptr
*/
void FreeList(nodeptr list)
{
    nodeptr listHead=list;

    //逐个释放链表空间
    while(listHead->next!=NULL)
    {
        listHead=listHead->next;
        free(list);
        list=listHead;
    }
    free(listHead);
}

/**
* 判断存在
* 判断list代表的链表是否包含指定单词。
* @param list:nodeptr,word:char*
*/
nodeptr ExistOrNot(nodeptr list,char* word){
    nodeptr temp;
    temp = list;
    //循环比较判断存在性
    while(temp!=NULL){
        if(strcmp((temp->data).word,word) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
#endif // BASICSTRUCTRUE_H_INCLUDED

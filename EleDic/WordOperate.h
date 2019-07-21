#ifndef WORDOPERATE_H_INCLUDED
#define WORDOPERATE_H_INCLUDED
/**
*@author 邢国浩
*2019/7/21
*定义存储数据链表的基本格式和信息
*定义对于链表结构基本的增加 删除 插入 操作
*定义对于单词的增加 删除 插入 功能模块
*/

//单词长度（词性长度）和中文释义长度的最大值
#define WORDNUM 30
#define MEANNUM 30

//数据内容
struct content
{
    //设置英文单词长度
    char word[WORDNUM+1];
    //设置中文释义长度
    char mean[MEANNUM+1];
    //设置单词词性长度
    char format[WORDNUM+1];
};

//链表
struct listNode
{
    //数据域，存放数据
    struct content data;
    //指向下一个链表节点
    struct listNode *next;
};

typedef struct listNode node;
typedef struct listNode* nodeptr;


void Insert(nodeptr ptr,struct content);

#endif // WORDOPERATE_H_INCLUDED

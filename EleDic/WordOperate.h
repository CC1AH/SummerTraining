#ifndef WORDOPERATE_H_INCLUDED
#define WORDOPERATE_H_INCLUDED
/**
*@author �Ϲ���
*2019/7/21
*����洢��������Ļ�����ʽ����Ϣ
*�����������ṹ���������� ɾ�� ���� ����
*������ڵ��ʵ����� ɾ�� ���� ����ģ��
*/

//���ʳ��ȣ����Գ��ȣ����������峤�ȵ����ֵ
#define WORDNUM 30
#define MEANNUM 30

//��������
struct content
{
    //����Ӣ�ĵ��ʳ���
    char word[WORDNUM+1];
    //�����������峤��
    char mean[MEANNUM+1];
    //���õ��ʴ��Գ���
    char format[WORDNUM+1];
};

//����
struct listNode
{
    //�����򣬴������
    struct content data;
    //ָ����һ������ڵ�
    struct listNode *next;
};

typedef struct listNode node;
typedef struct listNode* nodeptr;


void Insert(nodeptr ptr,struct content);

#endif // WORDOPERATE_H_INCLUDED

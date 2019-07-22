#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
/**
*
*
*/

//���а������ַ����������չ����(contains spilt��)
#include "StringUtility.h"

//���а����˵��ʽṹ��Ļ�����Ϣ������Ĳ�������InsertList,FreeList�Լ�ExistOrNot
#include "BasicStructrue.h"

//���а����˳�ʼ�����˵��Ͳ�ѯ���б�Ļ�������ģ�麯��initial,choseMenu,searchInChinese,searchInEnglish�Լ�listAll
#include "BasicFunctions.h"

//���а����˶��ڵ��ʱ���Ĳ���ģ�麯��addWord,deleteWord,modifyWord
#include "WordOperation.h"

//���а�����д���ղصĸ��ӹ��ܺ���collections��dictation
#include "OtherOperation.h"

int main(){
    //��ʼ�����ݽṹ
    nodeptr mainptr = NULL;
    nodeptr collectionptr = NULL;
    mainptr = initial(mainptr);
    double start = clock();
    double finish;

    int choose;
    choose = choseMenu();
    while(1){
    switch(choose){
    case 0:
        system("cls");
        searchInEnglish(mainptr);
        break;
    case 1:
        system("cls");
        searchInChinese(mainptr);
        break;
    case 2:
        system("cls");
        mainptr = addWord(mainptr);
        break;
    case 3:
        system("cls");
        mainptr = deleteWord(mainptr);
        break;
    case 4:
        system("cls");
        mainptr = modifyWord(mainptr);
        break;
    case 5:
        system("cls");
        collections(collectionptr);
        break;
    case 6:
        system("cls");
        printf("                        |--------------------����ģʽ---------------------|\n");
        printf("                        |------------------(1)��ȫ�������г�ȡ����-----------------------|\n");
        printf("                        |------------------(2)���ղؼ��г�ȡ����-------------------------|\n");
        printf("                        |------------------(3)�鿴ĿǰΪֹȫ������д��Ϣ-------------------------|\n");
        int chose;
        fflush(stdin);
        printf("������ѡ��");
        scanf("%d",&chose);
        //��дʱ��û�г�ʼ���ղؼ�
        collectionptr = initialCollections(collectionptr);
        if(chose == 1 || chose == 3)
        dictation(chose,mainptr);
        if(chose == 2){
        dictation(chose,collectionptr);
        collectionptr = initialCollections(collectionptr);
        }
        break;
    case 7:
        system("cls");
        listAll(mainptr);
        break;
    case 8:
        system("cls");
        char info[200];
        getCurrentTime(info);
        printf("\n\n\n\t\t\t���Ѿ��˳�������򣬸�л������顣");
        finish = clock();
        printf("\n\t\t\t����ʹ��ʱ�䣺%d s",(int)((finish - start)/CLOCKS_PER_SEC));
        printf("\t\t\t�ټ���");
        exit(1);
        break;
    default:
        break;
    }
    choose = choseMenu();
    }
}

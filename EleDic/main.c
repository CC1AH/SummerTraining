#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
/**
*
*
*/

//其中包含了字符串处理的拓展函数(contains spilt等)
#include "StringUtility.h"

//其中包含了单词结构体的基本信息和链表的操作函数InsertList,FreeList以及ExistOrNot
#include "BasicStructrue.h"

//其中包含了初始化，菜单和查询及列表的基本功能模块函数initial,choseMenu,searchInChinese,searchInEnglish以及listAll
#include "BasicFunctions.h"

//其中包含了对于单词本身的操作模块函数addWord,deleteWord,modifyWord
#include "WordOperation.h"

//其中包含听写，收藏的附加功能函数collections和dictation
#include "OtherOperation.h"

int main(){
    //初始化数据结构
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
        printf("                        |--------------------测试模式---------------------|\n");
        printf("                        |------------------(1)从全部单词中抽取测试-----------------------|\n");
        printf("                        |------------------(2)从收藏夹中抽取测试-------------------------|\n");
        printf("                        |------------------(3)查看目前为止全部的听写信息-------------------------|\n");
        int chose;
        fflush(stdin);
        printf("请输入选择：");
        scanf("%d",&chose);
        //听写时还没有初始化收藏夹
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
        printf("\n\n\n\t\t\t您已经退出这个程序，感谢您的陪伴。");
        finish = clock();
        printf("\n\t\t\t本次使用时间：%d s",(int)((finish - start)/CLOCKS_PER_SEC));
        printf("\t\t\t再见！");
        exit(1);
        break;
    default:
        break;
    }
    choose = choseMenu();
    }
}

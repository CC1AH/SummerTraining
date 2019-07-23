#ifndef ENTERTAINMENT_H_INCLUDED
#define ENTERTAINMENT_H_INCLUDED
#include<string.h>
#include<windows.h>
/**
* 该文件描述了电子辞典的娱乐功能模块
* 这个模块是不在项目需求里面的新添模块
* @author 邢国浩
* 2019/7/23
* copyright reserved
*/

int ifLog = 0;
//包含的函数原型
void EntertainmentMenu();
void log();
void openWithSystem();

//包含函数原型的基本内容
/**
* 娱乐功能菜单
* 没啥好说的
*/
void EntertainmentMenu(){
    printf("\n\n\n                       欢迎来到娱乐界面，该界面的功能需要VIP登陆之后才可以使用（密码015）\n");
	printf("                        ___________________________________________________________________________\n");
	printf("                        |------------------(1)游戏等待开放中（此模块请关注git上是否更新，开发者现在不想做...）|\n");
    printf("                        |------------------(2)(windows)打开所有原始资源文件-----------------------------------|\n");
    printf("请输入你的选择：\n");

	int choose;
	fflush(stdin);
	printf("请根据需求输入数字(1-2)：");

	//当用户的选择在0-10之外的范围则提示用户输入错误，请重新输入
	while((scanf("%d", &choose)!=1) || (choose<0||choose>2))
	{
		printf("输入错误，请重新输入(1-2)：");
		fflush(stdin);
	}

    switch(choose){
        case 1:
            log();
            break;
        case 2:
            openWithSystem();
            break;
        default:
            break;
    }
}

/**
* 登陆功能
* 要求用户输入VIP吗，三次机会，用完了之后休眠20秒才能接着输
*/
void log(){
    if(ifLog){
        printf("您已经登陆，享受娱乐模块的功能吧");
        return;
    }
    char code[30];
    fflush(stdin);
	printf("输入您的VIP码（015）");
	scanf("%s", &code);

	int leftChance = 2;

	//当用户没有输入015时提示用户输入错误，请重新输入,总共3次机会
	while(strcmp(code,"015")!=0)
	{
        if(leftChance!=0){
		printf("输入错误，请重新输入, 剩余%d：次",leftChance);
		fflush(stdin);
		leftChance--;
		scanf("%s", &code);
        }
        else{
            printf("对不起我们怀疑你在试。请20秒后再来");
            Sleep(20000);
            return;
        }
	}
    printf("您已经登陆，享受娱乐模块的功能吧");
    ifLog = 1;
}

/**
* 文件系统打开
* 登陆后windows资源管理器会调用打开所有文件
*/
void openWithSystem(){
    if(!ifLog){
        log();
        return;
    }
    printf("即将打开所有的资源文件");
    Sleep(300);
    ShellExecute(NULL,"open","dictionary.txt",NULL,NULL,SW_NORMAL);
    ShellExecute(NULL,"open","collections.txt",NULL,NULL,SW_NORMAL);
    ShellExecute(NULL,"open","dictationInfo.txt",NULL,NULL,SW_NORMAL);
}
#endif // ENTERTAINMENT_H_INCLUDED

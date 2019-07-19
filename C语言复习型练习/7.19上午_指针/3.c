#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"Game.h"
int main()
{
    int n;
    int count = 0;
    printf("请输入一个骰子需要好多个面\n");
    scanf("%d",&n);
    while(n){
        playGame(n);
        count++;
        printf("请输入一个骰子需要好多个面\n");
        scanf("%d",&n);
    }
    printf("你一共摇了%d次!!!\n祝你好运",count);
}


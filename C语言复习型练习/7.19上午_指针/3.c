#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"Game.h"
int main()
{
    int n;
    int count = 0;
    printf("������һ��������Ҫ�ö����\n");
    scanf("%d",&n);
    while(n){
        playGame(n);
        count++;
        printf("������һ��������Ҫ�ö����\n");
        scanf("%d",&n);
    }
    printf("��һ��ҡ��%d��!!!\nף�����",count);
}


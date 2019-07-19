#include <stdio.h>
#include <stdlib.h>
void BreakElement(int x){
    if(isSushu(x)){
        puts("這個數是素數");
    return;
    }

    int temp = x;
    int m[50];
    int i;
    int count = 0;
    for(i=2;i<x;++i){
        while(temp%i==0){
            m[count++] = i;
            temp /= i;
        }
    }

    printf("%d=",x);
    for(i=0;i<count-1;++i){
        printf("%d*",m[i]);
    }
    printf("%d\n",m[count-1]);
}

int isSushu(int m){
    int i;
    for(i=2;i<=m/2;++i){
        if(m%i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int i;
    while(1){
    printf("請輸入你想要分解的數:\n");
    scanf("%d",&i);
    BreakElement(i);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//請你指定秒數
void Timer(int n){
    int i;
    printf("計時中...\n");
    for(i=n;i>=1;--i){
        printf("時間剩餘：%d s",i);
        Sleep(1000);
        system("cls");
    }
    printf("時間到\a\a\a  請等一會");
}
int main()
{
    int n;
    while(1){
    printf("請你輸入秒數,輸入0以退出\n");
    scanf("%d",&n);
    if(n==0)
        break;
    Timer(n);
    Sleep(1500);
    system("cls");
    }
    return 0;
}


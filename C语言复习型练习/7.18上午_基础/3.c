#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
//Ո��ָ���딵
void Timer(int n){
    int i;
    printf("Ӌ�r��...\n");
    for(i=n;i>=1;--i){
        printf("�r�gʣ�N��%d s",i);
        Sleep(1000);
        system("cls");
    }
    printf("�r�g��\a\a\a  Ո��һ��");
}
int main()
{
    int n;
    while(1){
    printf("Ո��ݔ���딵,ݔ��0���˳�\n");
    scanf("%d",&n);
    if(n==0)
        break;
    Timer(n);
    Sleep(1500);
    system("cls");
    }
    return 0;
}


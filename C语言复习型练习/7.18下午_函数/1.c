#include <stdio.h>
#include <stdlib.h>
int max(int i1,int i2,int i3){
    int max = i1;
    if(i2 > max)
        max = i2;
    if(i3 > max)
        max = i3;
    return max;
}
int main()
{
     int i1,i2,i3;
    printf("請輸入3個整數：");
    scanf("%d%d%d",&i1,&i2,&i3);
    printf("輸入整數的最大值是：%d",max(i1,i2,i3));
    return 0;
}
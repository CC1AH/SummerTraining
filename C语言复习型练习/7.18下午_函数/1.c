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
    printf("Ոݔ��3��������");
    scanf("%d%d%d",&i1,&i2,&i3);
    printf("ݔ�����������ֵ�ǣ�%d",max(i1,i2,i3));
    return 0;
}
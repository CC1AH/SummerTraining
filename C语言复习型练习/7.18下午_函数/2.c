#include <stdio.h>
#include <stdlib.h>
int EleSum(int n){
    int sum = 0;
    for(int i=2;i<n-1;++i){
        if(n%i == 0)
            sum += i;
    }
    return sum;
}
int main()
{
     int n;
    printf("請輸入整數：");
    scanf("%d",&n);
    printf("輸入整數的因子之和是：%d",EleSum(n));
    return 0;
}



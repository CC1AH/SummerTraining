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
    printf("Ոݔ��������");
    scanf("%d",&n);
    printf("ݔ������������֮���ǣ�%d",EleSum(n));
    return 0;
}



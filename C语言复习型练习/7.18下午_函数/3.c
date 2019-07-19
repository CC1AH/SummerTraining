#include <stdio.h>
#include <stdlib.h>
int F(int n){
    if(n==1||n==2){
        return 1;
    }
    else{
        return F(n-1) + F(n-2);
    }
}
int main()
{
    for(int i=1;i<=20;++i){
        printf("%d\t",F(i));
    }
    return 0;
}



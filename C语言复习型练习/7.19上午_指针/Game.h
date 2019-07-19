#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include<time.h>
void playGame(int n){
    int num,i;
    int sum = 0;
    printf("请输入使用多少个筛子：\n");
    scanf("%d",&num);
    for(i=0;i<n;++i){
        srand(time(NULL));
        sum += (rand()%num + 1);
    }
    printf("你使用%d个%d面的筛子摇出了%d点\n",n,num,sum);
}


#endif // GAME_H_INCLUDED

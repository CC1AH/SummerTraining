#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include<time.h>
void playGame(int n){
    int num,i;
    int sum = 0;
    printf("������ʹ�ö��ٸ�ɸ�ӣ�\n");
    scanf("%d",&num);
    for(i=0;i<n;++i){
        srand(time(NULL));
        sum += (rand()%num + 1);
    }
    printf("��ʹ��%d��%d���ɸ��ҡ����%d��\n",n,num,sum);
}


#endif // GAME_H_INCLUDED

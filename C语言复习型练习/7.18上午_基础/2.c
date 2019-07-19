#include <stdio.h>
#include <stdlib.h>
void printSpace(int m){
    int i;
    for(i=0;i<m;++i){
        printf(" ");
    }
}
void printStars(int n){
    int i;
    for(i=0;i<n;++i){
        printf("*");
    }
}
void printRhombus(int n){
     int m = n-1;
     printSpace(m+1);
     printStars(1);
     puts("");
     int i;
  for(i=0;i<m;++i){
     printSpace(m-i);
     printStars(1);
     printSpace(i*2+1);
     printStars(1);
     puts("");
     }
  for(i=m-2;i>=0;--i){
     printSpace(m-i);
     printStars(1);
     printSpace(i*2+1);
     printStars(1);
     puts("");
     }
     printSpace(m+1);
     printStars(1);
     puts("");
}
int main()
{
    while(1){
    int n;
    puts("請你指定空心菱形的大小 菱形的邊長為：");
    scanf("%d",&n);
    printRhombus(n);
    }
    return 0;
}

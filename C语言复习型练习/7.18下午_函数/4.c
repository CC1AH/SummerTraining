#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int WordNum(char* s){
    int count = 1;
   for(int i=0;i<strlen(s);++i){
    if(s[i]==' ')
        count++;
   }
   return count;
}
int main()
{
    char s[50];
    printf("Ոݔ���ַ�����");
    gets(s);
    printf("���~�Ă����ǣ�%d",WordNum(s));
    return 0;
}



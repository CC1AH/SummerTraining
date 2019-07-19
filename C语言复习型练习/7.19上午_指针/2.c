#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void Sort(char str[6][10]){
    int i,j;
    char temp[50];
    for(i=0;i<5;++i)
        for(j=i+1;j<6;++j)
        {
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    for(i=0;i<6;++i){
        printf(str[i]);
        printf("  ");
    }
}
int main()
{
    char s[6][10];
    printf("请输入字符串，以回车分割");
        for(int i=0;i<6;++i)
    gets(s[i]);
    Sort(s);
}


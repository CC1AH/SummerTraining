#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void caller(char*(*p)(char*), char* s){
    p(s);
}
char* toUpperString(char* s){
    int i;
    for(i=0;i<strlen(s);++i)
        s[i] = toupper(s[i]);
    printf(s);
    return s;
}
char* toLowerString(char* s){
    int i;
    for(i=0;i<strlen(s);++i)
        s[i] = tolower(s[i]);
    printf(s);
    return s;
}
char* changeStringCase(char* s){
    int i;
    for(i=0;i<strlen(s);++i){
        if(islower(s[i]))
        s[i] = toupper(s[i]);
        if(isupper(s[i]))
        s[i] = tolower(s[i]);
        }
        printf(s);
    return s;
}
int main()
{
    char s[50];
    printf("Enter a String!\n");
    gets(s);
    printf("Enter menu choice:\nu) uppercase\tl)lowercase\nt)transposed case\to)original case\nn)next string\n");
    char c;
    scanf("%c",&c);
    while(c!='q'){
        char temp[50];
        strcpy(temp,s);
        switch(c){
     case 'u':
        caller(toUpperString,temp);
        printf(" Enter menu choice:\n");
        break;
     case 'l':
        caller(toLowerString,temp);
        printf(" Enter menu choice:\n");
        break;
     case 't':
        caller(changeStringCase,temp);
        printf(" Enter menu choice:\n");
        break;
     case 'o':
        printf(s);
        printf(" Enter menu choice:\n");
        break;
     case 'n':
        gets(s);
        printf(" Enter menu choice:\n");
        break;
     default:
        break;
    }
        scanf("%c[^\n]",&c);
    }
}


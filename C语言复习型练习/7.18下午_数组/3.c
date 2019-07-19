#include <stdio.h>
#include <stdlib.h>
vchar* MyStrcat(char *dst, const char *src)
{
 
   char *temp = dst;
 
   while (*temp != '\0')

        temp++;
    
   while ((*temp++ = *src++) != '\0');


        return dst;

}


int main()
{
  
  	char str1[10] = "abc";
    
	char str2[] = "bcd";
  
  	char* str3 = MyStrcat(str1, str2);

 
   	printf("str1=%s\n", str1);
 
  	printf("str2=%s\n", str2);
  
  	printf("str3=%s\n", str3);
 
      return 0;

}
#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int Arr[],int n){
    int pass,i;
    for(pass=1;pass<n;++pass){
        for(i=0;i<n-pass;++i){
            if(Arr[i]>Arr[i+1]){
                int tmp = Arr[i];
                Arr[i] = Arr[i+1];
                Arr[i+1] = tmp;
            }
        }
    }
}
int main()
{
    int a[10];
    int i;
    puts("ÕˆÝ”Èë10‚€”µ");
    for(i=0;i<10;++i)
        scanf("%d",&a[i]);
    for(i=0;i<10;++i)
        printf("%d",a[i]);
    puts("\nÅÅÐòáá£º");
    bubbleSort(a,10);
     for(i=0;i<10;++i)
        printf("%d ",a[i]);
    return 0;
}

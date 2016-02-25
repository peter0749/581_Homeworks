#include <stdio.h>
#include <stdlib.h>
#define MAX 1000100
int main(void)
{
    int *book = (int*)malloc(sizeof(int)*MAX), num, m, i;
    while(1)
    {
        scanf("%d%d",&num,&m);
        if(m==0)    break;
        for(i=0; i<m; i++)    book[i] = 0;
        num%=m;
        for(i=1;; i++)
        {
            if(book[(num = num*10%m)]>0)    break;
            book[num]=i;
        }
        printf("%d\n",i-book[num]);
    }
    free(book);
    return 0;
}

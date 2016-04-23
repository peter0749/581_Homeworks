#include <stdio.h>
#include <stdlib.h>
#define MAX 10100

int arr[MAX];
char mark[MAX];

int main(void)
{
    int term, spy, i, total=0;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d", &spy);

        for(i=1; i<spy; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=0;i<spy;i++)mark[i]=0;
        for(i=spy-1, total=0; i>0; i--)
        {
            if(!mark[i])
            {
                mark[ arr[i] ] = 1;
            }
            else
                total++;
        }
        total += mark[0];
        printf("%d\n",total);
    }
    return 0;
}

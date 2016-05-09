#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10010

int arr[MAX];
bool mark[MAX];

int main(void)
{
    int term;
    int n, i, total;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);
        for(i=1; i<n; i++)
        {
            scanf("%d",arr+i);
        }
        total = 0;
        for(i=0; i<n; i++)mark[i]=false;
        for(i=n-1; i>0; i--)
        {
            if( !mark[i] )
            {
                mark[ arr[i] ] = true;
            }
            else
            {
                total++;
            }
        }
        if(mark[0])total++;
        printf("%d\n",total);
    }
    return 0;
}

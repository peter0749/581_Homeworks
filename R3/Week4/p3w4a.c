#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 3000
#define INF -1

int arr[MAXN];

int main(void)
{
    int i, n, minval, left, right, minnum;
    int num;
    while(scanf("%d", &n)!=EOF && n)
    {
        if(n<2)
        {
            for(i=0; i<n; i++)scanf("%d");
            printf("No solution\n");
            continue;
        }
        for(i=0; i<MAXN; i++)arr[i]=INF;
        minval = 1000000000;
        minnum = INF;
        for(i=0; i<n; i++)
        {
            scanf("%d", &num);
            if(arr[num]!=INF)
            {
                if( i - arr[num] < minval )
                {
                    minval = i - arr[num];
                    minnum = num;
                    left = arr[num];
                    right = i;
                }
            }
            arr[num] = i;
        }
        if(minnum==INF)
            printf("No solution\n");
        else
            printf("(%d,%d):%d\n", left, right, minnum);
    }
    return 0;
}

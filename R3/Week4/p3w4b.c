#include <stdio.h>
#include <stdlib.h>
#define MAXN 3000
#define INF -1

int arr[MAXN];

int main(void)
{
    int n, i, num, left, right, maxnum, maxval;
    while(scanf("%d", &n)!=EOF && n)
    {
        if(n<2)
        {
            for(i=0; i<n; i++)scanf("%d");
            printf("No solution\n");
            continue;
        }
        for(i=0; i<MAXN; i++) arr[i] = INF;
        maxnum = maxval = INF;
        for(i=0; i<n; i++)
        {
            scanf("%d", &num);
            if(arr[num]==INF) arr[num] = i;
            else
            {
                if( i - arr[num] > maxval )
                {
                    maxval = i-arr[num];
                    maxnum = num;
                    left = arr[num];
                    right = i;
                }
            }
        }
        if(maxnum==INF)
            printf("No solution\n");
        else
            printf("(%d,%d):%d\n", left, right, maxnum);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 3000
#define __bmax(x,y) (x)>(y) ? (x):(y)

int book[MAX];

int main(void)
{
    int n, i, num, max, left, right, val, t;
    while(scanf("%d", &n)!=EOF && n)
    {
        max = INT_MIN;
        for(i=0; i<MAX; i++) book[i] = -1;
        for(i=0; i<n; i++)
        {
            scanf("%d", &num);
            if(book[num]==-1) book[num] = i;
            else
            {
                t = i-book[num];
                if(t>max)
                {
                    left = book[num];
                    right = i;
                    val = num;
                    max = t;
                }
            }
        }
        if(max == INT_MIN)  printf("No solution\n");
        else    printf("(%d,%d):%d\n", left, right, val);
    }
    return 0;
}

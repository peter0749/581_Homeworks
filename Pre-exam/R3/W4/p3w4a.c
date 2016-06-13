#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXN 50000
#define LEN 3000

int counter[LEN];

int main(void)
{
    int n, i, num;
    int min = INT_MAX, left, right, val;
    while(scanf("%d", &n) && n)
    {
        min = INT_MAX;
        for(i=0; i<LEN; i++) counter[i] = -1;
        for(i=0; i<n; i++)
        {
            scanf("%d", &num);
            if(counter[num]==-1) counter[num] = i;
            else
            {
                if( i - counter[num] < min)
                {
                    min=i-counter[num];
                    val = num;
                    left = counter[num];
                    right = i;
                }
                counter[num] = i;
            }
        }
        if(min==INT_MAX)
            printf("No solution\n");
        else
            printf("(%d,%d):%d\n", left, right, val);
    }
    return 0;
}

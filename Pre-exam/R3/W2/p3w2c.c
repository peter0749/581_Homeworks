#include <stdio.h>
#include <stdlib.h>

int arr[600100];
int DP[600100];

int main(void)
{
    int n, term, i;
    int max=0;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)scanf("%d", arr+i);
        max = DP[0] = arr[0];
        for(i=1; i<n; i++)
        {
            if(DP[i-1] < 0) DP[i] = arr[i];
            else DP[i] = DP[i-1]+arr[i];
            if(DP[i]>max)max=DP[i];
        }
        if(max<0) max = 0;
        printf("%d\n", max);
    }

    return 0;
}

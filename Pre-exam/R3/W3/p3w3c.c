#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 55

int cutp[MAX];
int DP[MAX][MAX];

int rec_cut(int left, int right)
{
    if(right-left <= 1) return 0;
    if(DP[left][right]>=0) return DP[left][right];
    int i, temp=0, min = INT_MAX;
    for(i=left+1; i<right; i++)
    {
        temp = rec_cut(left, i) + rec_cut(i, right);
        if(temp < min) min = temp;
    }
    if(min==INT_MAX) min = 0;
    return DP[left][right] =  min+cutp[right]-cutp[left];
}

int main(void)
{
    int len, n, i, j;
    while(scanf("%d", &len)!=EOF && len)
    {
        scanf("%d", &n);
        for(i=1; i<=n; i++) scanf("%d", cutp+i);
        cutp[0] = 0; cutp[n+1] = len;
        for(i=n+1; i>=0; i--)for(j=n+1; j>=0; j--)DP[i][j] = -1;
        printf("The minimum cutting is %d.\n", rec_cut(0, n+1));
    }
    return 0;
}

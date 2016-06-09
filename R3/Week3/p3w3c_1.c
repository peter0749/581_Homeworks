#include <stdio.h>
#include <stdlib.h>
#define MAXCUT 60
#define INF 1000000000
int cutting_point[MAXCUT];
int DP[MAXCUT][MAXCUT];

int dfs(int left, int right)
{
    int i, t, min=INF;
    if(right - left <= 1)return 0;
    if(DP[left][right]>=0) return DP[left][right];
    for(i=left+1; i<right; i++)
    {
        t = dfs(left, i) + dfs(i, right);
        if(t<min) min = t;
    }
    return DP[left][right] = min + cutting_point[right] - cutting_point[left];
}

int main(void)
{
    int len, n;
    int min;
    int i, j;
    while(scanf("%d",&len)!=EOF && len)
    {
        scanf("%d",&n);
        for(i=0; i<MAXCUT; i++)for(j=0;j<MAXCUT;j++)DP[i][j] = -1;
        for(i=1; i<=n; i++)scanf("%d",&cutting_point[i]);
        cutting_point[0] = 0; cutting_point[n+1] = len;
        min = INF;
        min = dfs(0,n+1);

        printf("The minimum cutting is %d.\n",min);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXCUT 60
#define MAXLEN 1001
int cutting_point[MAXCUT];
bool cutted[MAXCUT];
int DP[MAXLEN][MAXLEN];

int dfs(int left, int right, int n)
{
    int total, min, i;
    if(DP[left][right]!=-1) return DP[left][right];

    total = right - left;
    min = 99999;
    for(i=0; i<n; i++)
    {
        total = right - left;
        if(!cutted[i] && cutting_point[i]<right && cutting_point[i]>left)
        {
            cutted[i] = true;
            total += dfs(left, cutting_point[i],n);
            total += dfs(cutting_point[i],right,n);
            cutted[i] = false;
            if(total < min) min = total;
        }
    }
    if(min == 99999) min = 0;
    //printf("left %d right %d %d\n",left,right,min);
    return DP[left][right] = min;
}

int main(void)
{
    int len, n;
    int min, total;
    int i, j;
    while(scanf("%d",&len)!=EOF && len)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++) cutted[i] = false;
        for(i=0; i<MAXLEN; i++)for(j=0;j<MAXLEN;j++)DP[i][j] = -1;
        for(i=0; i<n; i++)scanf("%d",&cutting_point[i]);
        min = total = 9999;
        for(i=0; i<n; i++)
        {
            total = len;
            cutted[i] = true;
            total += dfs(0,cutting_point[i],n);
            total += dfs(cutting_point[i],len,n);
            cutted[i] = false;
            if(total < min) min = total;
            //printf("%d\n",total);
        }
        if(min==9999)min=0;
        printf("The minimum cutting is %d.\n",min);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 100

int dfsstk[MAX];
char mark[MAX];
int w[MAX][MAX];
int max, min;

void dfs(const int n, int depth, int sum)
{
    int i, j;
    char conf=0;
    if(n==depth)
    {
        if(sum>max)max=sum;
        if(sum<min)min=sum;
        return;
    }
    for(i=0; i<n; i++)
    {
        if(!mark[i])
        {
            for(j=0; j<depth; j++)
            {
                if( abs(dfsstk[j]-i) == depth-j )//<<<<<<<
                {
                    conf = 1;
                    break;
                }
            }
            if(conf)
            {
                conf = 0;
                continue;
            }
            dfsstk[depth] = i;
            mark[i] = 1;
            dfs(n, depth+1, sum+w[depth][i]);//<<<<<<<<<
            mark[i] = 0;
        }
    }
}

int main(void)
{
    int term, n, i, j;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)for(j=0; j<n; j++)scanf("%d", &w[i][j]);
        max = -1; min = INT_MAX;
        dfs(n,0,0);
        if(min==INT_MAX) min=-1;
        printf("%d %d\n", max, min);
    }
    return 0;
}

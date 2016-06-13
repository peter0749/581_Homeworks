#include <stdio.h>
#include <stdlib.h>
#define MAX 1050000

int wei[MAX];
int DP[MAX];
int total = -1;

int dfs(const int n, int u)
{
    if(DP[u]>=0) return DP[u];
    int i, v, max = 0, temp;
    for(i=0; i<n; i++)
    {
        if(u & (1<<i))
        {
            v = u^(1<<i);
            temp = dfs(n, v);
            if(temp > max) max = temp;
        }
    }
    return DP[u] = (wei[u] += max);
}

int main(void)
{
    int n, i;
    while(scanf("%d", &n)!=EOF && n)
    {
        for(i=0; i<(1<<n); i++)
            scanf("%u", wei+i);
        for(i=0; i<(1<<n); i++) DP[i] = -1;
        total = -1;
        dfs(n, (1<<n)-1);
        printf("%d\n", wei[(1<<n)-1]);
    }
    return 0;
}

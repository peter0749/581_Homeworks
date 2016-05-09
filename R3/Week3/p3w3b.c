#include <stdio.h>
#include <stdlib.h>
#define MAX 1100000
#define dmax( x , y ) (x)>(y) ? (x):(y);
char weight[MAX];
int dp[MAX];

int dfs(int node, int n)
{
    if(dp[node]>=0) return dp[node];
    int i, temp, maxval=0;
    for(i=0; i<n; i++)
    {
        if( node&(1<<i) )//相鄰且小於node
        {
            temp = dfs((1<<i)^node,n);
            if( temp > maxval )//Choose max
                maxval = temp;
        }
    }
    //printf("Node %d, max %d\n",node, maxval);
    return dp[node]=(maxval+weight[node]);
}

int main(void)
{
    int n, i;
    while(scanf("%d",&n)!=EOF && n)
    {
        //printf("%d\n",n);
        for(i=0; i<(1<<n); i++){scanf("%d",weight+i); dp[i]=-1;}
        printf("%d\n", dfs((1<<n)-1, n));
        //for(i=0; i<n; i++)printf("%d\n",dp[i]);
    }
    return 0;
}

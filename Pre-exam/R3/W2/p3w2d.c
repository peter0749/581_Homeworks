#include <stdio.h>
#include <stdlib.h>
#define __BMax(X,Y) (X)>(Y) ? (X):(Y)
#define MAX 220

unsigned int chb[MAX][MAX];

int main(void)
{
    int i, j, n;
    while(scanf("%d", &n)!=EOF && n)
    {
        for(i=n; i>=0; i--) chb[0][i] = chb[i][0] = 0;
        for(i=1; i<=n; i++)for(j=1; j<=n; j++) scanf("%u", &chb[i][j]);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                chb[i][j] += __BMax(chb[i-1][j], chb[i][j-1]);
            }
        }
        printf("%u\n", chb[n][n]);
    }
    return 0;
}

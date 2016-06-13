#include <stdio.h>
#include <stdlib.h>
#define __BMAX(X,Y) (X)>(Y) ? (X):(Y)
#define MAXN 550
#define LEN 1010

int arr[MAXN];
int opt[MAXN][2];//N/Y

int main(void)
{
    int n, i, temp;
    while(scanf("%d", &n)!=EOF && n)
    {
        for(i=0; i<n; i++) scanf("%d", arr+i);
        opt[0][0] = 0; opt[0][1] = arr[0];
        for(i=1; i<n; i++)
        {
            opt[i][1] = opt[i-1][0] + arr[i];
            opt[i][0] = __BMAX(opt[i-1][0], opt[i-1][1]);
        }
        printf("%d\n", __BMAX(opt[n-1][0], opt[n-1][1]));
    }
    return 0;
}

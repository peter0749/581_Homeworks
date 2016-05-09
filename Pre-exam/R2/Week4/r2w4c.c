#include <stdio.h>
#include <stdlib.h>
#define MAX 1010
#define min(x,y) (x)<(y)?(x):(y)

int gate[MAX][2];

int main(void)
{
    int t1,t2,x1,x2;
    int n, i;
    t1=t2=x1=x2=0;
    while(scanf("%d",&n)!=EOF && n)
    {
        gate[0][0]=gate[0][1]=1000;
        for(i=1; i<=n; i++)
            scanf("%d%d",&gate[i][0], &gate[i][1]);
        t1 = t2 = 0;

        for(i=1; i<=n; i++)
        {
            x1 = min( t1+abs(gate[i-1][0]-gate[i][0]) , t2+abs(gate[i-1][1]-gate[i][0]) );
            x2 = min( t2+abs(gate[i-1][1]-gate[i][1]) , t1+abs(gate[i-1][0]-gate[i][1]) );
            t1 = x1;
            t2 = x2;
        }
        printf("%d\n", min(t1,t2));
    }
    return 0;
}

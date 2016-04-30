#include <stdio.h>
#include <stdlib.h>
#define MAX 2000
int gates[MAX][2];
//int res[MAX][2];

int min(const int a, const int b)
{
    return a<b?a:b;
}

int main(void)
{
    int n, i;
    int temp;
    int t1,t2,x1,x2;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        t1=t2=0;
        gates[0][0] = gates[0][1] = 1000;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&gates[i][0],&gates[i][1]);
            //if(gates[i][0]>gates[i][1]){temp=gates[i][0];gates[i][0]=gates[i][1];gates[i][1]=temp;}
        }
        for(i=1;i<=n;i++)
        {
            x1 = min( t1+abs(gates[i][0]-gates[i-1][0]) , t2+abs(gates[i][0]-gates[i-1][1]) );
            x2 = min( t1+abs(gates[i][1]-gates[i-1][0]) , t2+abs(gates[i][1]-gates[i-1][1]) );
            t1=x1; t2=x2;
            //printf("t1:%d t2:%d\n",t1,t2);
        }
        printf("%d\n",min(t1,t2));
    }
    return 0;
}

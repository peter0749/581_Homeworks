#include <stdio.h>
#include <stdlib.h>
#define MAX 300
#define max( x , y ) (x)>(y)?(x):(y)

unsigned int arr[MAX][MAX];

int main(void)
{
	unsigned int n;
	unsigned int i, j;
	for(i=0;i<MAX;i++)for(j=0;j<MAX;j++)arr[i][j] = 0;
	while(scanf("%u",&n)!=EOF)
	{
		if(n==0)break;
		//for(i=1;i<=n; i++)for(j=1;j<=n;j++)arr[i][j]=0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%u",&arr[i][j]);
			}
		}
		if(n==1){printf("%u\n",arr[1][1]);continue;}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n ;j++)
			{
				arr[i][j] += max( arr[i-1][j], arr[i][j-1] );
			}
		}
		printf("%u\n",arr[n][n]);
	}
	return 0;
}

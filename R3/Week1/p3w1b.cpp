#include <stdio.h>
#include <stdlib.h>
#define MAX 600
#define max(x,y) (x)>(y)?(x):(y);

int arr[MAX];
int dp1[MAX];
int dp2[MAX];
int dp3[MAX];

int main(void)
{
	int n, i;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		for(i=0; i<n; i++)
			scanf("%d",&arr[i]);
		dp1[0] = arr[0]; //Choose i
		dp2[0] = 0; //Dont choose i
		dp3[0] = dp1[0];//Best at i
		for(i=1; i<n; i++)
		{
			dp1[i] = dp2[i-1]+arr[i];//Choose i and dont choose i-1
			dp2[i] = dp3[i-1];//Dont choose i
			dp3[i] = max(dp1[i], dp2[i]);//Optimal solution
		}
		printf("%d\n",dp3[n-1]);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main(void)
{
	int n, i;
	//int first = 0;
	int set_count=0;
	int sum, avg;
	int arr[MAX];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)break;
		sum = avg = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
			sum+=arr[i];
		}
		avg = sum/n;
		sum = 0;
		for(i=0; i<n; i++)
		{
			if(arr[i]>avg)
				sum += abs(arr[i]-avg);
		}
		//if(first==0)first=1;
		//else printf("\n");
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",++set_count,sum);

	}
}

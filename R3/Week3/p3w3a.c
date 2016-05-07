#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXN 300
#define MAXM 60
#define MAXPATTERN 200010
int N[MAXN];
int M[MAXM];
bool CAN_MES[MAXPATTERN];

int main(void)
{
	int term, n, m;
	int maxwei;
	int counter;
	int i, j, k;
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d%d",&n,&m);
		for(i=0; i<n; i++)
			scanf("%d",N+i);
		maxwei = -1;
		for(i=0; i<m; i++)
		{
			scanf("%d",M+i);
			if(M[i]>maxwei)maxwei = M[i];
		}
		for(i=0; i<MAXPATTERN; i++)
			CAN_MES[i] = false;
		CAN_MES[0] = true;
		for(i=0; i<n; i++)
		{
			for(j=maxwei-N[i]; j>=0; j--)
			{
				if(CAN_MES[j])
				{
					CAN_MES[ j + N[i] ] = true;
				}
			}
		}
		counter = 0;
		for(i=0; i<m; i++)
			if( CAN_MES[ M[i] ] ) counter++;
		printf("%d\n",counter);

	}
	return 0;
}

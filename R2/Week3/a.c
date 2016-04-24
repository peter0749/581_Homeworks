#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 50010

short int weight[MAX];
bool visit[MAX];
int total=0, max=0;

int *map[MAX];

int *resize(int *vec)
{
	int i;
	int temp = vec[1]+2;
	int *newptr=NULL;
	if( vec[0] - vec[1] < 10  )
	{
		newptr = (int*)malloc( sizeof(int)*( vec[0]<<=1 ) );
		for(i=0 ;i<temp; i++)
			newptr[i] = vec[i];
		free(vec);
		return newptr;
	}
	return vec;
}

void dfs(int u)
{
	int i;
	total += weight[u];
	for(i=map[u][1]+1; i>1; i--)
	{
		if( !visit[ map[u][i] ] )
		{
			visit[ map[u][i] ] = true;
			dfs( map[u][i] );
		}
	}
}

int main(void)
{
	int term, m, n;
	int a, b;
	int i;
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d%d",&n,&m);
		for(i=0 ;i<n ;i++)
		{
			scanf("%hd",&weight[i]);
		}
		for(i=0 ;i<n; i++)
		{
			map[i] = (int*)malloc( sizeof(int)*5 );
			map[i][0] = 5;
			map[i][1] = 0;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d", &a, &b);
			map[a] = resize( map[a] );
			map[b] = resize( map[b] );
			map[a][ map[a][1]+2 ] = b; map[a][1]++;
			map[b][ map[b][1]+2 ] = a; map[b][1]++;
		}
		for(i=0; i<n; i++)visit[i]=false;
		max = 0;
		for(i=0; i<n; i++)
		{
			if( !visit[i] )
			{
				visit[i] = true;
				total = 0;
				dfs(i);
				if(total > max) max = total;
			}
		}
		
		printf("%d\n",max);

		for(i=0; i<n; i++)
		{
			free( map[i] );
			map[i] = NULL;
		}
	}
	return 0;
}

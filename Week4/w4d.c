#include <stdio.h>
#include <stdlib.h>
#define MAX 1010

int cmp(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main(void)
{
	int i;
	int term;
	int item;
	int sum;
	int wait[MAX];
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d", &item);
		for(i=0; i<item; i++)scanf("%d",&wait[i]);
		qsort(wait,item,sizeof(int),cmp);
		sum = 0;
		for(i=0; i<item; i++)
		{
			sum += (2*i+1)*wait[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}

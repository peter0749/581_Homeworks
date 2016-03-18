#include <stdio.h>
#include <stdlib.h>
#define MAX 10001

int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int main(void)
{
	int term;
	int i,j;
	int sum;
	int scount, icount;
	int student[MAX], item[MAX];
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d %d",&icount, &scount);
		if(icount>scount)
		{
			puts("-1");
			continue;
		}
		for(i=0; i<icount; i++)
		{
			scanf("%d", &item[i]);
		}
		for(i=0; i<scount; i++)
		{
			scanf("%d", &student[i]);
		}
		qsort(item,icount,sizeof(int),cmp);
		qsort(student,scount,sizeof(int),cmp);
		sum = i = j = 0;
		while(i<scount&&j<icount)
		{
			while(i<scount&&student[i]<item[j])i++;
			if(i>=scount)
			{
				sum = -1;
				break;
			}
			sum += student[i];
			i++;j++;
		}
		if(j<icount)sum=-1;
		printf("%d\n",sum);
	}
	return 0;
}

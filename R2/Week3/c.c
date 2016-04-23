#include <stdio.h>
#include <stdlib.h>
#define MAX 60000

typedef struct 
{
	int start;
	int endp;
}SEG;

SEG segment[MAX];

int mycmp(const void *a, const void *b)
{
	int temp;
	SEG *c = (SEG*)a;
	SEG *d = (SEG*)b;
	temp = c->start - d->start;
	return temp ? temp : c->endp - d->endp;
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int main(void)
{
	int term, m;
	int a,b;
	int total = 0;
	int leftmost, rightmost;
	int i, j;
	scanf("%d",&term);
	while(term--)
	{
		scanf("%d",&m);
		for(i=0; i<m ;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>b)swap(&a,&b);
			segment[i].start = a;
			segment[i].endp = b;
		}
		qsort(segment, m, sizeof(SEG), mycmp);
		
		total = 0;
		leftmost = segment[0].start;
		rightmost = segment[0].endp;
		for(i=1; i<m; i++)
		{
			if( segment[i].start <= rightmost )
			{
				if(segment[i].endp > rightmost) rightmost = segment[i].endp;
			}
			else
			{
				total += (rightmost - leftmost);
				rightmost = segment[i].endp;
				leftmost = segment[i].start;
			}
		}
		total += ( rightmost - leftmost );
		printf("%d\n",total);
	}
	return 0;
}

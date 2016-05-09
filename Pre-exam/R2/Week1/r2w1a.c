#include <stdio.h>
#include <stdlib.h>
#define MAX 200
typedef struct
{
    int t,d;
}JOB;

int cmp2(const void *a, const void *b)
{
    int temp;
    JOB *c = (JOB*)a;
    JOB *d = (JOB*)b;
    return (temp=c->d - d->d) ? temp:c->t - d->t;
}

JOB jobs[MAX];

int main(void)
{
    int term, n, i;
    int total = 0;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&jobs[i].t);
        }
        for(i=0; i<n; i++)
        {
            scanf("%d",&jobs[i].d);
        }
        qsort(jobs,n,sizeof(JOB),cmp2);
        total = 0;
        for(i=0; i<n; i++)
        {
            total += jobs[i].t;
            if( total > jobs[i].d )break;
        }
        if(i==n)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

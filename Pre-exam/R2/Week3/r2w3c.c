#include <stdio.h>
#include <stdlib.h>
#define MAX 50010
typedef struct
{
    int start,end;
}SEG;

int cmp(const void *a, const void *b)
{
    SEG *c = (SEG*)a;
    SEG *d = (SEG*)b;
    int temp = c->start - d->start;
    return temp?temp:c->end-d->end;
}

SEG seg[MAX];

int main(void)
{
    int term, n, i;
    int total = 0;
    int left, right;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&seg[i].start, &seg[i].end);
            if(seg[i].start > seg[i].end)
            {
                int t = seg[i].start;
                seg[i].start = seg[i].end;
                seg[i].end = t;
            }
        }
        qsort(seg,n,sizeof(SEG),cmp);
        left = seg[0].start; right = seg[0].end;
        total = 0;
        for(i=1; i<n; i++)
        {
            if( seg[i].start <= right )
            {
                if(seg[i].end > right) right = seg[i].end;
            }
            else
            {
                total += (right-left);
                right = seg[i].end;
                left = seg[i].start;
            }
        }
        total += right-left;
        printf("%d\n",total);
    }
    return 0;
}

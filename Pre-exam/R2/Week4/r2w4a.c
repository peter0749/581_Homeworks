#include <stdio.h>
#include <stdlib.h>
#define MAX 12000
typedef struct
{
    int x, y;
}BOX;

int cmp(const void *a, const void *b)
{
    BOX *c = (BOX*)a;
    BOX *d = (BOX*)b;
    int temp = d->x - c->x;
    return temp?temp:d->y - c->y;
}

BOX st[MAX];

int main(void)
{
    int term, n, i, j,a, b;
    int count=0;
    int total;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);
        for(i=0, count=0; i<n; i++)
        {
            scanf("%d%d",&a, &b);
            st[count].x = a; st[count++].y = b;
            st[count].x = b; st[count++].y = a;
        }
        qsort(st,count,sizeof(BOX),cmp);
        for(i=0, total = 0; i<count; i++)
        {
            total += st[i].y;
            for(j=i+1; j<count && st[i].x==st[j].x; j++);
            i = j-1;
        }
        printf("%d\n",total);
    }
    return 0;
}

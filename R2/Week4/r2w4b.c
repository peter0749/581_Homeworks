#include <stdio.h>
#include <stdlib.h>
#define MAX 50000
#define LEN 100
typedef struct
{
    int start, end;
} SEGMENT;

int cmp(const void *a, const void *b)
{
    SEGMENT *c = (SEGMENT*)a;
    SEGMENT *d = (SEGMENT*)b;
    int temp = c->start - d->start;
    return temp?temp:d->end - c->end;
}

SEGMENT seg[LEN];

int main(void)
{
    int term, a, b, n, t, i, j;
    int l=0, r=0;
    int best=0, besti=0, flag=0;
    int total=0;
    //int sum=0;
    char input[MAX];
    fgets(input,MAX,stdin);
    sscanf(input,"%d",&term);
    fgets(input,MAX,stdin);
    while(term--)
    {
        n = 0;
        fgets(input,MAX,stdin);
        while(input[0]!=0)
        {
            if(sscanf(input,"%d%d",&a,&b)<2)break;
            if(a>b)
            {
                t=a;
                a=b;
                b=t;
            }
            seg[n].start = a;
            seg[n++].end = b;
            if((fgets(input,MAX,stdin))==NULL)break;
        }//END-OF-IO;
        qsort(seg,n,sizeof(SEGMENT),cmp);
        //sum = 0;
        r = seg[0].end;
        total = 1;
        for(i=1; i<n && r<200; i++)
        {
            best = r;
            for(j=i; j<n && r<200 && seg[j].start - r <= 1; j++)
            {
                if(seg[j].end > best) best = seg[j].end;
            }
            i=j-1;
            if(best!=r)
            {
                //printf("%d\n",best);
                r=best;
                total++;
            }
        }
        printf("%d\n",total);
    }

    return 0;
}

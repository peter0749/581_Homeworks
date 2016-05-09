#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERLEN 3000
#define MAX 60
typedef struct
{
    int l, r;
}B;

int cmp(const void *a, const void *b)
{
    B *c = (B*)a;
    B *d = (B*)b;
    int temp = c->l - d->l;
    return temp?temp:d->r - c->r;
}

B arr[MAX];

int main(void)
{
    char temp[BUFFERLEN];
    int term=0, n=0, i, j, rightmost, best, total;
    fgets(temp,BUFFERLEN,stdin);
    term = atoi(temp);
    fgets(temp,BUFFERLEN,stdin);
    while(term--)
    {
        n = 0;
        while((fgets(temp,BUFFERLEN,stdin))!=NULL)
        {
            if(temp[0]=='\0'||temp[0]=='\n')break;
            sscanf(temp,"%d%d",&arr[n].l, &arr[n].r);
            if(arr[n].l > arr[n].r)
            {
                int t = arr[n].l;
                arr[n].l = arr[n].r;
                arr[n].r = t;
            }
            //printf("%d %d\n", arr[n].l, arr[n].r);
            n++;
        }
        qsort(arr,n,sizeof(B),cmp);
        rightmost = arr[0].r;
        total = 1;
        for(i=1;i<n && rightmost<200 ;i++)
        {
            best = rightmost;
            for(j=i; j<n && rightmost<200 && arr[j].l <= rightmost+1 ; j++)
            {
                if(arr[j].r > best)best = arr[j].r;
            }
            i = j-1;
            if(best>rightmost)
            {
                //printf("best %d\n",best);
                total++;
                rightmost = best;
            }
        }
        printf("%d\n",total);
    }

    return 0;
}

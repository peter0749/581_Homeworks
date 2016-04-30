#include <bits/stdc++.h>
#define MAX 20000
using namespace std;

typedef struct
{
    int x,y;
}BLOCK;

int cmp(const void *a, const void *b)
{
    BLOCK *c = (BLOCK*)a;
    BLOCK *d = (BLOCK*)b;
    int temp = d->x - c->x;
    return temp?temp:d->y - c->y;
}

BLOCK blocks[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    int term, n, d1, d2, j, i;
    int num=0, sum=0;
    cin>>term;
    while(term--)
    {
        num = 0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>d1>>d2;
            blocks[num].x = d1; blocks[num++].y = d2;
            blocks[num].x = d2; blocks[num++].y = d1;
        }
        qsort(blocks,num,sizeof(BLOCK),cmp);
        for(i=0, sum=0; i<num; i++)
        {
            sum += blocks[i].y;
            for(j=i+1; j<num && blocks[j].x == blocks[i].x; j++);
            i=j-1;
        }
        cout<<sum<<'\n';
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 1000000

bool table[MAX];
int num[4];
int val[4];

bool can_do(int d)
{
    int i, j, k, l;
    table[0] = true;
    for(i=1; i<MAX; i++) table[i] = false;
    for(k=0; k<3; k++)
    {
        for(i=d-val[k]; i>=0; i--)
        {
            if(table[i])
            {
                for(j=i+val[k], l=num[k]; j<=d, l>0; j+=val[k], l--) table[j]=true;
            }
        }
    }
    //freopen("debug.txt", "w", stderr);
    //for(i=0; i<1000; i++)fprintf(stderr,"%d:%d\n", i, table[i]);
    return table[d];
}

int main(void)
{
    int i, d;
    int term;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d", &d);
        for(i=0; i<3; i++) scanf("%d", num+i);
        for(i=0; i<3; i++) scanf("%d", val+i);

        printf( can_do(d)?"yes\n":"no\n" );
    }
    return 0;
}

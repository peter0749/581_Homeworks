#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int wei,deadline;
}STU;

int mycomp(const void *a, const void *b)
{
    return ((STU*)a)->deadline - ((STU*)b)->deadline;
}

int main(void)
{
    int term, n;
    int i;
    STU *ptr=NULL;
    int total=0;
    scanf("%d",&term);
    while(term--)
    {
        scanf("%d",&n);
        ptr = (STU*)malloc(sizeof(STU)*n);
        total = 0;

        for(i=0; i<n; i++)scanf("%d",&ptr[i].wei);
        for(i=0; i<n; i++)scanf("%d",&ptr[i].deadline);

        qsort(ptr,n,sizeof(STU),mycomp);

        for(i=0; i<n; i++)
        {
            total += ptr[i].wei;
            if(total>ptr[i].deadline)break;
        }

        if(i==n)puts("Yes");
        else    puts("No");
        free(ptr);
        ptr=NULL;
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 100000
int mycomp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main(void)
{
    int term, i,j,k;
    int arr[MAX], sum=0, cmpterm, temp;
    while(scanf("%d",&term)!=EOF)
    {
        if(!term)break;
        for(i=0; i<term; i++)
            scanf("%d",&arr[i]);

        qsort(arr,term,sizeof(int),mycomp);
        sum = 0;
        for(i=0;i<term-2;i++)for(j=i+1;j<term-1;j++)
        {
            temp = arr[i]+arr[j];
            for(k=j+1;k<term&&temp>arr[k];k++,sum++);
        }
        printf("%d\n",sum);
    }
    return 0;
}

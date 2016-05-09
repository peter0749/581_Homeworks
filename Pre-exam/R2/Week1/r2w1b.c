#include <stdio.h>
#include <stdlib.h>
#define MAX 10010

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int arr[MAX];

int main(void)
{
    int n,i,j,k,count;
    while(scanf("%d",&n)!=EOF && n)
    {
        for(i=0;i<n;i++)
            scanf("%d",arr+i);
        qsort(arr,n,sizeof(int),cmp);
        count = 0;
        for(i=0; i<n-2; i++)for(j=i+1; j<n-1; j++)
        {
            for(k=j+1; k<n; k++)
            {
                if(arr[i]+arr[j] > arr[k])
                    count++;
                else
                    break;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}

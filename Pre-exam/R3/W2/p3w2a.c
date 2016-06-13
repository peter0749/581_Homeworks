#include <stdio.h>
#include <stdlib.h>
#define MAX 60

int arr[MAX];

int main(void)
{
    int n, i, sum, dif;
    int counter = 0;
    while(scanf("%d", &n)!=EOF && n)
    {
        sum = 0;
        for(i=0; i<n; i++)
        {
            scanf("%d", arr+i);
            sum += arr[i];
        }
        sum/=n;
        dif = 0;
        for(i=0; i<n; i++)
        {
            if(arr[i] > sum) dif += (arr[i]-sum);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++counter, dif);
    }
    return 0;
}

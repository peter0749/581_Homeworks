#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 500
#define LEN 200010

int wei[MAX];
bool DP[LEN];
int base[MAX];

int main(void)
{
    int term, i, j, k, n, m, temp, counter;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++) scanf("%d", base+i);
        for(i=0, temp=-1; i<m; i++)
        {
            scanf("%d", wei+i);
            if(wei[i] > temp) temp = wei[i];
        }
        DP[0] = true;
        for(i=1; i<=temp; i++) DP[i] = false;
        for(k=0; k<n; k++)
        {
            for(i=temp-base[k]; i>=0; i--)
            {
                if(DP[i])
                {
                    DP[i+base[k]] = true;
                }
            }
        }
        counter = 0;
        for(i=0; i<m; i++)
        {
            if(DP[wei[i]])counter++;
        }
        printf("%d\n", counter);
    }
    return 0;
}

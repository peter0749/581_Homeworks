#include <stdio.h>
#include <stdlib.h>
#define MAXN 6000

int pa[MAXN];
int wei[MAXN];
int sub_count[MAXN];

int main(void)
{
    int term;
    int n, i;
    int sum;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d", &n);
        for(i=2; i<=n; i++) scanf("%d", pa+i);
        for(i=2; i<=n ;i++) scanf("%d", wei+i);
        for(i=0; i<=n ;i++) sub_count[i] = 1;
        sum = 0;
        for(i=n; i>=2; i--)
        {
            sub_count[ pa[i] ] += sub_count[i];
            sum += ((sub_count[i] * (n-sub_count[i]) * wei[i])<<1);
        }
        printf("%d\n", sum);
    }
    return 0;
}

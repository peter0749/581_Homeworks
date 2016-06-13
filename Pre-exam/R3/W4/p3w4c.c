#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXN 25

int w[MAXN];
int d[MAXN];
int maxr;
int n, L, Wa, Wb;

void brute_force(int depth, int crr_n, int crr_w, int crr_val)
{
    int temp;
    if(depth>=n || crr_w > Wb) return;
    if(crr_w >= Wa && crr_n >= L)
    {
        temp = (crr_val + crr_w - 1)/crr_w;
        if(temp > maxr) maxr = temp;
    }
    depth++;
    brute_force(depth, crr_n+1, crr_w+w[depth], crr_val+d[depth]);
    brute_force(depth, crr_n, crr_w, crr_val);
}

int main(void)
{
    int i, end_test;
    do{
        scanf("%d%d%d%d", &n, &L, &Wa, &Wb);
        for(i=0; i<n; i++) scanf("%d%d", d+i, w+i);
        maxr = -1;
        brute_force(-1, 0, 0, 0);
        printf("%d\n", maxr);
    }while(scanf("%d", &end_test)!=EOF && end_test!=-1);
    return 0;
}

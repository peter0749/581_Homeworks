#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

inline int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n;
    int i, j;
    int ally[MAX], enemy[MAX];
    int win=0;
    while(cin>>n)
    {
        if(n==0)break;
        for(i=0; i<n; i++)
            cin>>enemy[i];
        for(i=0; i<n; i++)
            cin>>ally[i];
        qsort(enemy,n,sizeof(int),cmp);
        qsort(ally,n,sizeof(int),cmp);
        i = j = win = 0;
        while(i<n&&j<n)
        {
            while(i<n&&ally[i]<=enemy[j])i++;
            if(i==n)break;
            win++;i++;j++;
        }
        cout<<win<<'\n';
    }
    return 0;
}

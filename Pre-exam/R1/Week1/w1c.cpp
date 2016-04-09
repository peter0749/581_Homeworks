#include <bits/stdc++.h>
#define MAX 1000101
using namespace std;

int book[MAX];

int main(void)
{
    int p, q;
    int step;
    cin.sync_with_stdio(false);
    while(cin>>p>>q)
    {
        if(q==0)break;
        for(int i=0; i<q; i++)book[i]=0;
        p%=q;
        step=1;
        while(1)
        {
            if(book[ p = p*10%q ]>0)break;
            book[p]=step++;
        }
        cout<<step-book[p]<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

unsigned int book[MAX]={0};
unsigned int rec[MAX]={0};

int main(void)
{
    cin.sync_with_stdio(false);
    int term;
    int i;
    unsigned int x, y, N;
    unsigned int base=1;
    cin>>term;
    while(term--)
    {
        cin>>x>>y>>N;
        for(i=0;i<N;i++)book[i]=0;
        base=1;
        x%=N;
        for(i=1;i<=y;i++)
        {
            if( book[ base = (base*x)%N ] >0 )break;
            book[base]=i;
            rec[i]=base;
        }
        if(i>y)cout<<base<<'\n';
        else
        {
            cout<<rec[book[base]+(y-i)%(i-book[base])]<<'\n';
        }
    }
    return 0;
}

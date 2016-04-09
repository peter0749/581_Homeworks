#include <bits/stdc++.h>

using namespace std;

inline int gcd(int x, int y)
{
    return x%y?gcd(y,x%y):y;
}

int main(void)
{
    cin.sync_with_stdio(false);
    int q1,r1,q2,r2,g;
    int term;
    cin>>term;
    while(term--)
    {
        cin>>q1>>r1>>q2>>r2;
        g = gcd(q1-r1,q2-r2);
        cout<<'1';
        for(int i=2; i<=g; i++)
        {
            if(g%i==0)
            {
                cout<<' '<<i;
            }
        }
        cout<<'\n';
    }
    return 0;
}

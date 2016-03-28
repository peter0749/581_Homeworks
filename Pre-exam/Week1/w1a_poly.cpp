#include <bits/stdc++.h>
#define MAX 1000

using namespace std;

int main(void)
{
    cin.sync_with_stdio(false);
    int term;
    int counter=0;
    int base[MAX], poly[MAX], ans[MAX];
    int d;
    for(int i=0; i<MAX; i++)ans[i] = poly[i]=0;
    cin>>term;
    while(term--)
    {
        cin>>base[2]>>base[1]>>base[0]>>d;
        if(d<1)
        {
            cout<<'1'<<'\n';
            continue;
        }
        for(int i=0; i<MAX; i++)ans[i] = poly[i]=0;
        ans[0]=1;
        counter=0;
        for(int i=0; i<d; i++)
        {
            for(int j=0; j<=counter; j++)
            {
                poly[j] = ans[j];
                ans[j] = 0;
            }
            for(int j=0; j<=counter; j++)
            {
                for(int k=0; k<=2; k++)
                    ans[j+k] += poly[j]*base[k];
            }
            counter+=2;
        }
        cout<<ans[counter];
        for(int i=counter-1; i>=0; i--)
            cout<<' '<<ans[i];
        cout<<'\n';
    }
    return 0;
}

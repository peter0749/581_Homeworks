#include <bits/stdc++.h>
#define MAX 600100
using namespace std;

int DP[MAX];
int arr[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    int term, n, maxval;
    cin>>term;
    while(term--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        DP[0] = arr[0];
        maxval = 0;
        for(int i=1; i<n; i++)
        {
            if(DP[i-1]<0) DP[i] = arr[i];
            else DP[i] = DP[i-1] + arr[i];
            maxval = max(maxval,DP[i]);
        }
        cout<<maxval<<'\n';
    }
    return 0;
}

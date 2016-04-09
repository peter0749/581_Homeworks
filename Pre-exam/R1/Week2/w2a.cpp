#include <bits/stdc++.h>
#define MAX 100
using namespace std;

typedef struct
{
    int y; int x;
}CORD;

int main(void)
{
    cin.sync_with_stdio(false);
    int term, n, maxval=-2000;
    int temp;
    CORD square[MAX];
    cin>>term;
    while(term--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>square[i].x>>square[i].y;
        }
        maxval=0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                temp = abs(square[i].x-square[j].x)*abs(square[i].y-square[j].y);
                if(temp>maxval)maxval=temp;
            }
        }
        cout<<maxval<<'\n';
    }
    return 0;
}

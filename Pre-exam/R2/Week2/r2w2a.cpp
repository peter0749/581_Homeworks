#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

int arr[MAX];
priority_queue<int, vector<int> , greater<int> > myque;

bool can_pass(const int N, const int M, const int D)
{
    int temp;
    for(int i=0; i<N; i++)
    {
        if(i<M)
            myque.push(arr[i]);
        else
        {
            temp = arr[i]+myque.top();
            myque.pop();
            myque.push(temp);
        }
    }
    while(myque.size()>1)myque.pop();
    temp = myque.top(); myque.pop();
    return temp<=D;
}

int sche(const int n, const int deadline)
{
    int upperb=n, lowerb=1;
    int midp;
    while( upperb > lowerb )
    {
        midp = (upperb+lowerb)/2;
        if(can_pass(n,midp,deadline))   upperb = midp;
        else lowerb = midp+1;
    }
    return lowerb;
}

int main(void)
{
    ios::sync_with_stdio(false);
    int term, deadline, n, maxterm;
    cin>>term;
    while(term--)
    {
        cin>>n>>deadline;
        maxterm = -1;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            if(arr[i] > maxterm) maxterm = arr[i];
        }
        if(maxterm > deadline)
        {
            cout<<"-1\n";
            continue;
        }
        cout << sche(n,deadline) << '\n';
    }
    return 0;
}

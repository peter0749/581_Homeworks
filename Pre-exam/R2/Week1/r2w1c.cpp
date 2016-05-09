#include <bits/stdc++.h>
using namespace std;

priority_queue<int , vector<int>, greater<int> > myque;

int main(void)
{
    ios::sync_with_stdio(false);
    int N,M, term, temp;
    cin>>term;
    while(term--)
    {
        cin>>N>>M;
        for(int i=0; i<N; i++)
        {
            cin>>temp;
            if(i<M)
                myque.push(temp);
            else
            {
                temp += myque.top();
                myque.pop();
                myque.push(temp);
            }
        }
        while(myque.size()>1)myque.pop();
        cout<<myque.top()<<'\n';
        myque.pop();
    }
    return 0;
}

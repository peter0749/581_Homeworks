#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int term, N, M, temp;
    priority_queue<int, vector<int>, greater<int> > que;
    ios::sync_with_stdio(false);
    cin>>term;
    while(term--)
    {
        cin>>N>>M;
        for(int i=0; i<N; i++)
        {
            cin>>temp;
            if(que.size()<M)que.push(temp);
            else
            {
                temp += que.top();
                que.pop();
                que.push(temp);
            }
        }

        while(que.size()>1) que.pop();
        cout<<que.top()<<'\n';
        que.pop();
    }
    return 0;
}

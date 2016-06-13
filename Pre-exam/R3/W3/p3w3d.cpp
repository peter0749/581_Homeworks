#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef vector<int> V;
bool visit[MAXN];
int step[MAXN];
V graph[MAXN];
stack<int> stk;

int main(void)
{
    int term, n, a, b, u, maxval=-1, maxnode=-1;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d", &n);
        for(int i=1; i<n; i++)
        {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=0; i<n; i++) visit[i] = false;
        for(int i=0; i<n; i++) step[i] = 0;
        maxval = maxnode = -1;
        stk.push(0);
        while(!stk.empty())
        {
            while( !stk.empty() && visit[stk.top()] ) stk.pop();//Pop all visited nodes;
            if(stk.empty()) break;
            u = stk.top(); stk.pop();
            visit[u] = true;
            for(int i=0; i<graph[u].size(); i++)
            {
                if(!visit[graph[u].at(i)])
                {
                    stk.push(graph[u].at(i));
                    step[graph[u].at(i)] = step[u]+1;
                }
            }
            if(step[u] > maxval)
            {
                maxval = step[u];
                maxnode = u;
            }
        }

        for(int i=0; i<n; i++) visit[i] = false;
        for(int i=0; i<n; i++) step[i] = 0;
        stk.push(maxnode);
        while(!stk.empty())
        {
            while( !stk.empty() && visit[stk.top()] ) stk.pop();//Pop all visited nodes;
            if(stk.empty()) break;
            u = stk.top(); stk.pop();
            visit[u] = true;
            for(int i=0; i<graph[u].size(); i++)
            {
                if(!visit[graph[u].at(i)])
                {
                    stk.push(graph[u].at(i));
                    step[graph[u].at(i)] = step[u]+1;
                }
            }
            if(step[u] > maxval)
            {
                maxval = step[u];
                maxnode = u;
            }
        }
        printf("%d\n", maxval);
        for(int i=0; i<MAXN; i++) graph[i].clear();
    }
    return 0;
}

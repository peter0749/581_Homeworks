#include <bits/stdc++.h>
#define MAXNODE 5011
#define MAXEDGE 100010
using namespace std;
typedef vector<unsigned int> V;
V graph[MAXNODE];
vector<bool> visit(MAXNODE);
V entry;
V val(MAXNODE);
unsigned int biggest;

inline void dfs(unsigned int n)
{
    visit[n] = true;
    if(val[n] > biggest)biggest = val[n];
    for(int i=0; i<graph[n].size(); i++)
    {
        if(!visit[graph[n].at(i)])
            dfs(graph[n].at(i));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    int n, m, t;
    unsigned int temp, a, b;
    while(cin>>n>>m>>t && n)
    {
        for(int i=0; i<t; i++)
        {
            cin>>temp;
            entry.push_back(temp);
        }
        for(int i=0; i<n; i++)
            cin>>val[i];
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            if(a==b)continue;
            graph[a].push_back(b);
        }
        biggest = 0;
        for(int i=0; i<n; i++)visit[i] = false;
        for(int i=0; i<t; i++)
        {
            //for(int j=0; j<n; j++)visit[j] = false;
            dfs(entry[i]);
        }
        cout<<biggest<<'\n';
        for(int i=0; i<n; i++)
            graph[i].clear();
        entry.clear();
    }
    return 0;
}

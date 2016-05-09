#include <bits/stdc++.h>
#define MAXNODE 50010
#define MAXEDGE 1000001
using namespace std;
typedef vector<int> V;
V gra[MAXNODE];
bool visit[MAXNODE];
int wei[MAXNODE];
int maxval=0;
int total=0;

void dfs(int node)
{
    visit[node] = true;
    total += wei[node];
    //cout<<total<<endl;
    for(int i=0; i<gra[node].size(); i++)
    {
        if(!visit[gra[node].at(i)])
            dfs(gra[node].at(i));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    int term, n, m, a, b;
    cin>>term;
    while(term--)
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
            cin>>wei[i];
        //for(int i=0; i<n; i++)cout<<wei[i]<<endl;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            if(a==b) continue;
            gra[a].push_back(b);
            gra[b].push_back(a);
        }
        for(int i=0; i<n; i++)visit[i]=false;
        maxval = 0;
        for(int i=0; i<n; i++)
        {
            if(!visit[i])
            {
                total = 0;
                dfs(i);
                if(total > maxval) maxval = total;
            }
        }
        for(int i=0; i<n; i++)gra[i].clear();
        cout<<maxval<<'\n';
    }
    return 0;
}

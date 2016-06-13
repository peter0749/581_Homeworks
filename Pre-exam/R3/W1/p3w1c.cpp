#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

typedef vector<int> V;

V graph[MAX];
bool visit[MAX];
V weight(MAX);
int DP[MAX][2];

void dfs(int tar)
{
    DP[tar][0] = 0;
    DP[tar][1] = weight[tar];
    visit[tar] = true;
    for(int i=0; i<graph[tar].size(); i++)
    {
        if(!visit[graph[tar].at(i)])
        {
            dfs(graph[tar].at(i));
            DP[tar][1] += DP[graph[tar].at(i)][0];
            DP[tar][0] += max(DP[graph[tar].at(i)][0], DP[graph[tar].at(i)][1]);
        }
    }
}

int main(void)
{
    int term, n, e;
    int a, b;
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d%d", &n, &weight[1]);
        for(int i=2; i<=n; i++)
        {
            scanf("%d%d", &a, &b);
            graph[i].push_back(a);
            graph[a].push_back(i);
            weight[i] = b;
        }

        for(int i=0; i<=n; i++) visit[i] = false;//haven't visit yet.
        dfs(1);
        printf("%d\n", max(DP[1][0], DP[1][1]));

        for(int i=0; i<MAX; i++)
            graph[i].clear();
    }
    return 0;
}

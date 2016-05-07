#include <bits/stdc++.h>
#define MAXNODE 1050
#define BUFFERLEN 5000
using namespace std;

typedef vector<int> V;
V graph[MAXNODE];
V weight;
V inc, nic, best;

inline void dfs(int enter)
{
	inc[enter] = weight[enter];
	nic[enter] = 0;
	for(int i=0; i<graph[enter].size(); i++)
	{
		dfs(graph[enter].at(i));
		nic[enter] += best[graph[enter].at(i)];
		inc[enter] += nic[graph[enter].at(i)];
	}
	best[enter] = max(inc[enter],nic[enter]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	int term, n, pa;
	cin>>term;
	while(term--)
	{
		for(int i=0; i<MAXNODE; i++)graph[i].clear();
		cin>>n;
		weight.resize(n+1);
		inc.resize(n+1);
		nic.resize(n+1);
		best.resize(n+1);
		cin>>weight.at(1);
		for(int i=2; i<=n; i++)
		{
			cin>>pa>>weight[i];
			graph[pa].push_back(i);
		}
		dfs(1);
		cout<<best[1]<<'\n';
		inc.clear();
		nic.clear();
		best.clear();
		weight.clear();
	}
	return 0;
}

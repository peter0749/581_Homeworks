#include <bits/stdc++.h>

using namespace std;
typedef vector<int> V;
typedef vector< V > LV;
V weight;
LV neighbor;
V visited;
int maxval=0;
int total = 0;

inline void dfs(const int u)
{
	total += weight.at(u);
	for(int i=0; i<neighbor.at(u).size(); i++)
	{
		if(!visited.at(neighbor.at(u).at(i)))
		{
			visited.at(neighbor.at(u).at(i))=true;
			dfs(neighbor.at(u).at(i));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	int term,n,m;
	int u, v;
	cin>>term;
	while(term--)
	{
		cin>>n>>m;
		visited.resize(n);
		for(int i=0; i<n; i++)visited.at(i) = false;
		neighbor.resize(n);
		weight.resize(n);
		for(int i=0; i<n; i++)
			cin>>weight.at(i);
		for(int i=0; i<m; i++)
		{
			cin>>u>>v;
			neighbor.at(u).push_back(v);
			neighbor.at(v).push_back(u);
		}
		maxval = total =  0;
		for(int i=0; i<n; i++)
		{
			if(!visited.at(i))
			{
				visited.at(i)=true;
				total = 0;
				dfs(i);
				if(total > maxval) maxval = total;
			}
		}
		
		cout<<maxval<<'\n';

		visited.clear();
		neighbor.clear();
		weight.clear();
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef vector<unsigned int> V;
typedef vector< V > L;
V start;
V treasure;
L gra;
vector<bool> visited;
unsigned int maxval=0;
stack<unsigned int> stk;

inline void dfs(unsigned int node)
{
	if(visited.at(node))return;
	visited.at(node)=true;
	if(treasure.at(node)  >  maxval) maxval = treasure.at(node);
	for(int i=0; i<gra.at(node).size(); i++)
	{
		if(!visited.at(gra.at(node).at(i)))
			dfs(gra.at(node).at(i));
	}
}

int main(void)
{
	unsigned int n,m,t;
	unsigned int temp, s;
	while(cin>>n>>m>>t)
	{
		if(n==0&&m==0&&t==0)break;
		gra.resize(n);
		visited.resize(n);
		for(int i=0; i<t; i++)
		{
			cin>>temp;
			start.push_back(temp);
		}
		for(int i=0; i<n; i++)
		{
			cin>>temp;
			treasure.push_back(temp);
		}
		for(int i=0; i<m; i++)
		{
			cin>>temp>>s;
			if(temp==s)continue;
			gra.at(temp).push_back(s);
		}

		maxval = 0;
		for(int i=0; i<t; i++)
		{
			for(int j=0; j<n; j++)visited.at(i)=false;
			dfs(start.at(i));
		}
		cout<<maxval<<'\n';
		treasure.clear();
		visited.clear();
		gra.clear();
		start.clear();
	}
	return 0;
}

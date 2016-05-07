#include <bits/stdc++.h>
#define MAXT 3
#define MAXV 100010
using namespace std;
int unit[MAXT];
int val[MAXT];
bool dp[MAXV]={false};

inline bool compo(const int m)
{
	int limit;
	for(int i=0; i<=m; i++)dp[i]=false;
	dp[0]=true;
	for(int i=0; i<MAXT; i++)
	{
		for(int j=m; j>=0; j--)
		{
			if(dp[j])
			{
				limit = unit[i];
				for(int k=j+val[i]; k<=m && limit>0 ; k+=val[i], limit--)
				{
					dp[k] = true;
				}
			}
		}
	}
	return dp[m];
}

int main(void)
{
	ios::sync_with_stdio(false);
	int term;
	int m;
	cin>>term;
	while(term--)
	{
		cin>>m;
		for(int i=0; i<MAXT; i++)
			cin>>unit[i];
		for(int i=0; i<MAXT; i++)
			cin>>val[i];
		if( compo(m) ) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;
}

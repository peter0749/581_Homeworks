#include <bits/stdc++.h>
#define MAXNODE 5050
using namespace std;

int weight[MAXNODE];
int pa[MAXNODE];
int subt_count[MAXNODE];

int main(void)
{
	ios::sync_with_stdio(false);
	int term, n;
	int sum;
	cin>>term;
	while(term--)
	{
		cin>>n;
		for(int i=0; i<=n; i++)subt_count[i]=1;
		for(int i=2; i<=n; i++)
			cin>>pa[i];
		for(int i=2; i<=n; i++)
			cin>>weight[i];
		for(int i=n; i>=2; i--)
		{
			subt_count[ pa[i] ] += subt_count[i];
		}
		sum = 0;
		for(int i=n; i>=2; i--)
		{
			//cout<<subt_count[i]<<endl;
			sum += (weight[i] * subt_count[i] * (n - subt_count[i]));
		}
		sum<<=1;
		cout<<sum<<'\n';
	}
	return 0;
}

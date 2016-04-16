#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

int arr[MAX];
priority_queue<int, vector<int> , greater<int> >que;

int sche(int n, int m)
{
	int time=0;
	int total=0;
	int i, j;
	while(!que.empty())que.pop();
	for(i=0; i<n; i++)
	{
		if(i<m)que.push(arr[i]);
		else
		{
			time = que.top() + arr[i];
			que.pop();
			que.push(time);
		}
	}
	while(que.size()>1)que.pop();
	total = que.top();
	que.pop();
	return total;
}

int getMachineN(int N, int D)
{
	int lowerb=1, upperb=N;
	int mid, temp;
	while(upperb>lowerb)
	{
		mid = (lowerb+upperb)>>1;
		if((temp=sche(N,mid))>D)lowerb=mid+1;
		else upperb=mid;
	}
	return lowerb;
}

int main(void)
{
	int term;
	int N, M;
	int maxc;
	cin>>term;
	while(term--)
	{
		cin>>N>>M;
		maxc=-1;
		for(int i=0; i<N; i++)
		{
			cin>>arr[i];
			if(arr[i] > maxc) maxc = arr[i];
		}
		if(maxc>M)cout<<"-1\n";
		else
		{
			cout<<getMachineN(N,M)<<'\n';
		}
	}
	return 0;
}

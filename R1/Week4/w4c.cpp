#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX 10000
#define ALNUM 26

using namespace std;

int main(void)
{
	cout.sync_with_stdio(false);
	int term;
	int maxcount;
	int alco[ALNUM];
	char temp[MAX];
	int itemp;
	int i;
	char *ptr=NULL;
	cin.getline(temp,MAX);
	term = atoi(temp);
	while(term--)
	{
		maxcount = 0;
		for(i=0; i<ALNUM; i++)alco[i] = 0;
		cin.getline(temp,MAX);
		ptr = temp;
		while(ptr!=NULL && *ptr!='\0')
		{
			if(isalpha(*ptr))
			{
				itemp = toupper(*ptr)-'A';
				alco[itemp]++;
				if(alco[itemp]>maxcount)maxcount = alco[itemp];
			}
			ptr++;
		}
		for(i=0;i<ALNUM;i++)
		{
			if(alco[i]==maxcount)cout<<(char)('A'+i);
		}
		cout<<'\n';
	}
	return 0;
}

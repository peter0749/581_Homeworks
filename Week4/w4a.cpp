#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#define ARRMAX 1010
#define MAX 100000
using namespace std;

const char tok[]=" \n";

int cmpx(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

int cmpy(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

double mydist(int x, int y)
{
	return sqrt(x*x+y*y);
}

inline int datain(int xcord[])
{
	int n=0;
	char temp[MAX];
	char *ptr;
	cin.getline(temp,MAX);
	ptr = strtok(temp,tok);
	while(ptr!=NULL)
	{
		xcord[n++] = abs(atoi(ptr));
		ptr = strtok(NULL,tok);
	}
	return n;
}

int main(void)
{
	cout.sync_with_stdio(false);
	int term;
	char temp[MAX];
	int i;
	int xcord[ARRMAX],ycord[ARRMAX];
	int n;
	double sum=0.0;
	int ty;
	cin.getline(temp,MAX);
	term = atoi(temp);
	while(term--)
	{
		sum=0.0;
		datain(xcord);
		n = datain(ycord);

		qsort(xcord,n,sizeof(int),cmpx);
		qsort(ycord,n,sizeof(int),cmpy);
		for(i=0; i<n; i++)
		{
			sum += mydist(xcord[i],ycord[i]);
		}
		cout<<(int)sum<<'\n';
	}
	return 0;
}

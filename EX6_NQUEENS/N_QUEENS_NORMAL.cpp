#include <bits/stdc++.h>
#define MAX 101
/*Size of maximum size of checkerboard.*/

using namespace std;

int weight[MAX][MAX] = {{0}};/*Record of scores on checkerboard.*/
int dfsstk[MAX];/*Check oblique direction.*/
unsigned int testbit[MAX];/*Check rows and columns.*/
int maxval=0;/*Maximum score.*/

int find_bit(const int n)
{
    int index = n/sizeof(int);
    int diff = n%sizeof(int);
    return testbit[index]&(1u<<diff);/*If found, return 1, else return 0.*/
}

void set_bit(const int n)
{
    int index = n/sizeof(int);
    int diff = n%sizeof(int);
    testbit[index] |= (1u<<diff);/*Set the nth bit.*/
}

void unset_bit(const int n)
{
    int index = n/sizeof(int);
    int diff = n%sizeof(int);
    testbit[index] &= ~(1u<<diff);/*unset the nth bit.*/
}

void dfs(int curr_d, const int max_d, int sum)
{
    int conflict(0);
    if(curr_d==max_d)
    {
        if(sum>maxval)maxval=sum;
    }
    else
    {
        for(int i=0; i<max_d; i++)
        {
            /* 0~n-1 bits records the queen at (curr_d)th col. (i)th row.*/
            if(!find_bit(i))
            {
                for(int j=0; j<curr_d; j++)//o
                {
                    /*Check obliquely*/
                    if(abs(dfsstk[j]-i)==(curr_d-j))
                    {
                        conflict=1;
                        break;
                    }
                }
                if(conflict)
                {
                    conflict=0;
                    continue;
                }
                //else
                dfsstk[curr_d] = i;
                set_bit(i);
                dfs(curr_d+1,max_d,sum+weight[curr_d][i]);/*Add the score*/
                unset_bit(i);/*For back-tracking*/
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    //freopen("testout.txt","w",stdout);
    //freopen("exercise6_test.in","r",stdin);
    int n, term;
    cin>>term;
    while(term--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>weight[i][j];/*Scores*/
        }
        for(int i=0; i<n; i++)
        {
            testbit[i] = 0;/*Initialize*/
        }
        maxval = 0;
        dfs(0,n,0);/*At first, the sum of scores is 0*/
        cout<<maxval<<'\n';/*Printout the maximum sum of scores.*/
    }
    return 0;
}

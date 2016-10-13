#include <bits/stdc++.h>
#define MAX_SIZE 13

using namespace std;

const char dir[8][2] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} }; //Eight different directions. Clockwise. (col, row)
short chb[MAX_SIZE][MAX_SIZE] = {{0}};

/* 0 for empty, 1 for stone, 2 for queens, 3 for paths of queens. */
int maxval = 0;

void dfs(int col, int row, const int max_depth, int sum)
{
    bool test = (row == max_depth);//At the end of row.
    if( (max_depth-col)*max_depth + (max_depth - row + 1) + sum <= maxval ) return;
    //A lower-bound. If remaining blocks + sum <= maxval, then there is impossible a better solution exist.
    if(col>max_depth)//Halt condition
    {
        if(sum > maxval)maxval = sum;
        return;
    }
    if(chb[col][row]==0)//Can place a queen;
    {
        for(int i=0, j; i<8; i++)//Fill eight different direction;
        {
            for(j=1; chb[dir[i][0]*j + col][dir[i][1]*j + row]!=1 ; j++)//Fill until reach a stone.
                chb[dir[i][0]*j + col][dir[i][1]*j + row] --;//Mark;
        }
        chb[col][row] = 2;
        test ? dfs(col+1, 1, max_depth, sum+1) : dfs(col, row+1, max_depth, sum+1);//Place;
        /*Restore*/
        chb[col][row] = 0;
        for(int i=0, j; i<8; i++)//Fill eight different direction;
        {
            for(j=1; chb[dir[i][0]*j + col][dir[i][1]*j + row]!=1 ; j++)
                chb[dir[i][0]*j + col][dir[i][1]*j + row] ++;//Mark;
        }
        /*End of restoration.*/
    }
    test ? dfs(col+1, 1, max_depth, sum) : dfs(col, row+1, max_depth, sum);//Dont Place;
}

int main(void)
{
    ios::sync_with_stdio(false);
    //freopen("exercise6_advance_test.in","r",stdin);
    //freopen("adv_out.out","w",stdout);
    int term, n, t;
    /*Initialize.*/
    for(int i=0, j; i<MAX_SIZE; i++)
        for(j=0; j<MAX_SIZE; j++)
            chb[i][j]=1; //Build Stone Walls.
    cin>>term;
    while(term--)
    {
        cin>>n;
        t = n+1;
        for(int i=0; i<=t; i++)
        {
            chb[0][i] = chb[t][i] = chb[i][0] = chb[i][t] = 1;//Clean-UP;
        }
        for(int i=1, j; i<=n; i++)
            for(j=1; j<=n; j++)
                cin>>chb[i][j];
        maxval = 0;
        dfs(1,1,n,0);
        cout<<maxval<<'\n';
    }
    return 0;
}

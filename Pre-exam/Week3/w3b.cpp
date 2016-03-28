#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

typedef struct
{
    int pos;
    int dir;
}FROG;

//FROG rec[MAX];
int book[MAX][2];
int cells[MAX];

inline int go_frog(FROG *frog, const int n)
{
    int temp;
    int step = 1;
    while(frog->pos>=0 && frog->pos<n)
    {
        temp = frog->dir<1?0:1;
        if(book[frog->pos][temp]>0)return step-book[frog->pos][temp];
        book[frog->pos][temp] = step;
        if(cells[frog->pos]<0)frog->dir = -frog->dir;
        frog->pos = frog->pos + abs(cells[frog->pos]) * frog->dir;
        step++;
    }
    return frog->pos<0?-2:-1;
}

int main(void)
{
    int cell, op, i;
    int step;
    FROG frog;
    while(cin>>cell>>op)
    {
        if(cell==0||op==0)break;
        for(i=0; i<cell; i++)cin>>cells[i];

        while(op--)
        {
            for(i=0; i<=cell; i++)book[i][0] = book[i][1] = 0;
            cin>>frog.pos>>frog.dir;
            step = go_frog(&frog,cell);
            if(step==-1)cout<<"Forward\n";
            else if(step==-2)cout<<"Backward\n";
            else cout<<"Cycle "<<step<<'\n';
        }
    }
    return 0;
}

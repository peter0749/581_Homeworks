#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#define MAX 100001

using namespace std;

int digit[MAX] = {0};
int book[MAX] = {0};

int modN(int x, int y, int N)
{
    int i, base(1);
    if(x==0)    return 0;
    if(y==0)    return 1;
    //getch();cout<<"ok"<<endl;
    for(i=0;i<N;i++)   book[i]=0;
    //x%=N;
    for(i=1; i<=y;i++)
    {
        base = (base*x)%N;
        //cout<<base<<endl;
        if(book[base]!=0) break;
        book[base] = i;
        digit[i] = base;
    }
    if(i>y)
    {
        return base;
    }
    //return -1;
    return digit[book[base]+(y-i)%(i-book[base])];
}

int main(void)
{
    int term;
    int x, y, N;
    cin>>term;
    while(term--)
    {
        cin>>x>>y>>N;
        cout<<modN(x,y,N)<<"\n";
    }
    return 0;
}

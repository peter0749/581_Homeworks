#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int gcd(int x, int y)/*Note: x>y*/
{
    return x%y==0? y : gcd(y,x%y);
}

int main(void)
{
    int term, Q1, R1, Q2, R2, G;
    int stk[1000], top;
    cin>>term;
    while(term--)
    {
        top = -1;
        cin>>Q1>>R1>>Q2>>R2;
        G=gcd(Q1-R1,Q2-R2);
        cout<<"1";
        if(G!=1)
        {
            stk[++top] = G;
        }
        for(int i=2; i*i<=G; i++)
        {
            if(G%i==0)
            {
                stk[++top] = G/i;
                cout<< " " <<i;
            }
        }
        if(top>=0&&stk[top]*stk[top]==G)    top--;
        while(top>=0)
        {
            cout<<" "<<stk[top--];
        }
        cout<<"\n";
    }
    return 0;
}

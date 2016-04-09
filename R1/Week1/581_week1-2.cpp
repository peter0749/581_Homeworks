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
    cin>>term;
    while(term--)
    {
        cin>>Q1>>R1>>Q2>>R2;
        G=gcd(Q1-R1,Q2-R2);
        cout<<"1";
        for(int i=2; i<=G; i++)
        {
            if(G%i==0)  cout<< " " <<i;
        }
        cout<<"\n";
    }
    return 0;
}

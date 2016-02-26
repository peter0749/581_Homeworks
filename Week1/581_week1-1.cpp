#include <iostream>
#include <iomanip>
#include <string>
#define MAX 1001

using namespace std;

int mtx[MAX] = {0}, cp_mtx[MAX] = {0}, temp[MAX] = {0};

inline void mul(int deg)
{
    for(int i=0; i<=deg; i++)
    {
        for(int j=0; j<=2; j++)
        {
            temp[i+j] += (mtx[i] * cp_mtx[j]);
        }
    }
}

int main(void)
{
    int term, power, deg;
    cin>>term;
    while(term--)
    {
        cin>>mtx[2]>>mtx[1]>>mtx[0]>>power;
        for(int i=0; i<=2; i++) cp_mtx[i]=mtx[i];
        deg = 2;
        while(--power)
        {
            mul(deg);
            deg+=2;
            for(int i=0; i<=deg; i++)
            {
                mtx[i] = temp[i];
                temp[i] = 0;
            }
        }
        cout<<mtx[deg];
        for(int i=deg-1; i>=0; i--)
        {
            cout<<" "<<mtx[i];
        }
        cout<<"\n";
    }
    return 0;
}

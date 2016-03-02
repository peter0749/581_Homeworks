#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
typedef long long int LL;

int main(void)
{
    LL A, B, M, base=1;

    while(1)
    {
        base=1;
        cin>>A>>B>>M;
        A%=M;
        while(B)
        {
            if(B&1uLL)
            {
                base*=A;
                base%=M;
                cout<<base<<endl;
            }
            A = A*A;
            A%=M;
            B>>=1;
        }
        cout<<base<<"\n";

    }



    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define MAX 1000

using namespace std;

int main(void)
{
    char temp[MAX];
    int i;
    int deci(0);
    int sum(0);
    int len(0);
    int term;
    while(1)
    {
        cin>>term;
        if(term==0) break;
        sum = 0;
        while(term--)
        {
            cin>>temp;
            len = strlen(temp);
            for(i=0; i<len&&temp[i]=='0'; i++);
            if(i==len)
            {
                //if(i<=1)    break;
                //cout<<"0\n";
                continue;
            }
            deci=0;
            for(; i<len; i++)
            {
                deci<<=1;
                if(temp[i]=='1')
                {
                    deci|=1;
                }
            }
            sum += deci;
        }
        cout<<sum<<'\n';
    }

    return 0;
}

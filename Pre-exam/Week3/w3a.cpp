#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main(void)
{
    cin.sync_with_stdio(false);
    int term;
    int i;
    char temp[MAX];
    int sum;
    int num;
    while((cin.getline(temp,MAX))!=NULL)
    {
        term = atoi(temp);
        if(term==0)break;
        sum = 0;
        while(term--)
        {
            num = 0;
            cin.getline(temp,MAX);
            for(i=0; temp[i]=='0'; i++);
            for(;temp[i]!='\0';i++)
            {
                num <<= 1;
                if(temp[i]=='1')
                    num |= 1;
            }
            sum+=num;
        }
        cout<<sum<<'\n';
    }
    return 0;
}

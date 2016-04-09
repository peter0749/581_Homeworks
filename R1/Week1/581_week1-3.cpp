#include <iostream>
#include <iomanip>
#include <string>
#define MAX 1000011

using namespace std;

int main(void)
{
    int *book =  new int[MAX];
    int num, p, i;
    while(1)
    {
        cin >> num >> p;
        if(p==0)    break;
        for(i=0; i!=p; i++)    book[i] = 0;
        num%=p;
        for(i=1;; i++)
        {
            if(book[num = num*10%p]>0)    break;
            book[num]=i;
        }
        cout<<i-book[num]<<"\n";
    }
    delete [] book;
    return 0;
}

#include <bits/stdc++.h>
#define MAX 10010
using namespace std;

inline int cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    cout.sync_with_stdio(false);
    int term;
    int sum;
    int citem;
    int arr[MAX];
    cin>>term;
    while(term--)
    {
        cin>>citem;
        for(int i=0; i<citem; i++)cin>>arr[i];
        qsort(arr,citem,sizeof(int),cmp);
        sum = 0;
        for(int i=0; i<citem; i++)
        {
            //cout<<arr[i]<<endl;
            sum += arr[i]*(2*i+1);
        }
        cout<<sum<<'\n';
    }
    return 0;
}

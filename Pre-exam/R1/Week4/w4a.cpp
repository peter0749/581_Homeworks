#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

inline int xcmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

inline int ycmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    cin.sync_with_stdio(false);
    int term;
    int n;
    double sum;
    char temp[MAX];
    char *tok=" \n";
    char *ptr=NULL;
    int xcord[MAX],ycord[MAX];
    cin.getline(temp,MAX);
    term = atoi(temp);
    while(term--)
    {
        cin.getline(temp,MAX);
        n = 0;
        ptr = strtok(temp,tok);
        while(ptr!=NULL)
        {
            xcord[n++] = abs(atoi(ptr));
            ptr = strtok(NULL,tok);
        }
        cin.getline(temp,MAX);
        n = 0;
        ptr = strtok(temp,tok);
        while(ptr!=NULL)
        {
            ycord[n++] = abs(atoi(ptr));
            ptr = strtok(NULL,tok);
        }
        qsort(xcord,n,sizeof(int),xcmp);
        qsort(ycord,n,sizeof(int),ycmp);
        sum = 0.0;
        for(int i=0; i<n; i++)
        {
            sum += sqrt(xcord[i]*xcord[i]+ycord[i]*ycord[i]);
        }
        cout<<(int)sum<<'\n';
    }
    return 0;
}

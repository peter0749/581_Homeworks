#include <bits/stdc++.h>
#define MAX 10000
#define LETTERMAX 26

using namespace std;

int main(void)
{
    int term;
    int maxval;
    char temp[MAX];
    int arr[LETTERMAX];
    cin.getline(temp,MAX);
    term = atoi(temp);
    while(term--)
    {
        for(int i=0; i<LETTERMAX; i++) arr[i] = 0;
        cin.getline(temp,MAX);
        for(int i=0; temp[i]!='\0' ; i++)
        {
            if(isalpha(temp[i]))
                arr[toupper(temp[i])-'A']++;
        }
        maxval = 0;
        for(int i=0; i<LETTERMAX; i++)
            if(arr[i]>maxval)maxval=arr[i];
        for(int i=0; i<LETTERMAX; i++)
            if(arr[i]==maxval)cout<<(char)(i+'A');
        cout<<'\n';
    }

    return 0;
}

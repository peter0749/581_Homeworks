#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int main(void)
{
    cin.sync_with_stdio(false);
    char temp[MAX];
    char *ptr1, *ptr2, *seekptr;
    const char tok[]=" \n";
    int len;
    int counter=0;
    while((cin.getline(temp,MAX))!=NULL)
    {
        counter=0;
        ptr1 = strtok(temp,tok);

        ptr2 = strtok(NULL,tok);

        len = strlen(ptr1);
        while(ptr2!=NULL && *ptr2!='\0')
        {
            if(strncmp(ptr1,ptr2,len)==0)counter++;
            ptr2++;
        }
        cout<<counter<<'\n';
    }

    return 0;
}

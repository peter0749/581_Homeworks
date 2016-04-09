#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAX 1000

using namespace std;

int main(void)
{
    char temp[MAX];
    char *ptr1, *ptr2;
    int len1,len2;
    int counter;
    while((cin.getline(temp,MAX))!=NULL)
    {
        counter = 0;
        ptr1 = strtok(temp," \n");
        ptr2 = strtok(NULL," \n\0");
        //cout<<ptr1<<' '<<ptr2<<endl;
        len1 = strlen(ptr1);
        len2 = strlen(ptr2);
        //cout<<len1<<' '<<len2<<endl;
        //len2-=len1;
        for(int i=0; i<=len2-len1;i++)
        {
            if(strncmp(ptr1,ptr2+i,len1)==0)  counter++;
        }
        cout<<counter<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
#define MAX 100010
using namespace std;

inline int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int term;
    int citem, cstudent, sum;
    int item[MAX], stu[MAX];
    int i, j;
    cin.sync_with_stdio(false);
    cin>>term;
    while(term--)
    {
        cin>>citem>>cstudent;
        for(int i=0; i<citem; i++)cin>>item[i];
        for(int i=0; i<cstudent; i++)cin>>stu[i];
        if(citem>cstudent)
        {
            cout<<"-1\n";
            continue;
        }
        qsort(stu,cstudent,sizeof(int),cmp);
        qsort(item,citem,sizeof(int),cmp);
        i = j = sum = 0;
        while(i<cstudent&&j<citem)
        {
            while(i<cstudent&&stu[i]<item[j])i++;
            if(i>=cstudent){sum=-1;break;}
            sum+=stu[i];
            i++;j++;
        }
        cout<<sum<<'\n';
    }
    return 0;
}

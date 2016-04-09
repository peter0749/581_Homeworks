#include <iostream>
#include <algorithm>

using namespace std;
class STU
{
        public:
                int wei, deadline;
                STU()
                {
                        wei = deadline = 0;
                }
                int operator< (STU compar2)const
                {
                        return deadline < compar2.deadline;
                }
};

int main(void)
{
        int term, n;
        int i;
        STU *ptr=NULL;
        int total=0;
        ios::sync_with_stdio(false);
        cin>>term;
        while(term--)
        {
                cin>>n;
                ptr = new STU[n];
                total = 0;

                for(i=0; i<n; i++)cin>>ptr[i].wei;
                for(i=0; i<n; i++)cin>>ptr[i].deadline;
                sort(ptr,ptr+n);

                for(i=0; i<n; i++)
                {
                        total += ptr[i].wei;
                        if(total>ptr[i].deadline)break;
                }

                if(i==n)cout<<"Yes\n";
                else    cout<<"No\n";
                delete [] ptr;
                ptr=NULL;
        }
        return 0;
}

#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef vector<int> V;

stack<int, vector<int> > stk;
V gra[MAXN];
vector<bool>visit(MAXN);
V node_depth(MAXN);

int main(void)
{
    ios::sync_with_stdio(false);
    int term, n, a, b;
    int u, node1, node2, max1,max2;
    cin>>term;
    while(term--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            gra[i].clear();
        }
        for(int i=1; i<n; i++)
        {
            cin>>a>>b;
            gra[a].push_back(b); gra[b].push_back(a);
        }
        u = -1;
        node1 = max1 = -1;
        fill(node_depth.begin(),node_depth.begin()+n,0);
        fill(visit.begin(),visit.begin()+n, false);
        stk.push(0);
        while(!stk.empty())
        {
            while(!stk.empty()&&visit.at(stk.top()))stk.pop();//Pop all visited;
            if(stk.empty())break;//Check if stack empty;
            u = stk.top();stk.pop();
            for(int i=0; i<gra[u].size(); i++)
            {
                if(!visit[gra[u].at(i)])//If not visited;
                {
                    stk.push(gra[u].at(i));//Push into stack
                    node_depth.at(gra[u].at(i)) = node_depth.at(u) + 1;//It's a tree, no problem.
                    if(node_depth.at(gra[u].at(i)) > max1)
                    {
                        max1 = node_depth.at(gra[u].at(i));
                        node1 = gra[u].at(i);
                    }
                }
            }
            visit.at(u) = true;
            //cout<<"Passed1: "<<u<<endl;
        }
        //cout<<"End1: "<<u<<endl;
        //cout<<"Max1: "<<max1<<"\nNode1: "<<node1<<endl;
        fill(node_depth.begin(),node_depth.begin()+n,0);
        fill(visit.begin(),visit.begin()+n,false);
        max2 = node2 = -1;
        stk.push(node1);
        while(!stk.empty())
        {
            while(!stk.empty()&&visit.at(stk.top()))stk.pop();//Pop all visited;
            if(stk.empty())break;//Check if stack empty;
            u = stk.top();stk.pop();
            for(int i=0; i<gra[u].size(); i++)
            {
                if(!visit[gra[u].at(i)])//If not visited;
                {
                    stk.push(gra[u].at(i));//Push into stack
                    node_depth.at(gra[u].at(i)) = node_depth.at(u) + 1;//It's a tree, no problem.
                    if(node_depth.at(gra[u].at(i)) > max2)
                    {
                        max2 = node_depth.at(gra[u].at(i));
                        node2 = gra[u].at(i);
                    }
                }
            }
            visit.at(u) = true;
            //cout<<"Passed2: "<<u<<endl;
        }
        //cout<<"End2: "<<u<<endl;
        //cout<<"Max2: "<<max2<<"\nNode2: "<<node2<<endl;
        cout<<max2<<'\n';
    }
    return 0;
}

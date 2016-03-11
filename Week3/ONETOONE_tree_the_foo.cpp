#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#define MAX 1000000

using namespace std;

typedef struct nodes
{
    int key;
    struct nodes *left, *right;
} btree;

void push(int n, btree *ptr)
{
    if(n>ptr->key)
    {
        if(ptr->right==NULL)
        {
            ptr->right = new btree;
            ptr->right->key = n;
            ptr->right->left = ptr->right->right = NULL;
        }
        else
            push(n,ptr->right);
    }
    else
    {
        if(ptr->left==NULL)
        {
            ptr->left = new btree;
            ptr->left->key = n;
            ptr->left->left = ptr->left->right = NULL;
        }
        else
            push(n,ptr->left);
    }
}

void travel(int data[], int *index, btree *ptr)
{
    if(ptr==NULL)   return;
    travel(data,index,ptr->left);
    data[(*index)++] = ptr->key;
    //cout<<ptr->key<<endl;
    travel(data,index,ptr->right);
    delete ptr;
}

void tsort(int out[], int n)
{
    int i;
    int flag = 0;
    btree *head=NULL;
    head = new btree;
    head->key = out[0];
    head->left = head->right = NULL;
    for(i=1; i<n; i++)
        push(out[i],head);
    travel(out,&flag,head);
}


int main(void)
{
    //int arr[]= {5,4,3,2,1};
    int *enemy=NULL, *ally=NULL;
    int  ce, win;
    int i, j;
    //freopen("testout.txt","w",stdout);

    //tsort(arr,5);
    //for(i=0;i<5;i++)cout<<arr[i]<<endl;
    //cin>>term;
    while(1)
    {
        cin>>ce;
        if(ce==0)break;
        enemy = new int[ce];
        for(i=0;i<ce;i++)cin>>enemy[i];
        //cin>>ca;
        ally = new int[ce];
        for(i=0;i<ce;i++)cin>>ally[i];
        tsort(enemy,ce);
        tsort(ally,ce);

        //for(i=0;i<ce;i++)cout<<enemy[i]<<endl;
        //for(i=0;i<ca;i++)cout<<ally[i]<<endl;

        win = i = j = 0;

        while(i<ce&&j<ce)
        {
            while(i<ce&&ally[i]<=enemy[j])i++;
            if(i==ce) break;
            win++;
            i++;
            j++;
        }
        cout<<win<<'\n';
        delete [] ally;
        delete [] enemy;
        ally = enemy = NULL;
    }

    return 0;
}

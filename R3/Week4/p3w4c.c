#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <time.h>
#define MAXN 50
#define MAX 1000000000
int val[MAXN], wei[MAXN];
int answer;
//bool add[MAXN];
int wlb, wub, llb, n;
//bool DP[MAX];
//int DP[MAXN][MAXN];//num, weight, val;

void brute_force(const int max_depth, int depth, int num, int w, int v)
{
    int temp;
    if(depth >= max_depth || w>wub)return;
    if(num>=llb && w>=wlb)
    {
        temp = (v+w-1)/w;
        if(temp > answer) answer = temp;
    }
    brute_force(max_depth, ++depth, num, w, v);
    brute_force(max_depth,depth, num+1, w+wei[depth], v+val[depth]);
}

int main(void)
{
    //srand(time(NULL));
    int i, j, input_end;
    do{
        scanf("%d%d%d%d",&n,&llb,&wlb,&wub);
        for(i=0; i<n; i++)
        {
            scanf("%d%d", val+i, wei+i);
            //val[i] = rand()%100;
            //wei[i] = rand()%10;
        }
        answer = -1;
        //for(i=0; i<n; i++) add[i]=false;//initialize
        //for(i=0; i<n; i++)for(j=0; j<n; j++)DP[i][j] = -1;
        brute_force(n,-1,0,0,0);
        printf("%d\n", answer);
    }while( scanf("%d", &input_end) && input_end!=-1 );
    return 0;
}

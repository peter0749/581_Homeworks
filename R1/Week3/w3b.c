#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10003

typedef struct
{
    char dire;
    int position;
} FROG;

//FROG rec[MAX] = {0};
int book[MAX][2] = {0}; /*index 0 for forward, 1 for backward*/
int map[MAX] = {0};

int go_frog(const int n, FROG *frog)
{
    int step = 0;
    int temp = 0;
    while(frog->position >= 0 && frog->position < n)
    {
        //rec[++step] = *frog;
        ++step;
        temp = frog->dire==1?0:1;
        if(book[frog->position][temp]!=0)
        {
            return step - book[frog->position][temp];
        }
        book[frog->position][temp] = step;
        if(map[frog->position]<0)   frog->dire = -frog->dire;
        frog->position = frog->position + (frog->dire) * abs(map[frog->position]);
    }
    return frog->dire>0?-1:-2;
}

int main(void)
{
    int mapsize, inst;
    int i;
    FROG current;
    int cycle;
    while(scanf("%d %d", &mapsize, &inst)!=EOF)
    {
        if(mapsize==0 && inst==0)   break;
        for(i=0; i<mapsize; i++)
        {
            scanf("%d", &map[i]);
        }
        while(inst--)
        {
            for(i=0; i<mapsize;i++)
                book[i][0] = book[i][1] = 0;
            scanf("%d %d", &current.position, &current.dire);
            //printf("%d %d\n",current.position, current.dire);
            cycle = go_frog(mapsize, &current);
            if(cycle==-1)
            {
                puts("Forward");
            }
            else if(cycle==-2)
            {
                puts("Backward");
            }
            else
                printf("Cycle %d\n",cycle);
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, int *argv[])
{
    int i;
    int sum = 0 ;
    for(i=1;i<=argc;i++)
    {
        sum += atoi(argv[i]);
    }
    printf("%d\n",sum);
    return 0;
}

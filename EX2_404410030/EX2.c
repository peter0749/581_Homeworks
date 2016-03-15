#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, int *argv[])
{
    int i;
    int sum = 0 ;
    int type;
    char pause;
    char *ptr=NULL;
    if(argc<=1)
    {
        printf("Please enter parameters.\n\nEX2.exe [--help]|[/h]|[/?] will display helping page.\nPress ENTER to exit.\n");
        pause = getchar();
        return -2;
    }
    if(strcmp(argv[1],"--help")==0||strcmp(argv[1],"/?")==0||strcmp(argv[1],"/h")==0)
    {
        printf("\n#####Author: Kuang-Yu Jeng#####\n\nUsage:\nEX2.exe [base_n] \( [num1] [num2] [num3]...\)\n\nWill sum up the numbers in base_n \(Display in base 10\)\n\nEX2.exe [--help]|[/h]|[/?] will display this helping page.\n");
        return 0;
    }
    type = atoi(argv[1]);
    if(type<2||type>32)
    {
        printf("Invalid base!\n\nEX2.exe [--help]|[/h]|[/?] will display helping page.\n");
        return -1;
    }

    for(i=2;i<=argc;i++)
    {
        sum += strtol(argv[i],&ptr,type);
    }

    printf("%d\n",sum);
    return 0;
}

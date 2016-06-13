#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50000
int main(void)
{
    char temp[MAX];
    char input[MAX];
    char *ptr;
    int num, i;
    while((fgets(input, MAX, stdin))!=NULL)
    {
        strtok(input,"\n\b\r");
        ptr = input;
        while(ptr!=NULL && *ptr!='\0')
        {
            i=0;
            while(ptr!=NULL && *ptr!='\0' && isdigit(*ptr)) temp[i++] = *(ptr++);
            temp[i] = '\0';
            num = atoi(temp);
            i=0;
            while(ptr!=NULL && *ptr!='\0' && !isdigit(*ptr)) temp[i++] = *(ptr++);
            temp[i] = '\0';
            for(i=0; i<num; i++) printf("%s", temp);
        }
        printf("\n");
    }
    return 0;
}

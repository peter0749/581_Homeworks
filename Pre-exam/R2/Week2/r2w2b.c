#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 5000

int main(void)
{
    char temp[MAX];
    char *ptr=NULL;
    const int lendiff = 'z' + 'A';
    //freopen("testout.txt","w",stdout);
    while(fgets(temp,MAX,stdin)!=NULL)
    {
        ptr = temp;
        while(ptr!=NULL && *ptr!='\0')
        {
            if(isalpha(*ptr))
            {
                *ptr = lendiff - *ptr;
            }
            if(isdigit(*ptr))
            {
                if(*ptr!='9') *ptr = *ptr + 1;
                else *ptr = '0';
            }
            ptr++;
        }
        fprintf(stdout,"%s",temp);
    }
    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#define T 1
#define F 0
#define MAX 1000
#define TEMPLEN 60

using namespace std;

typedef struct
{
    char ACCOUNT[MAX];
    char DOMAIN[MAX];
} EMAIL;

int mySTRCMP(char const *tar, char const *src)
{
    while((*tar)!='\0'&&(*src)!='\0')
    {
        if(tolower(*tar)>tolower(*src))   return 1;/*Ignore difference of Capital and lower case.*/
        else if(tolower(*tar)<tolower(*src))  return -1;
        tar++;
        src++;
    }
    return 0;
}

int cmpACCOUNT(const void *a, const void *b)
{
    EMAIL *dead = (EMAIL*)a;
    EMAIL *beef = (EMAIL*)b;

    return mySTRCMP(dead->ACCOUNT,beef->ACCOUNT);/*Compare base on ACCOUNT*/
}

int cmpDOMAIN(const void *a, const void *b)
{
    EMAIL *dead = (EMAIL*)a;
    EMAIL *beef = (EMAIL*)b;
    int diffDOMAIN = mySTRCMP(dead->DOMAIN,beef->DOMAIN);

    if(diffDOMAIN==0)
        return mySTRCMP(dead->ACCOUNT,beef->ACCOUNT);

    return diffDOMAIN;/*Compare base on DOMAIN+ACCOUNT*/
}

int valid(const char *head, const char *tail)
{
    char *ptr;
    int i;
    const char diff[2]= {1,-1};

    if(tail-head==0)    return F;/*Empty, not valid*/
    ptr=(char*)head;
    //int dot = -1;
    while(ptr!=NULL&&ptr!=tail)
    {
        if(!isalnum(*ptr)&&*ptr!='_'&&*ptr!='.'&&*ptr!='-')/*Check if the character is not valid. */
        {
            return F;
        }
        if(*ptr=='.')
        {
            if(ptr==head||ptr==tail)    return F;/*Can't appear at head and tail. And prevent the next statement cause Segment Fault.*/
            for(i=0; i<2; i++)
            {
                if(*(ptr+diff[i])=='.')   return F;/*Check if there are double dots. */
            }
            //dot++;
        }
        ptr++;
    }
    //if(dot<0) return F;
    return T;
}

void mypush(char *input, EMAIL *data)
{
    const char tok[]="@\n";
    char *ptr;
    ptr = strtok(input,tok);
    strcpy(data->ACCOUNT,ptr);
    ptr = strtok(NULL,tok);
    strcpy(data->DOMAIN,ptr);
}

void mySORT(int n, EMAIL data[], int (*cmp)(const void *a, const void *b))
{
    int i, j;
    EMAIL temp;
    for(i=n-1;i>=1;i--)/*For maintain the original order, I choose bubble sort...(STABLE SORT)*/
    {
        for(j=0;j<i;j++)
        {
            if(cmp(&data[j],&data[j+1])>0)
            {
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    const char at = '@';
    int count;
    int i;
    EMAIL *data=NULL;
    int term;
    char temp[TEMPLEN];
    char *cptr=NULL, *toat=NULL;
    //freopen("testout.txt","w",stdout);
    fgets(temp,TEMPLEN,stdin);
    term = atoi(temp);
    data = (EMAIL*)malloc(sizeof(EMAIL)*term);
    count = 0;
    while(term--)
    {
        fgets(temp,TEMPLEN,stdin);
        cptr = temp+strlen(temp)-1;
        if(*cptr=='\n') *cptr='\0';/*To prevent \n in.*/
        toat = strchr(temp,at);
        if(toat==NULL)
        {
            printf("%s\t\t=> Not valid\n",temp);
            continue;
        }

        /*Check if account is not valid*/
        if(!valid(temp,toat)||!valid(toat+1,temp+strlen(temp)))
        {
            printf("%s\t\t=> Not valid\n",temp);
            continue;
        }
        printf("%s\t\t=> Valid\n",temp);

        /*If there is a valid data, then write to structure. */
        mypush(temp,data+count);
        count++;
    }
    puts("===Before sorting===\n");
    for(i=0; i<count; i++)
    {
        printf("%s@%s\n",data[i].ACCOUNT,data[i].DOMAIN);
    }
    puts("===Sort by ACCOUNT===\n");

    mySORT(count,data,&cmpACCOUNT);
    for(i=0; i<count; i++)
    {
        printf("%s@%s\n",data[i].ACCOUNT,data[i].DOMAIN);
    }
    puts("===Sort by DOMAIN+ACCOUNT===\n");

    mySORT(count,data,&cmpDOMAIN);
    for(i=0; i<count; i++)
    {
        printf("%s@%s\n",data[i].ACCOUNT,data[i].DOMAIN);
    }
    free(data);
    data=NULL;
    printf("Press ENTER to exit.\n");
    fgets(temp,MAX,stdin);
    return 0;
}

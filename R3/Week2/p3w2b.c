#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50000
int main(void)
{
	int i;
	int n;
	char input[MAX];
	char temp[MAX];
	char *ptr1=NULL,*ptr2=NULL;
	while((fgets(input,MAX,stdin))!=NULL)
	{
		ptr1 = input;
		while(ptr1!=NULL && *ptr1!='\0')
		{
			n = -1;
			if(isdigit(*ptr1))
			{
				ptr2 = ptr1;
				i = 0;
				while(ptr2!=NULL && *ptr2!='\0' && isdigit(*ptr2)){temp[i++] = *(ptr2++);}
				temp[i] = '\0';
				n = atoi(temp);
				ptr1 = ptr2-1;
			}
			if(n!=-1)
			{
				ptr2 = ptr1+1;
				i = 0;
				while(ptr2!=NULL && *ptr2!='\0' && isalpha(*ptr2)){temp[i++]=*(ptr2++);}
				temp[i] = '\0';
				for(i=0; i<n; i++)printf("%s",temp);
				ptr1 = ptr2-1;
			}
			ptr1++;
		}
		printf("\n");
	}
	return 0;
}

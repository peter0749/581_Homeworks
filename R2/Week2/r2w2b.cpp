#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int main(void)
{
	char temp[MAX];
	char *ptr=NULL;
	const int letterdiff='z'+'A';
	//freopen("testout.txt","w",stdout);
	while((gets(temp))!=NULL)
	{
		ptr = temp;
		while(ptr!=NULL&&*ptr!='\0')
		{
			if(isalpha(*ptr))
			{
				*ptr = letterdiff - *ptr;
			}
			else if(isdigit(*ptr))
			{
				if(*ptr=='9')	*ptr='0';
				else
				{
					*ptr = *ptr+1;
				}
			}
			ptr++;
		}
		puts(temp);
	}
	return 0;
}

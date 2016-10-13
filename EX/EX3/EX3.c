#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20
#define BUFFERMAX 10000
#define MESSAGE( x ) printf("Stack full, successfully allocate double size %d.\n", (x) );
#define FLEN 6
#define MLEN 4

typedef enum{female,male}sex;

typedef struct record
{
	char name[MAX];
	int age;
	sex gender;
	//sex 0 for female, 1 for male;
}STUDENT;

typedef struct
{
	unsigned int get_size;
	unsigned int get_record;
	STUDENT *stu;
}Dynamic_Arr;

void init_vec( Dynamic_Arr *ptr )
{
	ptr->get_record = 0;
	ptr->get_size = 5;/*The size of vector at the beginning.*/
	ptr->stu = (STUDENT*)malloc( sizeof(STUDENT)*5 );
}

void del_vec( Dynamic_Arr *ptr )
{
	ptr->get_record = 0;
	ptr->get_size = 0;
	free(ptr->stu);
	ptr->stu = NULL;
}

void resize_vec( Dynamic_Arr *ptr )
{
	int i;
	STUDENT *newptr=NULL;
	if( ptr->get_size - ptr->get_record == 0 )/* The array is full */
	{
		newptr = (STUDENT*)malloc(sizeof(STUDENT) * (ptr->get_size<<=1));/* Reallocate new memory. */
		for(i=0; i<ptr->get_record; i++)
		{
			newptr[i] = ptr->stu[i];/* Copy all. */
		}
		free(ptr->stu);/* Release old one. */
		ptr->stu = newptr;/* Assign the address to the vector. */
		MESSAGE( ptr->get_size );/*Printout the message.*/
	}
}

void push_back_vec( Dynamic_Arr *ptr, const char *name, const int age, const sex gender )
{
	char *charptr=NULL;
	resize_vec(ptr);/* If the vetor is full, expand it.  */
	/*Pushback all the contents.*/
	strcpy(ptr->stu[ ptr->get_record ].name , name );
	ptr->stu[ ptr->get_record ].age = age;
	ptr->stu[ ptr->get_record ].gender = gender;
	printf("Insert record, name=");/*Ensure the record is in the vector*/
	charptr = ptr->stu[ ptr->get_record ].name;
	while(charptr!=NULL && *charptr!='\0')
	{
		printf("%c",*charptr);
		charptr++;
	}
	printf(",age=%d ,sex=%s\n",ptr->stu[ ptr->get_record ].age, ptr->stu[ ptr->get_record ].gender?"Male":"Female");
	ptr->get_record++;/* The insertion completed */
}

int main(void)
{
	Dynamic_Arr arr;
	init_vec(&arr);
	int i=0;
	const char tok[]=",";
	char *ptr=NULL;
	char temp[BUFFERMAX];
	char name[BUFFERMAX];
	int age;
	int failed=0;
	sex gender;
	while( (fgets(temp,BUFFERMAX,stdin)) != NULL )
	{
		ptr = strtok(temp, tok);/*Seperate Name and Age.*/
		if(ptr==NULL)return(-1);/*If fail*/
		while(ptr!=NULL && *ptr!='\0' && *ptr!='\"')ptr++;/*Find ' " '*/
		ptr++;/*Begin to load "name"*/
		i=0;
		while(ptr!=NULL && *ptr!='\0' && *ptr!='\"')
		{
			name[i++]=*(ptr++);
		}
		name[i]='\0';
		ptr = strtok(NULL, tok);/*Seperate Age and Sex, step forward to Age.*/
		if(ptr==NULL)return(-2);/*If fail*/
		age = atoi(ptr);/*Assign age*/
		if(age<0)
		{
			printf("Thank you, but I'm not \"THAT\" young ;)\n");
			continue;/* To prevent enter a negative age. */
		}
		ptr = strtok(NULL, tok);/*Step into sex. */
		if(ptr==NULL)return(-3);/*If fail, return -3*/
		failed = 0;/*Check if user enter unneccessary words.*/
		while(ptr!=NULL && *ptr!='\0' && (*ptr==' ' || *ptr=='\t'))ptr++;/*Pharsing space, and \t.*/
		if( ptr!=NULL && *ptr!='\0' && ((strncmp(ptr,"female",FLEN)) == 0 ) )
		{
			ptr = ptr+FLEN;
			while(ptr!=NULL && *ptr!='\0')
			{
				if(*ptr!=' '&&*ptr!='\t'&&*ptr!='\n')
				{
					failed = 1;
					break;
				}
				ptr++;
			}
			if(!failed)
				gender = female;
		}
		else if(ptr!=NULL && *ptr!='\0' && ((strncmp(ptr,"male",MLEN)) == 0))
		{
			ptr = ptr+MLEN;
			while(ptr!=NULL && *ptr!='\0')
			{
				if(*ptr!=' '&&*ptr!='\t'&&*ptr!='\n')
				{
					failed = 1;
					break;
				}
				ptr++;
			}
			if(!failed)
				gender = male;
		}
		else
		{
			printf("Oops! Wrong input format :(\n");
			continue;
		}
		if(failed)
		{
			printf("Please don't enter unneccessary words.\n");
			continue;
		}

		push_back_vec( &arr, name, age, gender );/*Push back all the contents.*/
	}
	del_vec(&arr);/* Release the memory. */
	return 0;
}

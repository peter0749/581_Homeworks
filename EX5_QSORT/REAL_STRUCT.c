#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#define MAX 50000
#define NAMELEN 24
#define GROUP 15
#include "MYSORT_FINAL.h"

typedef struct
{
    char NAME[NAMELEN];
    int ID;
} STUDENT;

STUDENT stu[MAX];

int cmp(const void *a, const void *b)
{
    STUDENT *c = (STUDENT*)a;
    STUDENT *d = (STUDENT*)b;
    int temp = c->ID - d->ID;
    return temp? temp : strncmp(c->NAME,d->NAME,NAMELEN);
}

int main(void)
{
    char temp[MAX], name[NAMELEN], filepath[MAX];
    int id, i, j;
    FILE *FP_IN=NULL, *FP_OUT=NULL;
    while(1)
    {
        printf("Read(R) / Create(C) / Quit(Q) ?\n");
        fgets(temp,MAX,stdin);
        if(temp[0]=='Q') break;
        else if(temp[0]=='R')
        {
            printf("File Path: ");
            fgets(filepath,MAX,stdin);
            sscanf(filepath,"%s",filepath);/*Parsing*/

            if((FP_IN = fopen(filepath,"rb"))==NULL) return -2;//Check if file not available.

            fscanf(FP_IN,"%d\n",&i);/*Read header*/
            fread(stu,sizeof(STUDENT),i,FP_IN);/*Read contents.*/

            printf("ID\tName:\n");
            for(j=0; j<i; j++)
                printf("%d\t%s\n",stu[j].ID,stu[j].NAME);
            fclose(FP_IN);
            printf("Successfully read file: %s\n", filepath);
            printf("Sort? (Y/N)");
            fgets(temp,MAX,stdin);
            if(temp[0]=='Y')
            {
                my_qsort(stu,i,sizeof(STUDENT),cmp);
                printf("After Sorting:\n");
                printf("ID\tName\n");
                for(j=0; j<i; j++)
                    printf("%d\t%s\n",stu[j].ID, stu[j].NAME);
                /*Sorted*/

                printf("Output file path: ");
                fgets(filepath,MAX,stdin);
                sscanf(filepath,"%s",filepath);/*Parsing*/

                if((FP_OUT = fopen(filepath, "wb")) == NULL) return -1;//Check if file not available.

                fprintf(FP_OUT,"%d\n",i);
                fwrite(stu,sizeof(STUDENT),i,FP_OUT);
                fclose(FP_OUT);

                printf("Successfully sorted file: %s\n", filepath);
            }
        }
        else if(temp[0]=='C')
        {
            printf("File Path: ");
            fgets(filepath,MAX,stdin);
            sscanf(filepath,"%s",filepath);

            if((FP_OUT = fopen(filepath,"wb"))==NULL) return -1;//Check if file not available.

            printf("Input format: ID (space) name\nEnter ID -1 to exit and save.\n");

            i = 0;
            while(1)
            {
                fgets(temp,MAX,stdin);
                sscanf(temp,"%d%s",&id,name);

                if(id==-1)break;//if -1, break.

                stu[i].ID = id;
                strncpy(stu[i++].NAME,name,NAMELEN);
            }

            /*Write to file*/
            fprintf(FP_OUT,"%d\n",i);/*Write header.*/
            fwrite(stu,sizeof(STUDENT),i,FP_OUT);
            fclose(FP_OUT);

            if((FP_IN = fopen(filepath,"rb"))==NULL) return -2;//Check if file not available.

            fscanf(FP_IN,"%d\n",&i);/*Read header.*/
            fread(stu,sizeof(STUDENT),i,FP_IN);/*Read contents.*/
            printf("ID\tName:\n");

            for(j=0; j<i; j++)
                printf("%d\t%s\n",stu[j].ID,stu[j].NAME);

            fclose(FP_IN);
            printf("Successfully created file: %s\n", filepath);
        }
    }

    return 0;
}

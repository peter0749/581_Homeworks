#include <sys/time.h>
#include <sys/types.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <string.h>
#include <pthread.h>
#include "MYSORT_POSIX.h"
#define MAX 2000000
#define TIME 30
#define SHUFFLE_T 8
unsigned long long int counter = 0;
int arr1[MAX];
int arr2[MAX];

int cmp(const void *a, const void *b)
{
    counter++;
    return *(int*)a-*(int*)b;
}

int main(void)
{
    struct timeval start, end;
    struct timezone start_z, end_z;
    double diff1, diff2, times;
    int i, t, n, term;
    freopen("Q_SORT_ONLY_FF.out","w",stdout);
    //freopen("TEST001.in","r",stdin);
    srand(time(NULL));
    scanf("%d", &term);
    while(term--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)scanf("%d", arr1+i);
        for(i=0; i<n; i++)arr2[i]=arr1[i];

        counter = 0;
        gettimeofday(&start,&start_z);
        my_qsort(arr1,n,sizeof(int),cmp);
        gettimeofday(&end, &end_z);
        diff1 = (double)(end.tv_sec-start.tv_sec) + (double)(end.tv_usec-start.tv_usec) / 1.0e6L;
        fprintf(stderr,"My sort: \n");
        fprintf(stderr,"time: %.6lf s\n", diff1);
        fprintf(stdout,"MY\tcomparison: %lld times\n",counter);

        counter = 0;
        gettimeofday(&start,&start_z);
        qsort(arr2,n,sizeof(int),cmp);
        gettimeofday(&end, &end_z);
        diff2 = (double)(end.tv_sec-start.tv_sec) + (double)(end.tv_usec-start.tv_usec) / 1.0e6L;
        fprintf(stderr,"STD qsort: \n");
        fprintf(stderr,"time: %.6lf s\n", diff2);
        fprintf(stdout,"STD\tcomparison: %lld times\n",counter);

        fprintf(stdout,"MY/STD: %.6lf times\n", diff2/diff1);
        fprintf(stdout,"\n");
    }
    return 0;
}

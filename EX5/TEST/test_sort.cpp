#include <sys/time.h>
#include <bits/stdc++.h>
#include "MYSORT_POSIX.h"

unsigned long long int counter = 0;
int *arr1;
int *arr2;

inline int cmp(const void *a, const void *b)
{
    counter++;//For Benchmarking
    return *(int*)a-*(int*)b;
}

inline bool sort_cmp(const int &a, const int &b)
{
    counter++;
    return a < b;
}

int main(void)
{
    struct timeval start, end;
    struct timezone start_z, end_z;
    double diff1, diff2, times;
    int i, j, t, n, sw;
    unsigned long long int sum;
    //freopen("UNIFORM.out","a",stdout);
    srand(time(NULL));
    printf("Test Case:\n1. Uniform\t2. Repeated\t3. Reversed\t4. Sorted\n");
    scanf("%d", &sw);
    printf("Number to sort: ");
    scanf("%d", &n);

    /*Allocate memory*/
    arr1 = new int[n];
    if(arr1==NULL)return -1;
    arr2 = new int[n];
    if(arr2==NULL)return -2;

    printf("Cycle: ");
    scanf("%d", &t);
    for(j=1; j<=t; j++)
    {
        printf("Test Case %d:\n", j);
        /*Generate Random Data*/
        if(sw==1)
            for(i=0; i<n; i++)arr1[i] = arr2[i] = rand();
        else if(sw==2)
            for(i=0; i<n; i++)arr1[i] = arr2[i] = rand()%1;
        else if(sw==3)
            for(i=0; i<n; i++)arr1[i] = arr2[i] = -i;
        else if(sw==4)
            for(i=0; i<n; i++)arr1[i] = arr2[i] = i;
        else
            for(i=0; i<n; i++)arr1[i] = arr2[i] = (rand()<<17 | rand()<<2 | rand()&3);
        /*STL sort*/
        counter = 0;//Used to calculate number of comparison;
        gettimeofday(&start, &start_z);
        std::sort(arr1,arr1+n,sort_cmp);
        gettimeofday(&end, &end_z);
        diff1 = (double)(end.tv_sec-start.tv_sec) + (double)(end.tv_usec-start.tv_usec)/1.0e6L;
        printf("STL sort:\nTime: %lf\nComparison: %lld\n",diff1,counter);
        printf("===\n\n");
        /*End of STL sort*/

        /*My qsort*/
        counter = 0;
        gettimeofday(&start, &start_z);
        my_qsort(arr2,n,sizeof(int),cmp);
        gettimeofday(&end, &end_z);
        diff2 = (double)(end.tv_sec-start.tv_sec) + (double)(end.tv_usec-start.tv_usec)/1.0e6L;
        printf("My qsort:\nTime: %lf\nComparison: %lld\n",diff2,counter);
        printf("===\n\n");
        /*End of my qsort*/

        /*Calculate the number of wrong answers.*/
        sum = 0;
        for(i=0; i<n; i++)
        {
            if(arr1[i]!=arr2[i])
            {
                sum++;
                printf("Wrong at index %d : %d != %d (STL:MY)\n", arr1[i], arr2[i]);
            }
        }
        sum = (n-sum)*100;
        printf("ACC: %lf\nSpeed (MY/STL): %lf\n", (double)sum/(double)n, diff1/diff2);/*Compute the accuracy.*/
        printf("\n");
    }
    delete [] arr1;
    delete [] arr2;
    return 0;
}

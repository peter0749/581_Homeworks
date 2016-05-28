#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 10001
#define ERR 1.0e-7L
#define CHKERR 1.0e-5L
#define f_abs( x )  ( ((x) < 0) ?  (-(x)):(x)  )

double mtx[MAX][MAX];
double cp[MAX][MAX];//For checking

double row_op(const int n, double A[][MAX], double x[])
{
    int i, j, k;
    double det=1.0L, t;
    double *buffer = NULL;//For copy
    for(i=0; i<n; i++)
    {
        if( f_abs(A[i][i]) < ERR  ) //Leading 1 is zero
        {
            j=i+1;
            while( j<n && f_abs(A[j][j]) < ERR )j++;// Find the row containing leading one;
            if(j==n) return 0; //no leading 1 at i-th col, det==0;

            buffer = (double*)malloc(sizeof(double) * (n+1));
            for(k=0; k<=n; k++)buffer[k] = A[i][k]; //Copy the elements for swapping
            for(k=0; k<=n; k++)  //Swap two rows;
            {
                A[i][k] = A[j][k];
                A[j][k] = buffer[k];
            }
            det = -det; //Since two rows swapped, det = -det;
            free(buffer);
            buffer = NULL;
        }//End of Swapping;
        det *=  (t = A[i][i]); //det *= leading 1s;
        for(j=0; j<=n; j++) A[i][j]/=t; //i-th row divide by leading 1;
        for(j=i+1; j<n; j++)
        {
            if( f_abs(A[j][i]) > ERR )// If the i-th col != 0
            {
                t = A[j][i];
                for(k=0; k<=n; k++)
                {
                    A[j][k] = A[j][k] - (t*A[i][k]); //Row reduction
                }
            }
        }
    }
    for(i=n-1; i>=0; i--)//Substitution
    {
        x[i] = A[i][n];
        for(j=i+1; j<n; j++)
        {
            x[i] -= (A[i][j]*x[j]);
        }
    }
    return det;
}

int main(void)
{
    freopen("test_out.out","w",stdout);
    srand(time(NULL));
    int n, i, j;
    int counter=0;
    double det, temp;
    double x[MAX];
    while(scanf("%d",&n)!=EOF && n)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cp[i][j] = mtx[i][j] = (double)((rand()<<17|rand()<<2|rand()&3)%n);//Copy for checking
            }
        }
        for(i=0; i<n; i++)
        {
            cp[i][n] = mtx[i][n] = (double)((rand()<<17|rand()<<2|rand()&3)%n);//Copy for checking
        }

        det = row_op(n, mtx, x);

        fprintf(stdout,"Case %d: n=%d\n", counter++, n);
        fprintf(stdout,"\ndeterminant");
        if(f_abs(det) > ERR)
        {
            fprintf(stdout,"=%.6lf\n",det);
            for(i=0; i<n; i++)
                if( f_abs(x[i]) < ERR )
                    fprintf(stdout,"x[%d] =\t0.0000\n",i);
                else
                    fprintf(stdout,"x[%d] =\t%.4lf\n", i, x[i]);

            /*Checking*/
            for(i=0; i<n; i++)//Check the answer;
            {
                temp = 0.0L;
                for(j=0; j<n; j++)
                    temp += (cp[i][j]*x[j]);
                if( f_abs(temp-cp[i][n]) > CHKERR )break;
            }
            if(i!=n) fprintf(stderr,"Not precise!\n");
            /*End of checking*/
        }
        else
            fprintf(stdout," is zero\n");
        fprintf(stdout,"===============\n");
    }
    return 0;
}

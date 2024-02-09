#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#define N 100 //#rows in matrix A
#define P 100 //#column in matrix A
#define M 100 //#column in matrix B
// create a parallel region explicitly scoping all variables
int main(int argc, char *argv[])
{
  int tid, nthreads, i, j, k;
  double a[N][P], b[P][M], c[N][M];

 #pragma omp parallel shared(a,b,c,nthreads) private(tid,i,j,k)
{
  tid=omp_get_thread_num();
//Initializing matrix
 #pragma omp for
  for(i=0; i<N; i++)
   for(j=0; j<P; j++)
      a[i][j]=i+j;

 #pragma omp for
  for(i=0; i<P; i++)
   for(j=0; j<M; j++)
     b[i][j]=i*j;

 #pragma omp for
   for(i=0; i<N; i++)
    for(j=0; j<M; j++)
        c[i][j]=0;

printf("Thread %d Starting matix multiply...\n",tid);
 #pragma omp for
   for(i=0; i<N; i++)
  {
  printf("Thread=%d row=%d\n",tid,i);
 printf("\n");
   for(j=0; j<M; j++)
   {
     for(k=0; k<P; k++)
       c[i][j] += a[i][k] * b[k][j];
   }
  }
// return(0);
}
}

nclude<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
 int arr[N];
int i;
  omp_set_num_threads(3);
  printf("With no chuncksize passed:\n");
  #pragma omp parallel for schedule(dynamic)
  for(int arr[]=0; arr[]<N-1; arr[]++)
  {
    printf("Threads %d processess iteration %d.\n",omp_get_thread_num(),i*i);
  }
   printf("With chuncksize 2 \n");

#pragma omp parallel for schedule(dynamic,3)
for(int arr[]=0; arr[]<10; arr[]++)
  {
    printf("Threads %d processess iteration %d.\n",omp_get_thread_num(),i*i);
  }
return 0;
}


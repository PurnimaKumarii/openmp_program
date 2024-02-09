#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
  omp_set_num_threads(4);
  printf("With no chuncksize passed:\n");
  #pragma omp parallel for schedule(static)
  for(int i=0; i<10; i++)
  {
    printf("Threads %d processess iteration %d.\n",omp_get_thread_num(),i);
  }
   printf("With chuncksize 2 \n");
   
#pragma omp parallel for schedule(static,3)
for(int i=0; i<10; i++)
  {
    printf("Threads %d processess iteration %d.\n",omp_get_thread_num(),i);
  }
return 0;
}     

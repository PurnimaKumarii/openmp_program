#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
  omp_set_num_threads(4);
   #pragma omp parallel for schedule(runtime)
   for(int i=0; i<10; i++)
   {
      printf("Threads %d processe iteration %d.\n", omp_get_thread_num(),i);
   }
 return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int a=12345;
#pragma omp threadprivate(a)

int main()
{
   //Turn off dynamic threads as required by threadprivate
    omp_set_dynamic(0);
    #pragma omp  parallel copyin(a)
    {
           #pragma omp master
            {
                printf("[First parallel region] Master thread changes the value of a to 67890.\n" );
                 a=67890;
            }
           #pragma omp barrier
           printf("[first parallel region] Thread %d: a=%d.\n",omp_get_thread_num(),a);
     }
  #pragma omp parallel copyin(a)
  {
   printf("[second parallel region] Thread %d: a=%d.\n",omp_get_thread_num(),a);
  }
 return 0;
}

#include<stdio.h>
#include<omp.h>
#define N 5
 int main()
  {
    int a=20;
    int b=10;
    int c=40;
    omp_set_num_threads(N);
#pragma omp parallel for firstprivate(c)
for(int i=0; i<N; i++)
 {
   printf("Thread %d value is %d\n",omp_get_thread_num(),c);
  c=a+b; //private
  printf("Thread %d value is %d\n",omp_get_thread_num(),c);
  }
printf("%d",c);
return 0;
}



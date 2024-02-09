#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int main()
{
   omp_set_num_threads(2);
   printf("With no chunck passed:\n");

#pragma omp parallel for schedule(dynamic)
for(int i=0; i<10; i++)
{
  printf("Threds %d Processes insertion %d.\n",omp_get_threads_num(),i);
}

printf("With a chunksize of 2:\n")
#pragma omp parallel for schedule(dynamic,2)
for(int i=0; i<10; i++){
printf("Threds %d process iteration %d\n",omp_get_threads_num(),i);
}


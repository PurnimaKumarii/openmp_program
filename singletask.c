#include<stdio.h>
#include<omp.h>
int main()
{
   #pragma omp parallel
   {
     #pragma omp single
    {
      #pragma omp task

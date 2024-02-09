#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main(int argc,char* argv[])
{
  //use 4 threads when creating openMp parallel region
  omp_set_num_threads(4) ;
  int total=0;   
   #pragma omp parallel default(none) shared(total)
       {

           //Create a parallel region
             for(int i=0; i<10;i++)
             {
              // Atomically add one to the total  
                              #pragma omp reduction
                  total++;
                  }
     
              }
  
printf("Total=%d.\n",total);
return 0;
}


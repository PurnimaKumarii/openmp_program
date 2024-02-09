#include<stdio.h>
#include<omp.h>
int main()
{
   int i;
   int sum=0;
#pragma omp parallel 
 {
 #pragma omp sections reduction(+:sum)

  {
  #pragma omp section 

   {
        for(i=0; i<=10; i++)
         	{
              sum=sum+i;
	      
              }
              #pragma omp section 

              {
                         for( i=0; i<=10; i++)
                          {
  
                             sum=sum+i;
                        

                          } 

               }

    }  
  }
 }
 printf("Sum=%d",sum);

   return 0;
  

}

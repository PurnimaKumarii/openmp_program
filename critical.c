#include<stdio.h>
#include<omp.h>
int main()
{
 omp_set_num_threads(4);
  int total = 0;
//create parallel region
 #pragma omp parallel default(none) shared(total)
{
int i;
   //calculate my factorial
    int my_value=1; 
      for(i=2; i<= omp_get_num_threads(); i++)
        {
          my_value *= i;
        }
     //Add my value to total
     #pragma omp critical
       {
         printf("[Thread %d] Total before I add my value(%d): %d.\n",omp_get_thread_num(),my_value , total);
           total += my_value;
        printf("[Thread %d] total after I added my value: %d.\n",omp_get_thread_num(),total);
       
       }
}
return 0;
}

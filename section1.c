#include<stdio.h>
#include<omp.h>
int main()
{
    int i=0;
 
        omp_set_num_threads(2);

        #pragma omp parallel 
        {
         #pragma omp sections private(i)
                {

                        #pragma omp section  

                       {
                                printf("section 1 \n",omp_get_thread_num(),i);
                        }
                        #pragma omp section 
                        
                        {
                             
                                 printf("section 2 \n",omp_get_thread_num(),i);

                        }
                        #pragma omp section  
                        
                        {
                             
                                 printf("section 3 \n",omp_get_thread_num(),i);

                        }
			#pragma omp section 

                        {
                             
                                 printf("section 4 \n",omp_get_thread_num(),i);

                        }
			#pragma omp section 
                        {
                             
                                 printf("section 5 \n",omp_get_thread_num(),i);

                        }


                        }
        }
        return 0;
}



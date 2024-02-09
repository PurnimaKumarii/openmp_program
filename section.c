#include<stdio.h>
#include<omp.h>
#define N 7
int main()
{
	int i=0;
	int a[N], b[N],c[N],d[N];
        omp_set_num_threads(2);
        

	/* some initialization*/

	for(i=0; i<N; i++)
	{
		a[i]=i*2;
		b[i]=i+2;
	}

	#pragma omp parallel shared(a,b,c,d) private(i)
        {
         #pragma omp sections private(i)
        	{
                  
			#pragma omp section  
			
			for(i=0;i<N; i++)
			{
 				c[i]=a[i]+b[i];
				printf("section 1 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],c[i]);
			}
			#pragma omp section 
			for(i=0;i<N;i++)
			{
				d[i]=a[i]*b[i];
				printf("section 2 # working thread : %d | %d * %d = %d\n",omp_get_thread_num(),a[i],b[i],d[i]);
			}
			#pragma omp section  

                        for(i=0;i<N; i++)
                        {
                                c[i]=a[i]+b[i];
                                printf("section 3 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],c[i]);
                        }
			#pragma omp section  

                        for(i=0;i<N; i++)
                        {
                                c[i]=a[i]+b[i];
                                printf("section 4 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],c[i]);
                        }

			#pragma omp section  

                        for(i=0;i<N; i++)
                        {
                                c[i]=a[i]+b[i];
                                printf("section 5 # working thread : %d | %d + %d = %d\n",omp_get_thread_num(),a[i],b[i],c[i]);
                        }


			}
	}
printf("%d",i);
	return 0;
}



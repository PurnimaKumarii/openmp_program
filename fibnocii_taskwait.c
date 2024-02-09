#include<stdio.h>
#include<omp.h>
 int fabnocii(int n)
 {
   
   int a=0,b=1;
   int c;
   while(n >2)
   {
    c=a+b;
   printf("%d",c);
   a=b;
   b=c;
   n--;
   }
   printf("\n");
}
 return result;
}
   int main()
  {
   int n;
  
 #pragma omp paralel
 {
   #pragma omp single
    {
      #pragma omp task shared(c)
      c = fabnocii(n);
      #pragma omp taskwait
       printf("The fabnocii series of %d is %d\n"n,c);
  }
 }
 return 0;


}


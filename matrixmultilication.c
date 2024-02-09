#include<stdio.h>
#define N 100
int main()
{
    int a[3][3],b[3][3],c[3][3];
    int result[3][3];
    int sum=0;
int i,j,k;
   printf("Enter the first matrix:\n");
      for(i=0;  i<3; i++)
         {
            for(j=0; j<3; j++)
          {
           scanf("%d",&a[i][j]);
          }
       }
   printf("Enter the second matrix:\n");
     for(i=0; i<3; i++)
       {
         for(j=0; j<3; j++)
          {
          scanf("%d",&b[i][j]);
          }
       }
    for(i=0; i<3; i++)
      {
      for(j=0; j<3; j++)
        {
          for(k=0; k<3; k++)
          {
             sum+=a[i][k]* b[k][j];
          }
          result[i][j]=sum;
      }
      sum=0;
    
}
 printf("The matrix multiplication is:\n");

   for(i=0; i<3; i++)
   {
   for(j=0; j<3; j++)
   {
    printf("%d ",result[i][j]);
   }
 printf("\n");
  }
  return 0;
}


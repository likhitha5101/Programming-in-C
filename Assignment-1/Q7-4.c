#include<stdio.h>
void main()
{
int n,sum=0;
printf("Enter value of n: ");
scanf("%d",&n);
if(n>0 && n<100)
 {
   for(int i=1;i<=n;++i)
     sum+=i;
   printf("Sum of n numbers= %d \n",sum);
 }

}

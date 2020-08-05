#include<stdio.h>
void main()
{
int n,sum=0;
printf("Enter the n: ");
scanf("%d",&n);
for(int i=1;i<=n;++i)
  sum+=i;
printf("Sum of n numbers= %d \n",sum);
}

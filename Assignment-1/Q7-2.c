#include<stdio.h>
void main()
{
int n,sum=0;
do
{ 
  printf("Enter the number: ");
  scanf("%d",&n);
  if(n!=-999)
   sum+=n;
}while(n!=-999);

printf("Sum of given numbers= %d \n",sum);
}

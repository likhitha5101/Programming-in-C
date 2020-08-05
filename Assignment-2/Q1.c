#include<stdio.h>
int checkoddeven(int n)
{
if (n%2==0)
  return 1;
else
  return 0;
}
void main()
{
int n,osum=0,esum=0,num;
printf("\nEnter number of integers: ");
scanf("%d",&n);
for(int i=0;i<n;++i)
{
  printf("\nEnter a number: ");
  scanf("%d",&num);
  if(checkoddeven(num)==1)
    esum+=num;
  else
    osum+=num;
}
printf("\nSum of odd numbers: %d",osum);
printf("\nSum of even numbers: %d\n",esum);
}

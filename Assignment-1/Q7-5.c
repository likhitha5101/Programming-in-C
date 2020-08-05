#include<stdio.h>
void main()
{
int n,sum=0;

while(1)
{
 printf("Enter value of n: "); 
 scanf(" %d",&n);
 if(n<=0 && n>=100)
   break;
 sum+=n;
}
printf("\nThe sum is: %d",sum);
if(n<=0&&n>=100)
 printf("\nN should range between 0 and 100");
}

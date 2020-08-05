#include<stdio.h>
unsigned long fact(int n)
{
unsigned long fact=1;
for(int i=1;i<=n;++i)
 fact*=i;

return fact;


}
void main()
{
int n;
printf("\nEnter a number: ");
scanf("%d",&n);
if(n>=1 && n<=100)
{
unsigned long temp=fact(n);
printf("\nFactorial of %d is : %lu\n",n,temp);
while(temp!=0)
{
 if(temp%10!=0)
   {temp=temp%10;
    break;
   }
 temp/=10;
}
printf("\nRightmost non-zero digit is: %lu\n",temp);
}
}         

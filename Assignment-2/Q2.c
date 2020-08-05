#include<stdio.h>
void ReverseNum(int *num)
{
int rev=0;
while(*num!=0)
{
 rev=rev*10+ *num%10;
 *num/=10;
}
*num=rev;
}
void main()
{
int n;
printf("\nEnter a number: ");
scanf("%d",&n);
ReverseNum(&n);
printf("\nReverse of the number is:%d\n",n);
}

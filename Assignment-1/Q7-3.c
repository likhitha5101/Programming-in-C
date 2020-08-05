#include<stdio.h>
void main()
{
int n,sum=0;
char ch='y';
do
{ 
  printf("Enter the number: ");
  scanf("%d",&n);
  sum+=n;
  printf("Do you want to continue(y/n)? ");
  scanf("%s",&ch);
}while(ch!='n');

printf("Sum of given numbers= %d \n",sum);
}
#include<stdio.h>
float prod(float n)
{
printf("Enter a number: ");
scanf("%f",&n);
if(n==0)
 return 1;
else
 return n*prod(n);
}
void main()
{
float n;
printf("\nMultiplication will be stopped when you enter 0\n");
printf("Enter a number: ");
scanf("%f",&n);
float product=prod(n)*n;
printf("Result; %.3f\n",product);
}

#include<stdio.h>
float power(float X, int N)
{
if(N==0)
 return 1;
else
 return X*power(X,N-1);
}
void main()
{
float X,pow;
int N;
printf("\nEnter the value of base: ");
scanf("%f",&X);
printf("'\nEnter the value of power: ");
scanf("%d",&N);
if (N<0)
{pow=power(X,-N);
pow=1/pow;
}
else
pow=power(X,N);
printf("\nBase %f to the power %d is %f\n",X,N,pow);
}

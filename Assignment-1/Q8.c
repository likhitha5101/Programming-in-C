#include<stdio.h>
void main()
{
float a,b,d,c;
int op;
printf("Enter the value of a: ");
scanf("%f",&a);
printf("Enter the value of b: ");
scanf("%f",&b);
printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Square");
printf("\nEnter your choice(1-5): ");
scanf("%d",&op);
switch(op)
{
case 1: c=a+b;
	break;
case 2: c=a-b;
	break;
case 3: c=a*b;
	break;
case 4: c=a/b;
	break;
case 5: c=a*a;
	d=b*b;
	break;
}
if(op!=5)
printf("RESULT= %.3f \n",c);
else
printf("RESULT=%.3f,%.3f \n",c,d);
}

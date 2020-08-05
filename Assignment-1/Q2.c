#include<stdio.h>
void main()
{
float c,f,kel;
printf("\nEnter temperature in celsius: ");
scanf("%f",&c);
f=c*9/5+32;
kel=f+273.15;
printf("\nTemperature in fahrenheit is %0.2f \n",f);
printf("\nTemperature in kelvin is %0.2f \n",kel);
}
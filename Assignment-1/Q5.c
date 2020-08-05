#include<stdio.h>
int main()
{
float bp,da,hra,pf,cca,ins,gross,ded, net;
char optionHRA,optionCCA;

printf("Enter Basic Pay : ");
scanf("%f",&bp);

printf("\nEnter the type of HRA('M'/'C'/'T'): ");
scanf("%s",&optionHRA);

printf("\nEnter the type of CCA('W'/'E'/'M'): ");
scanf("%s",&optionCCA);

switch(optionHRA)
{
case 'M': hra=0.1*bp;
	  break;
case 'c':hra=0.08*bp;
	  break;
case 'T': hra=0.05*bp;
	  break;
}

switch(optionCCA)
{
case 'W': cca=1000;
	  break;
case 'E':cca=2000;
	  break;
case 'M': cca=5000;
	  break;
}

da=0.88*bp;
ins=2000;
pf=0.12*bp;
gross=da+hra+cca;
ded=ins+pf;
net=gross-ded;
printf("Gross salary = %0.2f",gross);
printf("\nDeductions = %0.2f",ded);
printf("\nNet salary = %0.2f \n",net);
return 0;
}


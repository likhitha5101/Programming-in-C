#include<stdio.h>
void main()
{
float bp,da,hra,pf,cca,ins,gross,ded, net;
printf("Enter Basic Pay : ");
scanf("%f",&bp);
da=0.88*bp;
hra=0.08*bp;
cca=1000;
ins=2000;
pf=0.12*bp;
gross=da+hra+cca;
ded=ins+pf;
net=gross-ded;
printf("Gross salary = %0.2f",gross);
printf("\nDeductions = %0.2f",ded);
printf("\nNet salary = %0.2f \n",net);
}

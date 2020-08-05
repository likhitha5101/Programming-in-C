#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void table(double (*p)(double i,int m,double n), double a,int m,double i,int t);
double percmpd(double i,int m,double n);
double dailycmpd(double i,int m,double n);
double contcmpd(double i,int m,double n);

double *val[6];

void main()
{
int m[6]={1,2,4,12,360,0},t,k;
double i,a;
char choice;
printf("\nMonthly Amount : ");
scanf("%lf",&a);
printf("Interest : ");
scanf("%lf",&i);
i*=0.01;
printf("\nFrequency of compounding :\n");
for(t=0;t<6;t++)
	val[t]=(double *) malloc (50 * sizeof(double));
for(t=0;t<6;t++)
	{
	if(t<4) table(percmpd,a,m[t],i,t);
	else if(t==4) table(dailycmpd,a,m[t],i,t);
	else table(contcmpd,a,m[t],i,t);
	
	}
printf("Terms	    Annualy	Semiannualy	   Quaterly	Monthly    Daily	Continuous\n");
printf("(years)\n");
for(t=0;t<50;t++)
	{
	printf("%d   \t",t+1);
	for(k=0;k<6;k++)
		{printf("%.1lf",*(val[k]+t));
		 printf("\t");}
	printf("\n");
	}

}

void table(double (*p)(double i,int m,double n), double a,int m,double i,int t)
{
int j;
double f;
for(j=1;j<=50;j++)
	{
	f=a*(*p)(i,m,j);
	*(val[t]+j-1)=f;
	}

}


double percmpd(double i,int m,double n)
{
    double x;
    x=12*(pow((1+i/m),m*n)-1)/i;
    return x;
}
double dailycmpd(double i,int m,double n)
{
    double x;
    x=(pow((1+i/m),m*n)-1)/(pow((1+i/m),m/12)-1);
    return x;
}
double contcmpd(double i,int m,double n)
{
    double x;
    x=(exp(i*n)-1)/(exp(i/12)-1);
    return x;
}

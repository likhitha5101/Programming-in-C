#include<stdio.h>
#include<math.h>

void table(double (*fn)(double,int,float),double a,int m, float n)
{
    double i,f;
    //printf();
    for(int c=5;c<=10;++c)
    {
        i=0.01*c;
        f=a*(*fn)(i,m,n);
        printf("  %.2f",f);
    }

}

double ci1(double i,int m,float n)
{
    double x;
    x=12*(pow((1+i/m),m*n)-1)/i;
    return x;
}
double ci2(double i,int m,float n)
{
    double x;
    x=(pow((1+i/m),m*n)-1)/(pow((1+i/m),m/12)-1);
    return x;
}
double ci3(double i,int m,float n)
{
    double x;
    x=(exp(i*n)-1)/(exp(i/12)-1);
    return x;
}
void main()
{
    float n;
    int m=1;
    double a;
    printf("\n\nEnter Principal amount:  ");
    scanf("%lf",&a);
    printf("\n\nEnter number of years: ");
    scanf("%f",&n);
    printf("\n\nPrincipal amount:  %.2lf",a);
    printf("\n\nNumber of years: %.2f",n);
    printf("\n\nInterest rate:   ");
    printf("5%%\t    6%%\t\t7%%\t   8%%\t\t9%%\t    10%% ");
    printf("\n\nFrequency of\ncompounding\n\nAnnually     ");
    table(ci1,a,m,n);
    m=2;
    printf("\n\nSemiannual   ");
    table(ci1,a,m,n);
    m=4;
    printf("\n\nQuarterly    ");
    table(ci1,a,m,n);
    m=12;
    printf("\n\nMonthly      ");
    table(ci1,a,m,n);
    m=360;
    printf("\n\nDaily        ");
    table(ci2,a,m,n);
    m=0;
    printf("\n\nContinuously ");
    table(ci3,a,m,n);
}

#include<stdio.h>
int ord(int num)
{
int r,temp=num;
do
{
 r=num%10;
 num/=10;
 if(r<=num%10)
  return 0;
}while(num!=0);
return temp;
}

void main()
{
int a[200],c=0,x;
for(int i=100;i<=999;++i)
{
 x=ord(i);
 if(x!=0)
  {a[c]=x;
   c++;
  }
}
for(int j=0;j<c;++j)
 printf("%d\n",a[j]);
printf("The total number of well ordered numbers are: %d",c);
}

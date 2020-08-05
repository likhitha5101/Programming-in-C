#include<stdio.h>
void main()
{
int num,c=0;
printf("Enter n: ");
scanf("%d",&num);
while(num!=0)
{
 if(num%10==5)
  c+=1;
 else
  c=0;
 if(c==3)
  break;
 num/=10;
}
if(c==3)
 printf("YES\n");
else
 printf("NO\n");
}
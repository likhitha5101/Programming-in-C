#include<stdio.h>
void main()
{
int n,i=0,num,sum=0;
printf("Enter value of n: "); 
scanf("%d",&n);
while(i<n)
{
printf("Enter value of num: "); 
scanf("%d",&num);
if(num>0 && num<100)
 {
 sum+=num;
 i+=1;
 }
else printf("\nEnter a number ranging between 0 and 100");
}
}

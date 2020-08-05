#include<stdio.h>
void main()
{
int num,flag;
printf("Enter a number: ");
scanf("%d",&num);
if(num%2==0)
 flag=0;
else
 flag=1;
printf("Flag =%d \n",flag);
}
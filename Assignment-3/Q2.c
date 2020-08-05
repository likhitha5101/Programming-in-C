#include<stdio.h>
void main()
{
int a[10]={0},n,k,i,j,max;

printf("enter the no of digits:");
scanf("%d",&n);
for(i=0;i<n;i++)
	{
	printf("enter the digits:");
	scanf("%d",&k);
	a[k]+=1;
	}
max=a[0];
for(i=1;i<10;i++)
	if(a[i]>max)
		max=a[i];
printf("\n");
for(i=max;i>=1;i--)
	{
	for(j=0;j<10;j++)
		if(a[j]>=i)
			printf("*  ");
		else
			printf("   ");
	printf("\n");
	}
for(i=0;i<=9;i++)
	printf("%d  ",i);
printf("\n");
}		

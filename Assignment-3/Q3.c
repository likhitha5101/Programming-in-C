#include<stdio.h>
void pushzeroestoend(int arr[],int n);
void main()
{
int n,i,a[10]={0};
printf("Enter the no of elements:");
scanf("%d",&n);
for(i=0;i<n;i++)
	{
	printf("Enter the element:");	
	scanf("%d",&a[i]);
	}
pushzeroestoend(a,n);
printf("\n The altered array is :");
for(i=0;i<n;i++)
	{
	printf("%d",a[i]);
	if(i!=n-1)
		printf(",");
	}
printf("\n");
}
void pushzeroestoend(int a[],int n)
{
int i,j;
for(i=0;i<n;i++)
	{
	if(a[i]==0)
	{       i=i-1;
		for(j=i+1;j<n-1;j++)
			a[j]=a[j+1];
		
		a[n-1]=0;
  		n--;
	}
	}
}

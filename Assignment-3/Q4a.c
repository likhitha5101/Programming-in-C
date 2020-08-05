#include<stdio.h>
float average(float mark[10][10],float weight[10],int n, int c)
{
float sum;
for(int i=0;i<n;i++)
	{
	sum=0;
	for(int j=0;j<c;j++)
		sum+=(weight[j]*(mark[i][j]/100));
		
	mark[i][c]=sum;
	}
sum=0;
for(int i=0;i<n;i++)
	sum+=mark[i][c];
	
return sum/n;
}




void main()
{
char name[10][80];
float mark[10][10],weight[10];
int c,n,i,j;
printf("\nEnter the no of students:");
scanf("%d",&n);
printf("\nEnter the no of courses:");
scanf("%d",&c);
for(j=0;j<c;j++)
{
printf("Enter mark%d weightage:",j+1);
scanf("%f",&weight[j]);
}
for(i=0;i<n;i++)
	{
	printf("enter your name:");
	scanf("%s",name[i]);
	for(j=0;j<c;j++)
		{
		printf("Enter mark%d:",j+1);
		scanf("%f",&mark[i][j]);
		}
	}

printf("\n\nthe class average is %.2f \n",average(mark,weight,n,c));
printf("\n\nmarklist::\n\n");

for(i=0;i<n;i++)
	{
	printf("\n name:");
	puts(name[i]);
	for(j=0;j<c;j++)
		printf("mark%d:%.2f   ",j+1,mark[i][j]);
	printf("  average:%.2f",mark[i][c]);
	}
printf("\n");
}

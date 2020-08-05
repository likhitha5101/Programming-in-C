#include<stdio.h>
float average(float mark[10][10],int n, int c)
{
float sum,classavg;
for(int i=0;i<n;i++)
	{
	sum=0;
	for(int j=0;j<c;j++)
		sum+=mark[i][j];
		
	mark[i][c]=sum/c;
	}
sum=0;
for(int i=0;i<n;i++)
	sum+=mark[i][c];
	
return sum/n;
}


void main()
{
char name[10][80];
float mark[10][10],clsavg;                                           ;
int c,n,i,j;
printf("\nEnter the no of students:");
scanf("%d",&n);
printf("\nEnter the no of courses:");
scanf("%d",&c);
for(i=0;i<n;i++)
	{
	printf("enter your name:");
	scanf("%s",name[i]);
	for(j=0;j<c;j++)
		{
		printf("Enter mark %d:",j+1);
		scanf("%f",&mark[i][j]);
		}
	}
clsavg=average(mark,n,c);
printf("\n\nthe class average is %.2f \n",clsavg);
printf("\n\nmarklist::\n\n");

for(i=0;i<n;i++)
	{
	printf("\nNAME:");
	puts(name[i]);
	for(j=0;j<c;j++)
		printf("MARK %d:%.2f   ",j+1,mark[i][j]);
	printf("  AVG:%.2f",mark[i][c]);
	}
printf("\n");
}

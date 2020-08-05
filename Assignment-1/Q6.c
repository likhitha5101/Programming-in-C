#include<stdio.h>
void main()
{
int n,i,j;
printf("Enter the value of N: ");
scanf("%d",&n);

for(i=0;i<n;++i)
{
  for(j=0;j<=i;++j)
     printf("  ");
  for(j=0;j<n-i;j++)
    {
     if(j+1!=n-i)
      printf("* _ ");
     else
      printf("* ");
    }
     
  printf("\b\n\n");
}

for(i-=2;i>=0;--i)
{
  for(j=0;j<=i;++j)
     printf("  ");
  for(j=0;j<n-i;j++)
     {
     if(j+1!=n-i)
      printf("* _ ");
     else
      printf("* ");
    }
  printf("\b\n\n");
}
}

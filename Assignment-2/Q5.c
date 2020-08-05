#include<stdio.h>
void printing(int N)
{
if(N>0)
{
 printf("%d",N-1);
 printing(N-1);
}
}
void main()
{
int N;
printf("Enter the value of N: ");
scanf("%d",&N);
printf("The required sequence: ");
printing(N);
printf("\n");
}

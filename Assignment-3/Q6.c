#include<stdio.h>
#include<stdlib.h>
void main()
{
char ch1,ch2,op[3]={'R','P','S'};
int i=0,point[2]={0,0},r;
printf("'\n\nR-Rock  P-Paper  S-Scissors");
for(;i<10;++i)
	{
	ch1=ch2='\0';
	printf("\n***************************\n\nEnter(R/P/S): ");
	scanf(" %c",&ch1);
	r=rand()%3;
	ch2=op[r];
	printf("Your Choice: %c \nComputer's Choice: %c",ch1,ch2);

	if (ch1=='R' && ch2=='S')
		{
 		printf("\nYOU WIN");
 		point[0]+=1;
		}
	else if (ch1=='S' && ch2=='P')
		{
		printf("\nYOU WIN");
		point[0]+=1;
		}
	else if (ch1=='P' && ch2=='R')
		{
		printf("\nYOU WIN");
		point[0]+=1;
		}
	else if (ch1==ch2)
 		printf("\nDRAW");
	else
		{
		printf("\nCOMPUTER WINS");
		point[1]+=1;
		}
	}
printf("\nSCOREBOARD\n~~~~~~~~~~");
printf("\nYOU: %d",point[0]);
printf("\nCOMPUTER: %d",point[1]);

if(point[0]>point[1])
 	printf("\nYOU WON THE SERIES!!!");
else if(point[0]<point[1])
 	printf("\nCOMPUTER WON THE SERIES!!!");
else
 	printf("\nIT'S A DRAW");
}

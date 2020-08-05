#include <stdio.h>
#include <string.h>
void main()
{
	char str[10][200];
	int row=0,i,l,k=0,j=0;
	char *pointer[10];
	printf("enter multiple lines of text and enter END at the end \n");
	while(1)
	{
		scanf(" %[^\n]",str[row]);
		l=strlen(str[row]);
		pointer[row]=str[row];
		if (str[row][l-3]=='E' && str[row][l-2]=='N' && str[row][l-1]=='D')
		{
			str[row][l-4]='\0';
			break;
		}
		row++;
	}

	for(i=0;i<=row;i++)
	{
		j=0;
		while(*(pointer[i]+j)!='\0')
		{
			if (*(pointer[i]+j)==' ')
			{
				k++;
			}
			j++;

		}
		k++;
	}
	
	printf("\nnumber of tokens : %d",k);
}

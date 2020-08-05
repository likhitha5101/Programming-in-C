#include<stdio.h>
#include<string.h>
void main()
{
char str[81],sub[81],temp[81];
printf("\nEnter a string:");
scanf(" %[^\n]",str);
printf("\nenter the sub string:");
scanf(" %[^\n]",sub);
int i,k=0,count=0;
for(i=0;i<=strlen(str);i++)
	{
	if(*(str+i)!=' '&&*(str+i)!='\0')
		*(temp+k++)=*(str+i);
	else
		{
		*(temp+k)='\0';
		if(strcmp(sub,temp)==0)
			count++;
		k=0;
		}

	}
printf("The no of times \'%s\' occurs is %d \n",sub,count);
}

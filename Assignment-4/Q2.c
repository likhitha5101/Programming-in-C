#include<stdio.h>
#include<string.h>
void main()
{
char str[81],sub[81],temp[81];
printf("\nenter the string:");
scanf(" %[^\n]",str);
printf("\nenter the sub string:");
scanf(" %[^\n]",sub);
int pos=-1,j=0,i,k=0;
for(i=0;i<strlen(str);i++)
	{
	k=0;
	for(j=0;j<strlen(sub);j++)
		if(str[i+j]==sub[j])
			k++;
	if(k==strlen(sub))
		pos=i;
	}
if(pos==-1)
	printf("\nsubstring not found");
else
	printf("substring found at %d position",pos+1);
}

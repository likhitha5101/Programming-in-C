#include<stdio.h>
#include<string.h>
void main()
{
char str[81],osub[81],nsub[81],temp[81];
printf("\nenter the string:");
scanf(" %[^\n]",str);
printf("\nenter the old sub string:");
scanf(" %[^\n]",osub);
printf("\nenter the new sub string:");
scanf(" %[^\n]",nsub);
int pos=0,j=0,i,k=0;
for(i=0;i<strlen(str);i++)
	{
	k=0;
	for(j=0;j<strlen(osub);j++)
		if(str[i+j]==osub[j])
			k++;
	if(k==strlen(osub))
		{
		for(j=0;j<strlen(nsub);j++)
				temp[pos++]=nsub[j];
		i+=strlen(osub)-1;
		}
	else
		temp[pos++]=str[i];			
	}
temp[pos]=0;
strcpy(str,temp);
printf("the altered string is %s",str);
}

Output:

cseb84@jtl-13:~/assignment4$ ./replace
enter the string:hello good morning
enter the old sub string:good
enter the new sub string:happy
the altered string is hello happy morning

4. Program Name: To reverse a given string

Program:

#include<stdio.h>
#include<string.h>
void main()
{
char str[81],t;
printf("\nenter the string:");
scanf(" %[^\n]",str);
int i,j;
for(i=0,j=strlen(str)-1;i<=j;i++,j--)
	{
	t=str[i];
	str[i]=str[j];
	str[j]=t;
	}
printf("the reversed string is %s",str);
}

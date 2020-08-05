#include<stdio.h>
int strleng(char[]);
void strcatt(char[],char[]);
void strncpyy(char d[],char s[],int n);
int strchrr(char s[],char c);
void strsett(char s[],char c);
int strcmpii(char s1[],char s2[]);
int isupperr(char c);
char toupperr(char c);
void strcattn(char d[],char s[],int n);
void input(char a[])
{
scanf(" %[^\n]",a);
}
char tolowerr(char ch)
{
    if(ch>='A' && ch<='Z')
        return ch+32;
    else
        return ch;
}
void main()
{
char c[81],d[81],ch;
int n,flag;
printf("\nmenu:\n1.Concatenate \n2.Copy n character \n3.First occurance of a character \n4.Setting a string \n5.Comparing 2 strings \n6. Concatenate n characters ");
printf("\n7.String length \n8.Is Upper \n9.To Lower \n10.To upper \nenter your choice:");
scanf("%d",&n);
if(n==1)
	{
	printf("\nEnter the string:");
	scanf(" %[^\n]",c);
	printf("\nEnter another string:");
	scanf(" %[^\n]",d);
	strcatt(c,d);
	printf("\nNew string is %s%s",c);
	}
else if(n==2)
	{
	printf("\nEnter the string:");
	scanf(" %[^\n]",c);
	printf("\nEnter another string to be copied:");
	scanf(" %[^\n]",d);
	int c1;
	printf("\nEnter no of char to be copied:");
	scanf("%d",&c1);
	strncpyy(c,d,c1);
	printf("\nNew string is %s",c);
	}
else if(n==3)
	{
	printf("\nEnter the string:");
	input(c);
	printf("\nEnter character to be searched:");
	char k;
	scanf(" %c",&k);
	printf("\n%c is found at %d position",k,strchrr(c,k));
	}
else if(n==4)
	{
	printf("\nEnter the string:");
	scanf(" %[^\n]",c);
	char k;
	printf("\nEnter character to be written:");
	scanf(" %c",&k);
	strsett(c,k);
	printf("\nNew string is %s",c);
	}
else if(n==5)
	{
	printf("\nEnter the string:");
	scanf(" %[^\n]",c);
	printf("\nEnter another string:");
	scanf(" %[^\n]",d);
	int c3=strcmpii(c,d);
	printf("\nReturned value is %d",c3);
	}
else if(n==6)
	{
	printf("\nEnter the string:");
	scanf(" %[^\n]",c);
	printf("\nEnter another string to be copied:");
	scanf(" %[^\n]",d);
	int c1;
	printf("Enter no of char to be concatenated:");
	scanf("%d",&c1);
	strcattn(c,d,c1);
	printf("\nNew string is %s",c);
	}
else if(n==7)
    {
    printf("\nEnter the string:");
	scanf(" %[^\n]",c);
	printf("\nLength of the string is : %d",strleng(c));
    }
else if(n==8)
    {
    printf("\nEnter a character:");
	scanf(" %c",&ch);
	flag=isupperr(ch);
	if (flag==0)
        printf("\nThe character is a lower case character");
    else
        printf("\nThe character is an upper case character");
    }
else if(n==10)
    {
    printf("\nEnter a character:");
	scanf(" %c",&ch);
	ch=toupperr(ch);
	printf("The Upper case character equivalent is: %c",ch);
    }
else if(n==9)
    {
    printf("\nEnter a character:");
	scanf(" %c",&ch);
	ch=tolowerr(ch);
	printf("The lower case character equivalent is: %c",ch);
    }
}
int strleng(char a[])
{
int i=0;
for(;a[i]!='\0';i++);
return(i);
}
void strcatt(char s1[],char s2[])
{
int len1=strleng(s1),len2=strleng(s2),i,j;
for(i=len1,j=0;i<=len1+len2&&j<len2;i++,j++)
	s1[i]=s2[j];
s1[i]='\0';
}
void strncpyy(char d[],char s[],int n)
{
int i;
for(i=0;i<n;i++)
	d[i]=s[i];
d[i]='\0';
}
int strchrr(char s[],char ch)
{
int k=-1,i,len=strleng(s);
for(i=0;i<len;i++)
	if(s[i]==ch)
		{
		k=i;
		break;
		}
return k+1;
}
void strsett(char s[],char c)
{
int len=strleng(s),i;
for(i=0;i<len;i++)
s[i]=c;
}
int isupperr(char c)
{
if(c>='A'&&c<='Z')
	return 1;
else
	return 0;
}
int islowerr(char c)
{
if(c>=97&&c<=122)
	return 1;
else
	return 0;
}
char toupperr(char c)
{
if(islowerr(c)==1)
	return c-32;
else
	return c;
}
int strcmpii(char s1[],char s2[])
{
 int i;
for(i=0;i<strleng(s1);i++)
	{
	if(toupperr(s1[i])==toupperr(s2[i]))
		continue;
	else if(toupperr(s1[i])<toupperr(s2[i]))
		return -1;
	else if(toupperr(s1[i])>toupperr(s2[i]))
		return 1;
    }
    if(i==strleng(s1)&& i==strleng(s2))
		return 0;
}
void strcattn(char s1[],char s2[],int n)
{
int len1=strleng(s1),len2=strleng(s2),i,j;
for(i=len1,j=0;i<=len1+len2&&j<n;i++,j++)
	s1[i]=s2[j];
s1[i]='\0';
}

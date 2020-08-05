#include<stdio.h>
#include<stdlib.h>
void main(int argc,char *argv[])
{
FILE *fp1,*fp2;
char ch[3]="w",c;

fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"r");
if(fp1==NULL)
	printf("\nSource File do not exist");
else
{
	if(fp2!=NULL)
{
	printf("\nDo you want to overwrite or append to the file?(w/a): ");
	scanf("%s",ch);
	fclose(fp2);
}
	fp2=fopen(argv[2],ch);
	
	while((c=getc(fp1))!=EOF)
	{
	putc(c,fp2);
	}
	printf("\nThe contents copied successfully!!\n");
}
fclose(fp1);
fclose(fp2);

}
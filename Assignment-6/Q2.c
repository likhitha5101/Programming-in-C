#include<stdio.h>
#include<stdio.h>
#include<string.h>
struct date
{
int d,m,yr;
};

struct medicine
{
int nos;
char name[30],vendor[30];
struct date mdate,edate;
};
void buy(struct medicine obj[],int *n)
{
int num,flag=0,i=0;
char nam[30];

printf("\nBUYING A MEDICINE");
printf("\n*******************");
printf("\nEnter Medicine name: ");
scanf("%s",nam);
for(i=0;i<*n;++i)
if(strcmp(nam,obj[i].name)==0)
{
	flag=1;
	printf("\nEnter Quantity :");
	scanf("%d",&num);
	obj[i].nos+=num;
	break;
}
if(flag==0)
{
strcpy(obj[*n].name,nam);
printf("\nEnter vendor name: ");
scanf("%s",obj[*n].vendor);
printf("\nEnter Manufacture date(dd/mm/yyyy): ");
scanf("%d %d %d",&obj[*n].mdate.d,&obj[*n].mdate.m,&obj[*n].mdate.yr);
printf("\nEnter expiry date(dd/mm/yyyy): ");
scanf("%d %d %d",&obj[*n].edate.d,&obj[*n].edate.m,&obj[*n].edate.yr);
printf("\nEnter Quantity :");
scanf("%d",&num);
obj[*n].nos+=num;
++(*n);
}
printf("\nMedicine bought successfully!!!");
}

void display(struct medicine obj[],int n)
{
printf("\nName\tVendor \tManufacture date\tExpiry date\tStock ");
for(int i=0;i<n;++i)
{
printf("\n\n%s\t",obj[i].name);
printf("%s",obj[i].vendor);
printf("\t\t%d/ %d /%d\t",obj[i].mdate.d,obj[i].mdate.m,obj[i].mdate.yr);
printf("\t%d/ %d/ %d\t",obj[i].edate.d,obj[i].edate.m,obj[i].edate.yr);
printf("\t%d",obj[i].nos);

}
}

void sell(struct medicine obj[],int *n)
{
int num,flag=0,i=0;
char nam[30];
printf("\nSELLING A MEDICINE");
printf("\n*******************");
printf("\nEnter Medicine name: ");
scanf("%s",nam);
for(i=0;i<*n;++i)
if(strcmp(nam,obj[i].name)==0)
{
	flag=1;
	do{
	printf("\nEnter Quantity :");
	scanf("%d",&num);
	}while(num>obj[i].nos&&printf("\nInsufficient stock"));
	obj[i].nos-=num;
	if(obj[i].nos==0)
      {
            for(;i<*n-1;++i)
            obj[i]=obj[i+1];
            --(*n);
      }
    printf("\nMedicine sold successfully!!!");

	break;
}
if(flag==0)
    printf("\nMedicine not found");
}
void check(struct medicine obj[],int n)
{
char nam[30];
int flag=0;
printf("\nCHECK AVAILABILITY");
printf("\n*******************");
printf("\nEnter medicine name: ");
scanf("%s",nam);
for(int i=0;i<n;++i)
{
if(strcmp(nam,obj[i].name)==0)
{
flag=1;
printf("\nName\tVendor \tManufacture date\tExpiry date\tStock ");

printf("\n\n%s\t",obj[i].name);
printf("%s",obj[i].vendor);
printf("\t\t%d/ %d /%d\t",obj[i].mdate.d,obj[i].mdate.m,obj[i].mdate.yr);
printf("\t%d/ %d/ %d\t",obj[i].edate.d,obj[i].edate.m,obj[i].edate.yr);
printf("\t%d",obj[i].nos);
break;
}
}
if(flag==0)
    printf("\nMedicine not found!!!");
}

void main()
{
struct medicine obj[20];
int n=0,op;
for(int i=0;i<20;++i)
obj[i].nos=0;
do
{

printf("\n\nMENU\n******");
printf("\n1. Buy a new drug \n2. Sell a drug \n3. Check availability of a drug \n4. Display \n5.Exit");
printf("\nEnter your choice: ");
scanf("%d",&op);
switch(op)
{
case 1: buy(obj,&n);

	    break;
case 2:sell(obj,&n);
        break;
case 3:check(obj,n);
        break;
case 4: display(obj,n);
	    break;
}
}while(op!=5);
}

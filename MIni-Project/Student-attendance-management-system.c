#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct date
{
    int dd,mm,yy;
};
struct stud
{
    char name[30],dept[30],sec,sub[6][30],status[6];
    int yr,np[6],na[6],nod[6];
    long rno;
};
struct handle
{
    char dept[30],sec,sub[50];
    int yr;
};
struct teach
{
    char name[30],pass[20],user[30];
    struct handle info[10];
};
struct point
	{
	    struct stud *sp;
	    struct date dp;
	};
void encrypt(char pass[])
{
    char ch;
    int i=0;
     do
    {
        ch=getch();
        if(ch!=13)
         {
            pass[i]=ch;
            ++i;
            printf("* ");
         }
    }while(ch!=13);
    pass[i]='\0';
}
void fullview(char user[])
{
	FILE *fp;
	struct date dobj;
	struct stud sobj,temp;
	float per;
 	fp=fopen("record.dat","rb");
	fread(&dobj,sizeof(struct date),1,fp);
	fread(&temp,sizeof(struct stud),1,fp);
	while(!feof(fp))
	{
		if (temp.rno==atoi(user))
			{
			    sobj=temp;
			}
		fread(&dobj,sizeof(struct date),1,fp);
		fread(&temp,sizeof(struct stud),1,fp);
	}
	printf("\n\n\t\tName: %s",sobj.name);
	printf("\n\n\t\tYear: %d\tDept: %s\tSec: %c",sobj.yr,sobj.dept,sobj.sec);
	printf("\n\n\t\tRegister no.: %lu",sobj.rno);
	printf("\n\n\t\tSubjects \tPercentage");

	for(int i=0;i<6;++i)
	{
		per=(float)(sobj.np[i]+sobj.nod[i])/(sobj.np[i]+sobj.na[i]+sobj.nod[i]);
		printf("\n\n\t\t%s\t%.2f",sobj.sub[i], per*100);
	}
	fclose(fp);
}
void month(char user[])
{
	FILE *fp;
	struct date dobj;
	struct stud sobj,temp;
	float per;
	int np[6]={0,0,0,0,0,0},na[6]={0,0,0,0,0,0},nod[6]={0,0,0,0,0,0},mon;
	fp=fopen("record.dat","rb");
	fread(&dobj,sizeof(struct date),1,fp);
	fread(&sobj,sizeof(struct stud),1,fp);
	printf("\n\n\t\tEnter month: (1-12): ");
	scanf(" %d",&mon);
	while(!feof(fp))
	{
		if((sobj.rno==atoi(user))&&dobj.mm==mon)
		{
		temp=sobj;
		for(int i=0;i<6;++i)
			if(sobj.status[i]=='P')
				np[i]+=1;

			else if(sobj.status[i]=='A')
				na[i]+=1;
		}
		fread(&dobj,sizeof(struct date),1,fp);
		fread(&sobj,sizeof(struct stud),1,fp);
	}
	printf("\n\n\t\tName: %s",temp.name);
	printf("\n\n\t\tYear: %d\tDept: %s\tSec: %c",temp.yr,temp.dept,temp.sec);
	printf("\n\n\t\tRegister no.: %lu",temp.rno);
	printf("\n\n\t\tSubjects \tPercentage");
	for(int i=0;i<6;++i)
	{
		per=(float)(np[i])/(np[i]+na[i]);
		printf("\n\n\t\t%s\t%.2f",temp.sub[i], per*100);
	}
}
void day(char user[])
{
	FILE *fp;
	struct date dobj;
	struct stud sobj,temp;
	float per;
	int m,d,y;
	fp=fopen("record.dat","rb");
	fread(&dobj,sizeof(struct date),1,fp);
	fread(&sobj,sizeof(struct stud),1,fp);
	printf("\n\n\t\tEnter day(dd/mm/yyyy format): ");
	scanf(" %d %d %d",&d,&m,&y);

	while(!feof(fp))
	{
		if(sobj.rno==atoi(user)&&dobj.mm==m&&dobj.dd==d&&dobj.yy==y)
		{
		temp=sobj;
		}
		fread(&dobj,sizeof(struct date),1,fp);
        fread(&sobj,sizeof(struct stud),1,fp);
	}
	printf("\n\n\t\tName: %s",temp.name);
	printf("\n\n\t\tYear: %d\tDept: %s\tSec: %c",temp.yr,temp.dept,temp.sec);
	printf("\n\n\t\tRegister no.: %lu",temp.rno);
	printf("\n\n\t\tDate: %d/%d/%d",d,m,y);
	printf("\n\n\t\tSubjects \tStatus");
	for(int i=0;i<6;++i)
        printf("\n\n\t\t%s\t\t%c",temp.sub[i],temp.status[i]);
	fclose(fp);
}
void student(char user[])
{
    int op;
    do
	{
	    system("CLS");
		printf("\n\n\t\t1.View attendance\n\n\t\t2.Month wise attendance\n\n\t\t3.Particular date\n\n\t\t4.Exit");
		printf("\n\n\t\tEnter your choice: ");
		scanf(" %d",&op);
		switch(op)
		{
			case 1:fullview(user);
					break;
			case 2:month(user);
					break;
            case 3:day(user);
                    break;
		}
		getch();
	}while(op!=4);
}

struct point* display(struct handle hobj,int *n)
{
    FILE *fp;
	struct date dobj,tdate;
	struct stud temp, sobj[20];;
	static struct point p;

 	fp=fopen("record.dat","rb");
 	float per[6]={0,0,0,0,0,0};
	fread(&dobj,sizeof(struct date),1,fp);
	fread(&temp,sizeof(struct stud),1,fp);
	tdate=dobj;

	while(!feof(fp))
	{
        if(strcmp(hobj.dept,temp.dept)==0&&hobj.sec==temp.sec&&hobj.yr==temp.yr)
			{
			    if((tdate.yy*10000+tdate.mm*100+tdate.dd)<=(dobj.yy*10000+dobj.mm*100+dobj.dd))
                    tdate=dobj;

            }
		fread(&dobj,sizeof(struct date),1,fp);
		fread(&temp,sizeof(struct stud),1,fp);
	}
	fseek(fp,0,0);
	fread(&dobj,sizeof(struct date),1,fp);
    fread(&temp,sizeof(struct stud),1,fp);
    if(*n==999)
        printf("\n\n\t\tRNo\t\tName\t\t%s\t %s\t%s\t%s\t%s\t%s",temp.sub[0],temp.sub[1],temp.sub[2],temp.sub[3],temp.sub[4],temp.sub[5]);
    else
        printf("\n\n\t\tRno\t\tName");

	while(!feof(fp))
	{
        if(strcmp(hobj.dept,temp.dept)==0&&hobj.sec==temp.sec&&hobj.yr==temp.yr)
			{
			    if(tdate.yy==dobj.yy&&tdate.mm==dobj.mm&&tdate.dd==dobj.dd)
                {

                    if(*n==999)
                    {
                        for(int i=0;i<6;++i)
                        {
                            per[i]=(float)(temp.np[i]+temp.nod[i])/(temp.np[i]+temp.na[i]+temp.nod[i]);
                            per[i]*=100;

                        }
                        printf("\n\n\t\t%lu\t%s    \t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f",temp.rno,temp.name,per[0],per[1],per[2],per[3],per[4],per[5]);
                    }
                    else
                    {
                        sobj[*n]=temp;
                        printf("\n\n\t\t%lu\t%s",temp.rno,temp.name);
                        (*n)++;
                    }

                }
            }
		fread(&dobj,sizeof(struct date),1,fp);
		fread(&temp,sizeof(struct stud),1,fp);
	}
	fclose(fp);
	p.sp=sobj;
	p.dp=tdate;
	return &p;

}
void update(struct teach tobj)
{
    FILE *fp,*fp1;
    int i=0,n=0,flag=0,j;
    long int rno,pos;
    struct date dobj,dtemp,lastdate;
struct stud *sobj,temp;
	static struct point *p;
	struct handle hobj;
	printf("\n\n\t\tUPDATE ATTENDANCE");
	printf("\n\n\t\tEnter Department: ");
	scanf(" %[^\n]",hobj.dept);
	printf("\n\t\tEnter Section: ");
	scanf(" %c",&hobj.sec);
	printf("\n\t\tEnter year: ");
	scanf(" %d",&hobj.yr);
	printf("\n\t\tEnter Sub: ");
	scanf(" %[^\n]",hobj.sub);
	while(tobj.info[i].dept[0])
    {
       if(strcmp(hobj.dept,tobj.info[i].dept)==0)
           if(strcmp(hobj.sub,tobj.info[i].sub)==0)
            if(hobj.sec==tobj.info[i].sec)
                {p=display(hobj,&n);
                flag=1;
                 lastdate=p->dp;
                sobj=p->sp;}
            i++;
    }
    if(flag==0)
    {
        printf("\n\n\t\tUpdate access denied!!!");
        getch();
    }
    if(flag==1)
    {
    printf("\n\n\t\tEnter date(dd/mm/yyyy): ");
    scanf("%d %d %d",&dobj.dd,&dobj.mm,&dobj.yy);
    printf("\n\n\t\tEnter Absentees Register No.(full no.)(Enter 0 to stop): ");
    if(lastdate.yy*10000+lastdate.mm*100+lastdate.dd!=dobj.yy*10000+dobj.mm*100+dobj.dd)
    for(i=0;i<n;++i)
        {
            for(j=0;j<6;++j)
                sobj[i].status[j]='-';
            sobj[i].status[j]='\0';
        }
 int x;
   do
    {
        scanf(" %lu",&rno);
        for(i=0;i<n&&(rno!=0);++i)
        {
            for(j=0;j<6;++j)
                if(strcmp(hobj.sub,sobj[i].sub[j])==0)
                    if(sobj[i].rno==rno)
                    {
                        x=j;
                        sobj[i].status[j]='A';
                        sobj[i].na[j]+=1;
                    }
        }

    }while(rno!=0);

    for(i=0;i<n;++i)
    {
         if(sobj[i].status[x]!='A')
        {
            sobj[i].status[x]='P';
            sobj[i].np[x]+=1;
        }
    }
    FILE *fp1;
    fp=fopen("record.dat","a+b");
    fp1=fopen("newrecord.dat","wb");
    fseek(fp,0,0);
    fread(&dtemp,sizeof(struct date),1,fp);
    pos=ftell(fp);
    fread(&temp,sizeof(struct stud),1,fp);
    while(!feof(fp))
    {
       flag=0;
        if(dtemp.dd==dobj.dd&&dtemp.mm==dobj.mm&&dtemp.yy==dobj.yy)
       {
        i=0;
         while(i<n)
        {
            if(temp.rno==sobj[i].rno)
            {
                x=i;
                flag=1;
                break;
            }
            i++;
        }

        if(flag==1)
        {
            fwrite(&dtemp,sizeof(struct date),1,fp1);
            fwrite(&sobj[x],sizeof(struct stud),1,fp1);
        }
       }
        else
        {
            fwrite(&dtemp,sizeof(struct date),1,fp1);
            fwrite(&temp,sizeof(struct stud),1,fp1);
        }


    fread(&dtemp,sizeof(struct date),1,fp);
    fread(&temp,sizeof(struct stud),1,fp);
    }
    if(lastdate.yy*10000+lastdate.mm*100+lastdate.dd!=dobj.yy*10000+dobj.mm*100+dobj.dd)
        {
            fseek(fp,0,2);
        for(i=0;i<n;++i)
        {
            fwrite(&dobj,sizeof(struct date),1,fp);
            fwrite(&sobj[i],sizeof(struct stud),1,fp);
            }
        }
    else{
        fclose(fp);
        fclose(fp1);
        remove("record.dat");
        rename("newrecord.dat","record.dat");
    }
    printf("\n\n\t\tATTENDANCE UPDATED SUCCESSFULLY!!!");
    getch();
    fclose(fp);}
}

void append()
{
    FILE *fp;
    struct date dobj;
    struct stud sobj;
    fp=fopen("record.dat","ab");
    	printf("\n\n\t\tEnter date(dd/mm/yy): ");
    	scanf(" %d",&dobj.dd);
    	scanf(" %d",&dobj.mm);
    	scanf(" %d",&dobj.yy);
    	printf("\n\n\t\tEnter Register No.: ");
    	scanf(" %lu",&sobj.rno);
    	printf("\n\t\tEnter Name; ");
    	scanf(" %[^\n]",sobj.name);
    	printf("\n\t\tEnter dept:");
    	scanf(" %[^\n]",sobj.dept);
    	printf("\n\t\tEnter sec:");
    	scanf(" %c",&sobj.sec);
    	printf("\n\t\tEnter year:");
    	scanf(" %d",&sobj.yr);
    	printf("\n\t\tEnter 6 subs:");
    	for(int i=0;i<6;i++)
    		scanf(" %[^\n]",sobj.sub[i]);
    	printf("\n\t\tEnter no of days present in 6 subs:");
    	for(int i=0;i<6;i++)
    		{scanf(" %d",&sobj.np[i]);printf("\t");}
    	printf("\n\t\tEnter no of days absent in 6 subs:");
    	for(int i=0;i<6;i++)
    		{scanf(" %d",&sobj.na[i]);printf("\t");}
    	printf("\n\t\tEnter no of ods in 6 subs:");
    	for(int i=0;i<6;i++)
    		{scanf(" %d",&sobj.nod[i]);printf("\t");}
    	printf("\n\t\tEnter todays status:");
    	for(int i=0;i<6;i++)
    		{scanf(" %c",&sobj.status[i]);printf("\t");}
    	sobj.status[6]='\0';

	fwrite(&dobj,sizeof(struct date),1,fp);
	fwrite(&sobj,sizeof(struct stud),1,fp);
    fclose(fp);
}
void teacher(struct teach tobj)
{
    FILE *fp;
	int op;
	char user[30];
	struct date dobj ;
	struct stud sobj ;
	struct handle hobj;
	int n=999;

	do
	{
	    system("CLS");
		printf("\n\n\t\t1.Update Attendance\n\n\t\t2.Append Data\n\n\t\t3.Class wise view attendance\n\n\t\t4.Student wise view attendance\n\n\t\t5.Exit");
		printf("\n\n\t\tEnter your choice: ");
		scanf(" %d",&op);
		switch(op)
		{
			case 1:update(tobj);
					break;
            case 2: append();
                    break;
            case 3:

                printf("\n\n\t\tEnter Department: ");
                scanf(" %[^\n]",hobj.dept);
                printf("\n\n\t\tEnter Section: ");
                scanf(" %c",&hobj.sec);
                printf("\n\n\t\tEnter year: ");
                scanf(" %d",&hobj.yr);
                printf("\n\n\n\t\tYear: %d\tDept: %s\tSec: %c",hobj.yr,hobj.dept,hobj.sec);
                display(hobj,&n);
                break;
            case 4:
                printf("\n\n\t\tEnter Student Register number: ");
                scanf(" %s",user);
                student(user);
                break;
		}
		getch();
	}while(op!=5);

}
void login(char s[])
{
    FILE *fp;
    fp=fopen(s,"r");
    int i=0,flag=0;
    char un[30],pass[30],ch,fun[30],fpass[30];
    printf("\n\t\tEnter Username/Register no.: ");
    scanf("%s",un);
    printf("\n\t\tEnter Password: ");
    encrypt(pass);
         if(strcmp("student.txt",s)==0)
         {
             while(!feof(fp))
            {

            fscanf(fp," %[^\t]",fun);
            fscanf(fp," %[^\n]",fpass);
            if((strcmp(fun,un)==0&&strcmp(fpass,pass)==0))
                {printf("\n\n\t\t\tLOGIN SUCCESSFUL!!");
                getch();
            flag=1;
            student(fun);
            break;}
         }
         }
         else
         {
             fclose(fp);
             fopen("tdata.dat","rb");
             struct teach tobj;
             fread(&tobj,sizeof(struct teach),1,fp);
             while(!feof(fp))
             {
                 if(strcmp(tobj.user,un)==0&&strcmp(tobj.pass,pass)==0)
                 {  printf("\n\n\t\t\tLOGIN SUCCESSFUL!!");
                 getch();
                    flag=1;
                    teacher(tobj);
                    break;
                 }
                 fread(&tobj,sizeof(struct teach),1,fp);
             }
    }
    if(flag==0)
       {
        printf("\n\n\t\tInvalid Username or Password");
        getch();
       }
    fclose(fp);

}
void newuser(char ch)
{
    char name[30],pass[30],rpass[30],fun[30],fpass[30];
   FILE *fp;
   int flag=0;
   int i=0;
   struct teach obj,temp;
    if(ch=='T'||ch=='t')
            {
                do
                {
                    printf("\n\n\t\tEnter name :");
                    scanf(" %[^\n]",obj.name);
                    printf("\n\t\tEnter User Name: ");
                    scanf(" %[^\n]",name);
                    flag=0;
                    fp=fopen("tdata.dat","rb");
                    fread(&temp,sizeof(struct teach),1,fp);
                    while(!feof(fp))
                    {
                    if(strcmp(temp.user,name)==0)
                       {
                         flag=1;break;
                       }
                    fread(&temp,sizeof(struct teach),1,fp);
                    }
                    fclose(fp);
                }while(flag!=0);
                do
                {
                    strcpy(obj.user,name);
                    printf("\n\t\tEnter password: ");
                    encrypt(obj.pass);
                    printf("\n\t\tRenter password: ");
                    encrypt(rpass);
                    if(strcmp(obj.pass,rpass)!=0)
                        printf("\n\n\t\tNo Match!!!Renter Password");
                }while(strcmp(obj.pass,rpass)!=0);
                i=0;
                do
                {
                    printf("\n\n\t\tEnter department :");
                    scanf(" %[^\n]",obj.info[i].dept);
                    printf("\n\n\t\tEnter section :");
                    scanf(" %c",&obj.info[i].sec);
                    printf("\n\n\t\tEnter yr :");
                    scanf(" %d",&obj.info[i].yr);
                    printf("\n\n\t\tEnter subject :");
                    scanf(" %[^\n]",obj.info[i].sub);
                    i++;
                    printf("\n\n\t\tDo you want to continue?(Y-yes/N-no): ");
                    scanf(" %c",&ch);
                }while(ch=='y'||ch=='Y');
                 obj.info[i].dept[0]='\0';
                fp=fopen("tdata.dat","ab");
                fwrite(&obj,sizeof(struct teach),1,fp);
                fclose(fp);
            }
            else
            {
                do
                {
                    printf("\n\t\tEnter User Name/Register no.: ");
                    scanf(" %[^\n]",name);
                    flag=0;
                    fp=fopen("student.txt","r");
                   while(!feof(fp))
                    {
                    fscanf(fp," %[^\t]",fun);
                    fscanf(fp," %[^\n]",fpass);
                    if(strcmp(fun,name)==0)
                       {
                         flag=1;break;
                       }
                    }
                    fclose(fp);
                }while(flag!=0);
                do
                {
                printf("\n\n\t\tEnter password: ");
                encrypt(pass);
                printf("\n\n\t\tRenter password: ");
                i=0;
                encrypt(rpass);
                if(strcmp(pass,rpass)!=0)
                    printf("\n\n\t\tNo Match!!!Renter Password");
                }while(strcmp(pass,rpass)!=0);
                fp=fopen("student.txt","a");


            fseek(fp,0,2);
            fprintf(fp,"%s\t",name);
            fprintf(fp,"%s\n",pass);
            fclose(fp);
            }

}
void main()
{
    int op;
    char ch,name[30],pass[30],rpass[30];
    FILE *fp;
    do
    { 
    system("CLS");
    printf("\n\n\t\tATTENDANCE MANAGEMENT SYSTEM");
    printf("\n\n\t\t1.Teacher Login");
    printf("\n\n\t\t2.Student Login");
    printf("\n\n\t\t3.New user(sign up)");
    printf("\n\n\t\t4.Exit");
    printf("\n\n\t\tEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
        case 1:login("teacher.txt");
            break;
        case 2:login("student.txt");
            break;
        case 3:printf("\n\t\tEnter T-Teacher/S-Student: ");
            scanf(" %c",&ch);
            newuser(ch);
            break;
    }
    }while(op!=4);
}

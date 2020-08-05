#include<stdio.h>
#include<string.h>
struct date
{
    int dd,mm,yy;
};

struct student
{
    int rollno,rank,age;
    float marks[5],totalMarks;
    char name[30],gender[15];
    struct date dateofbirth;
};

void input(struct student S[],int n)
{
    for(int i=0;i<n;++i)
    {
		 int op;
		 printf("\nStudent %d\n~~~~~~~~~~~",i+1);
		printf("\nEnter Roll no. : ");
		scanf("%d",&S[i].rollno);
		printf("\nEnter the student's name : ");
		scanf(" %[^\n]",S[i].name);
		printf("\nEnter the age: ");
		scanf("%d",&S[i].age);
		printf("\nEnter Gender: ");
		scanf("%s",S[i].gender);
		printf("\nEnter date of birth(dd/mm/yyyy): ");
		scanf("%d %d %d",&S[i].dateofbirth.dd,&S[i].dateofbirth.mm,&S[i].dateofbirth.yy);

		printf("\nEnter the marks:");
		S[i].totalMarks=0;
		for(int j=0;j<5;j++)
		{
			printf("\nSubject %d:",j+1);
			scanf("%f",&S[i].marks[j]);
			S[i].totalMarks+=S[i].marks[j];
		}

	}
}
void display(struct student S)
{
		printf("\nRoll no. :%d",S.rollno);
		printf("\nstudent's name : %s",S.name);
		printf("\nAge: %d",S.age);
		printf("\nGender: %s",S.gender);
		printf("\nDate of birth(dd/mm/yyyy): %d/%d/%d",S.dateofbirth.dd,S.dateofbirth.mm,S.dateofbirth.yy);
		printf("\nMarks:");
		for(int j=0;j<5;j++)
			printf("\nSubject %d: %.2f",j+1,S.marks[j]);
        printf("\nTotal marks: %.2f",S.totalMarks);
        printf("\nRank: %d ",S.rank);
        printf("\n=================================");
}
void rank(struct student S[],int n)
{
int i,j;
struct student p;
for(i=0;i<n-1;i++)
	for(j=0;j<n-i-1;j++)
		{
		if(S[j].totalMarks<S[j+1].totalMarks)
			{
			p=S[j];
			S[j]=S[j+1];
			S[j+1]=p;
			}
		}
S[0].rank=1;
for(i=1;i<n;i++)
	{
	if(S[i].totalMarks==S[i-1].totalMarks)
		S[i].rank=S[i-1].rank;

	else
		S[i].rank=i+1;
	}

}
void main()
{
    struct student stud[20];
    int i,j,n;
    char name[30];
    printf("\nEnter the no. of students: ");
    scanf("%d",&n);
    input(stud,n);
    rank(stud,n);
    printf(“\n Ranking Details”);
    printf(“\n************”);
    for(i=0;i<n;++i)
        display(stud[i]);
    int ch;
    do
    {
        printf("\nTo print mark sheet of a particular student");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        printf("\nEnter a name: ");
        scanf(" %[^\n]",name);
        for(i=0;i<n;++i)
            if(strcmp(stud[i].name,name)==0)
            {
                display(stud[i]);
                break;
            }
        printf("\nDo you want to continue?(Y/N) ");
        scanf(" %c",ch);

    }while(ch=='y'||ch=='Y');


}
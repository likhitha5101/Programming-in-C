#include<stdio.h>
#include<stdio.h>
struct emp
{
char name[30];
int empid;
float bp,da,hra,cca,ins,pf,gross,ded,net;
};
void input(struct emp *obj)
{
printf("\nEnter Employee's name : ");
gets(obj->name);
printf("\nEnter Employee ID : ");
scanf("%d",&obj->empid);
printf("\nEnter Basic Pay : ");
scanf("%f",&obj->bp);
}
void compute(struct emp *obj)
{
obj->da=0.88*obj->bp;
obj->hra=0.08*obj->bp;
obj->cca=1000;
obj->ins=2000;
obj->pf=0.12*obj->bp;
obj->gross=obj->da+obj->hra+obj->cca;
obj->ded=obj->ins+obj->pf;
obj->net=obj->gross-obj->ded;
}
void print(struct emp obj)
{
printf("\nSALARY DETAILS");
printf("\n~~~~~~~~~~~~~~~~");
printf("\nEmployee's name : %s",obj.name);
printf("\nEmployee ID : %d",obj.empid);
printf("\nBasic Pay : %.2f",obj.bp);
printf("\nGross salary = %0.2f",obj.gross);
printf("\nDeductions = %0.2f",obj.ded);
printf("\nNet salary = %0.2f \n",obj.net);
}
void main()
{
struct emp obj;
input(&obj);
compute(&obj);
print(obj);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct rec
{
    char name[30],add[30];
    unsigned long ph;
};
struct rec input()
{
    struct rec obj;
    printf("\nEnter Name: ");
    scanf("%s",obj.name);
    printf("\nEnter address:" );
    scanf("%s",obj.add);
    printf("\nEnter phone number: ");
    scanf("%lu",&obj.ph);
    return obj;
}
void display(struct rec obj)
{
    printf("\nNAME: %s",obj.name);
    printf("\nADDRESS: %s",obj.add);
    printf("\nPHONE NO: %lu\n",obj.ph);
}
void add()
{
    struct rec obj;
    FILE *fp;
    fp = fopen("details.dat", "ab");
    obj=input();
    fwrite(&obj,sizeof(struct rec),1,fp);
    fclose(fp);
}
void ins(int m)
{
    struct rec obj;
    int i=0;
    FILE *fp1,*fp2;
    fp1 = fopen("details.dat", "rb");
    fp2 = fopen("newdet.dat", "wb");
    for(;i<m-1;++i)
    {
        fread(&obj,sizeof(struct rec),1,fp1);
        fwrite(&obj,sizeof(struct rec),1,fp2);
    }
    obj=input();
    fwrite(&obj,sizeof(struct rec),1,fp2);
    while(1)
    {
        fread(&obj,sizeof(struct rec),1,fp1);
        if(!feof(fp1))
            fwrite(&obj,sizeof(struct rec),1,fp2);
        else
            break;
    }
    fclose(fp1);
    fclose(fp2);
    remove("details.dat");
    rename("newdet.dat","details.dat");
    printf("\nRECORD INSERTED SUCCESSFULLY!!!\n");
}
void del()
{
    struct rec obj;
    int i=0;
    char name[30];
    FILE *fp1,*fp2;
    fp1 = fopen("details.dat", "rb");
    fp2 = fopen("newdet.dat", "wb");
    printf("\nEnter name to delete record: ");
    scanf(" %[^\n]",name);
    while(1)
    {
        fread(&obj,sizeof(struct rec),1,fp1);
        if(strcmp(name,obj.name)!=0&&(!feof(fp1)))
            fwrite(&obj,sizeof(struct rec),1,fp2);
        if(feof(fp1))
            break;
    }
    fclose(fp1);
    fclose(fp2);
    remove("details.dat");
    rename("newdet.dat","details.dat");
    printf("\nRECORD DELETED SUCCESSFULLY!!!\n");
}
void n_disp(int n)
{
    struct rec obj;
    FILE *fp;
    fp = fopen("details.dat", "rb");
    fseek(fp,sizeof(struct rec)*(n-1),0);
    fread(&obj,sizeof(struct rec),1,fp);
    display(obj);
    fclose(fp);
}
void disp()
{
    struct rec obj;
    FILE *fp;
    fp = fopen("details.dat", "rb");
    while(1)
    {
        fread(&obj,sizeof(obj),1,fp);
        if(!feof(fp))
            display(obj);
        else
            break;

        printf("\n************************");
    }
    fclose(fp);
}
void main()
{
    struct rec obj;
    int n,op;
    char name[30];
    do
    {
    printf("\nMENU\n******");
    printf("\n1.Add a record \n2.Insert a record \n3.Delete a record\n4.Display nth record \n5.Display all records\n6.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("\nADD NEW RECORD");
        add();
        break;
    case 2:
        printf("\nINSERT A RECORD");
        printf("\nEnter the value of m(position): ");
        scanf(" %d",&n);
        ins(n);
        break;
    case 3:
        printf("\nDELETE A RECORD");
        del();
        break;
    case 4:
        printf("\nDISPLAY Nth RECORD");
        printf("\nEnter the value of n(position): ");
        scanf(" %d",&n);
        n_disp(n);
        break;
    case 5:
        printf("\nDISPLAY ALL RECORDS");
        disp();
        break;
    }
    }while(op!=6);
}

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
    fp = fopen("phone.dat", "ab");
    obj=input();
    fprintf(fp,"%s\n",obj.name);
    fprintf(fp,"%s\n",obj.add);
    fprintf(fp,"%lu\n",obj.ph);
    fclose(fp);
}
void ret(char name[30])
{
    struct rec obj;
    FILE *fp;
    fp = fopen("phone.dat", "rb");
    while(1)
    {
        fscanf(fp," %[^\n]",obj.name);
        fscanf(fp," %[^\n]",obj.add);
        fscanf(fp," %lu",&obj.ph);
        if((strcmp(name,obj.name)==0)&&(!feof(fp)))
                display(obj);
        if(feof(fp))
            break;
    }
    fclose(fp);
}
void modify()
{
    int op;
    char name[30];
    struct rec obj,newobj;
    FILE *fp1,*fp2;
    fp1 = fopen("phone.dat", "a+b");
    fp2 = fopen("phonenew.dat", "a+b");
    printf("\nEnter name to search and modify: ");
    scanf(" %[^\n]",name);
    while(1)
    {
        fscanf(fp1," %[^\n]",obj.name);
        fscanf(fp1," %[^\n]",obj.add);
        fscanf(fp1," %lu",&obj.ph);
        if((strcmp(name,obj.name)==0)&&(!feof(fp1)))
                {
                    display(obj);
                    printf("\nDo you want to modify\n1.NAME\n2.ADDRESS\n3.PHONE NUMBER");
                    printf("\nEnter (1/2/3): ");
                    scanf("%d",&op);

                    switch(op)
                    {
                        case 1:
                            printf("\nEnter new name: ");
                            scanf(" %[^\n]",obj.name);
                            break;
                        case 2:
                            printf("\nEnter new address: ");
                            scanf(" %[^\n]",obj.add);
                            break;
                        case 3:
                            printf("\nEnter new phone number: ");
                            scanf(" %lu",&obj.ph);
                            break;
                    }
                }
        if(feof(fp1))
            break;
        else
        {
        fprintf(fp2,"%s\n",obj.name);
        fprintf(fp2,"%s\n",obj.add);
        fprintf(fp2,"%lu\n",obj.ph);
        }
    }
    fclose(fp1);
    fclose(fp2);
    remove("phone.dat");
    rename("phonenew.dat","phone.dat");
    printf("\n\nRECORD MODIFIED SUCCESSFULLY!!!");
}
void disp()
{
    struct rec obj;
    FILE *fp;
    fp = fopen("phone.dat", "rb");
    while(1)
    {
        fscanf(fp," %[^\n]",obj.name);
        fscanf(fp," %[^\n]",obj.add);
        fscanf(fp," %lu",&obj.ph);
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
    int op;
    char name[30];
    do
    {

    printf("\nMENU\n******");
    printf("\n1.Add a record \n2.Modify \n3.Retrieve and display \n4.Display all records\n5.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&op);
    switch(op)
    {
    case 1:
        printf("\nADD NEW RECORD");
        add();
        break;
    case 2:
        printf("\nMODIFY EXISTING RECORD");
        modify();
        break;
    case 3:
        printf("\nRETRIEVE EXISTING RECORD");
        printf("\nEnter name to search: ");
        scanf(" %[^\n]",name);
        ret(name);
        break;
    case 4:
        printf("\nDISPLAY ALL RECORDS");
        disp();
        break;
    }
    }while(op!=5);
}

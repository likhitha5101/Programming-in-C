#include <stdio.h>
#include<stdlib.h>

#define rmax 20

void input(int *a[rmax], int r, int nc)
{
    int row,col;
    printf("\nEnter the elements:\n");
    for(row=0;row<r;row++)
    {
        printf("\nRow : %2d:\n",row+1);
        for(col=0;col<nc;col++)
            scanf("%d",(*(a+row)+col));
        printf("\n");
    }
            
}

void larger(int *a[rmax], int *b[rmax], int *c[rmax], int r, int nc)
{
    int row,col;
	
    for(row=0;row<r;row++)
    	for(col=0;col<nc;col++)
                if(*(*(a+row)+col)>*(*(b+row)+col))
			*(*(c+row)+col)=*(*(a+row)+col);
		else
			*(*(c+row)+col)=*(*(b+row)+col);
}

void display(int *c[rmax],int r, int nc)
{
    int row,col;
    for(row=0;row<r;row++)
    	{
	printf("\n");
	for(col=0;col<nc;col++)
            		printf("%4d",*(*(c+row)+col));
        	}
	printf("\n");    
}


void main()
{

    int r,nc,row;
    int *a[100],*b[100],*c[100];
    
    
    printf("\nEnter number of rows:");
    scanf("%d",&r);
    printf("\nEnter number of columns:");
    scanf("%d",&nc);
    
    

    for(row=0;row<r;row++)
    {
        a[row]=(int *) malloc (nc*sizeof(int));
        b[row]=(int *) malloc (nc*sizeof(int));
        c[row]=(int *) malloc (nc*sizeof(int));
    }
    
    input(a,r,nc);
    input(b,r,nc);
    larger(a,b,c,r,nc);
    display(c,r,nc);
    
}

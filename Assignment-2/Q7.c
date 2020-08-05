#include<stdio.h>
#include<stdlib.h>
char play='X';
char val='O';

void main()
{
int op,pos,count=0;
char a1=' ',a2=' ',a3=' ',b1=' ',b2=' ',b3=' ',c1=' ',c2=' ',c3=' ';
//char a1=a2=a3=b1=b2=b3=c1=c2=c3=' ';


printf("\n\nChoose Player (1 or 2): ");
scanf("%d",&op);
play='X';val='O';

while(count<9)
{
if((op==2 && play=='X')|| (op==1 && play=='O'))
 pos=(rand()%9 +1);
else
{
printf("Player %c : Choose position(1-9): ",play);
scanf("%d",&pos);
}
switch(pos)
{
case 1: if(a1==' ')
	 {a1=play;count++;}
	else
	 {if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;
case 2: if(a2==' ')
	{a2=play;count++;}
	else {
	if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;
case 3: if(a3==' ')
	{a3=play;count++;}
	else {
	if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;
case 4: if(b1==' ')
	{b1=play;count++;}
	else if(op==2 && play=='O'|| (op==1 && play=='X'))
	{printf("wrong move\n");play=val;}
	break;
case 5: if(b2==' ')
	{b2=play;count++;}
	else {
	if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;
case 6: if(b3==' ')
	{b3=play;count++;}
	else {
	if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;
case 7: if(c1==' ')
	{c1=play;count++;}
	else {
	if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;
case 8: if(c2==' ')
	{c2=play;count++;}
	else {
	if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;
case 9: if(c3==' ')
	{c3=play;count++;}
	else {
	if(op==2 && play=='O'|| (op==1 && play=='X'))
	printf("wrong move\n");
	play=val;}
	break;

}



printf("%c\t%c\t%c\n\n%c\t%c\t%c\n\n%c\t%c\t%c\n\n",a1,a2,a3,b1,b2,b3,c1,c2,c3);
printf("-----------------------------------------------\n");



if((a1==a2 && a2==a3) && a1!=' ' && a2!= ' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}
else if((b1==b2 && b2==b3) && b1!=' ' && b2!=' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}
else if((c1==c2 && c2==c3) && c1!=' ' && c2!=' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}
else if((a1==b1 && b1==c1) && a1!=' ' && b1!=' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}
else if((a2==b2 && b2==c2) && b2!=' ' && a2!=' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}
else if((a3==b3 && c3==a3) && a3!=' ' && b3!=' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}
else if((a1==b2 && b2==c3) && a1!=' ' && b2!=' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}
else if((c1==b2 && b2==a3) && c1!=' ' && b2!=' ') 
{
printf("\nPlayer %c Wins!!!\n",play);
break;
}

if(play =='X')
 {play='O';
 val='X';
}
else
 {
play='X';
val='O';}

}


//printf("\n\n%d",count);
if (count==9)
printf("\nDraw match !!!\n");

}

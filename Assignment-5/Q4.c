#include<stdio.h>
#include<stdlib.h>
long nodays(int *date)
{
	long ndays;
	int yy=*(date+2);
	ndays=(long)(30.42*(*(date+1)-1)+*date);
	if (*(date+1)==2)
		ndays+=1;
	else if(*(date+1)>2 && *(date+1)<8)
		ndays-=1;
	yy-=1900;
	if(yy%4==0 &&*(date+1)>2)
		ndays+=1;
	ndays+=(yy/4)*1461;
	ndays+=(yy%4)*365+1;
	if(ndays>59)
		ndays-=1;
	//printf("%ld\n",ndays%7);
	return ndays;
}
void main()
{
	int *date1,*date2;
	long n1,n2,diff;
	date1=(int*)malloc(3*sizeof(int));
	date2=(int*)malloc(3*sizeof(int));
	printf("\n\nFINDING DIFFERENCE BETWEEN TWO DAYS");
	printf("\n\nEnter a date(mm dd yyyy): ");
	scanf("%2d %2d %4d",(date1+1),(date1),(date1+2));
	n1=nodays(date1);
	printf("\nEnter another date(mm dd yyyy): ");
	scanf("%2d %2d %4d",(date2+1),(date2),(date2+2));
	n2=nodays(date2);
	diff=n1-n2;
	if (diff>0)
		printf("\n\n%d %d %d comes after %ld days of %d %d %d",*(date1+1),*(date1),*(date1+2),diff,*(date2+1),*(date2),*(date2+2));
	else
		printf("\n\n%d %d %d comes after %ld days of %d %d %d\n",*(date2+1),*(date2),*(date2+2),-diff,*(date1+1),*(date1),*(date1+2));

}

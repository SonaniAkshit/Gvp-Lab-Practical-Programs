
#include<stdio.h>
#include<conio.h>
void rem(int [],int *,int *);
void in(int [],int *,int *);
void display(int [],int *,int *);
void main()
{
	int q[50],front=-1,rear=-1,ch;
	int *f=&front,*r=&rear;

	while(1)
	{
		printf("\n 1.insert");
		printf("\n 2.remove");
		printf("\n 3.display");
		printf("\n 5.exit");
		printf("\n eneter your choics:-");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: in(q,f,r); break;
			case 2: rem(q,f,r); break;
			case 3: display(q,f,r); break;
			case 5: exit(0);
		}
	}
	getch();
}

void in(int q[],int *f,int *r)
{
	int n;
	if((*r==*f-1) ||(*r==4 && *f==0))
	{
		printf("\n queue is full...");
	}
	else
	{
		if(*f==-1 && *r==-1)
		{
			*f=*r=0;
			printf("\n enetere an element:- ");
			scanf("%d",&n);
			q[*r]=n;
		}
		else
		{
			if(*r==4 && *f!=0)
			{
				*r=0;
				printf("\n enetere an element:- ");
				scanf("%d",&n);
				q[*r]=n;
			}
			else
			{
				printf("\n enetere an element:- ");
				scanf("%d",&n);
				(*r)++;
				q[*r]=n;
			}
		}
	}
}
void rem(int q[],int *f,int *r)
{

}
void display(int q[],int *f,int *r)
{

}

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct grid{
	int ind;
	struct grid * link;
};
typedef struct grid * lptr;
void disp(lptr head)
{
	while(head!=NULL)
	{
		printf("%d ",head->ind);
		head=head->link;
	}
}
lptr insertend(lptr head,int pos)
{
	lptr p,t;
	p=(lptr)malloc(sizeof(struct grid));
	p->ind=pos;
	p->link=NULL;
	if(head==NULL)
		return p;
	else
	{
		t=head;	
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=p;
	}
	return head;
}

lptr booking(lptr head,int rows,int cols,int rowpos,int colpos,int seats)
{
	int i=0,j;
	lptr l;
	int pos=(rowpos*cols)+colpos,tru=1;
	if(rowpos>rows-1 || colpos> cols-1 || rowpos <0 || colpos<0 || seats > cols-colpos|| pos>(rows*cols-1))
	{
		printf("booking error\n");
		tru=0;
	}	//as there is no return ;
	if(tru==1)
	{
		printf("at booking counter : ");
		for(i=0;i<=seats-1;i++)
		{
			head=insertend(head,pos);
			pos++;
		}
	}
	//l=head;      // wont work if we dec at initialisation;
	disp(head);
	return head;
}
lptr cancel(lptr head,int rows,int cols,int rowpos,int colpos ,int seats)
{
	printf("\n\n");
	int pos;
	int c=0,flag=0;
	lptr temp,l=head,t=head;
	printf("cancellation: ");
	if(rowpos>rows-1 || colpos> cols-1 || rowpos <0 || colpos<0 || seats > cols-colpos|| pos>(rows*cols-1))
	{
		printf("cancellation error\n");
	}
	else
	{
		int last=0;
		while(seats!=0)
		{		
			while(t!=NULL)
			{
				pos=(rowpos*cols)+colpos;
				if(t->ind==pos )
				{
					if(t->link==NULL)
					{
						temp=t;
						free(temp);
						t->link=NULL;
					}
					else
					{
						t->ind=t->link->ind;
						temp=t->link;
						t->link=t->link->link;
						free(temp);
						flag=1;
						seats--;
						colpos++;
						break;
					}
				}
	
				t=t->link;
				disp(l);printf("\n");
			}
		}
	if(flag==0)
		printf("cancellation error");
	printf("\n..");
	disp(l);	
	}
}
main()
{
	lptr head=NULL,k=NULL;
	int m=5;
	int n=10;
	int seats=3;
	k=booking(head,m,n,2,4,6);
	//cancel(k,m,n,2,9,1);
}

#include<stdio.h>
#include<malloc.h>
struct grid
{
	int num;
	struct grid * link;
};
typedef struct grid * lptr;
void disp(lptr head,int rows,int cols)
{
	int c=0;
	while(head!=NULL)
	{
		printf("%d ",head->num);
		head=head->link;
		c++;
		if(c==cols)
		{
			c=0;
			printf("\n");
		}
	}
}
lptr booking(lptr head,int rows,int cols,int rowpos,int colpos,int seats)
{
	int pos=((rowpos)*cols)+(colpos),tru=1;	
	int size=rows*cols,i=0,j,k=0;
	int c=0,c1=0,flag=1;lptr temp,l=head;
	if(rowpos>rows-1  || rowpos <0 || colpos<0 || pos>(rows*cols-1))// || colpos> cols-1|| seats > cols-colpos)
	{
		printf("booking error\n");
		tru=0;
	}
	else
	{
		while(head->link!=NULL)
		{
				i++;
				if(i>=pos && i<pos+seats)
				{
					if(flag==1)
					{
						temp=head;
						flag=0;
					}
					if(head->num==0)
						c++;
					if(head->num==1)
						c1++;
				}
				if(c1>0)
				{
					printf("only %d seat/s is/are available %d is/are already booked \n",c,c1);
					tru=0;
					break;
				}
				if(c==seats)
				{
					lptr t=temp;
					while(t!=NULL)
					{
						t->num=1;
						t=t->link;c--;
						if(c==0)
							break;
					}
				}
				head=head->link;
		}
		if(tru==1)
			disp(l,rows,cols);
	}
}
lptr cancel(lptr head,int rows,int cols,int rowpos,int colpos,int seats)
{
	int pos=((rowpos)*cols)+(colpos),tru=1;
	int i=0,j,k,c=0,c1=0,flag=1;
	lptr temp,l=head;
	if(rowpos>rows-1 || rowpos <0 || colpos<0 || pos>(rows*cols-1))// || colpos> cols-1 || seats > cols-colpos)
	{
		printf("booking error \n");
		break;
	}
	else
	{
		while(head!=NULL)
		{
				i++;
				if(i>=pos && i<pos+seats)
				{
					if(flag==1)
					{
						temp=head;
						flag=0;
					}
					if(head->num==1)					
						c++;					
					if(head->num==0)
						c1++;	
				}
				if(c1==seats)
				{
					printf("bookings not found");
				}
				if(c==seats)
				{	
					lptr t=temp;
					while(t!=NULL)
					{
						t->num=0;
						t=t->link;c--;
						if(c==0)
							break;
					}
					break;
				}				
			head=head->link;
		}
		disp(l,rows,cols);
	}
}
lptr createLL(lptr l,int m,int n)
{
	lptr p=NULL,t=NULL;int i;
	for(i=0;i<=(m*n)-1;i++)
	{
		p=(lptr)malloc(sizeof(struct grid));
		p->num=0;
		p->link=t;
		t=p;
	}
	return t;
}
main()
{
	lptr l=NULL,k=NULL;
	int m=5;
	int n=10;
	k=createLL(l,m,n);
	booking(k,m,n,2,3,3);printf("\n\n");
	//booking(k,m,n,2,2,2);printf("\n\n");
	booking(k,m,n,1,5,8);printf("\n\n");
	//booking(k,m,n,3,4,6);printf("\n\n");
	
	//cancel(k,m,n,3,4,3);printf("\n\n");
	//cancel(k,m,n,2,3,2);
}


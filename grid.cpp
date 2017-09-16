#include<stdio.h>
#include<stdlib.h>
void disp(int **a,int m ,int n)
{
	int i,j;
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}
int book(int **a,int rows,int cols,int rowpos,int colpos,int seats)
{
	int i,j,c=0,k,flag=0,c1=0;
//	for(i=rowpos;i<=rows-1;i++)
//	{
	if(rowpos>rows-1 || colpos> cols-1 || rowpos <0 || colpos<0 || seats > cols-colpos)
		printf("booking error => row/col limit exceeded");
	else
	{
		for(j=colpos;j<=colpos+seats-1;j++)
		{
			if(a[rowpos][j]==0)
				c++;
			else if(a[rowpos][j]==1)
				c1++;
			if(c1>0)
			{
				if(c<=1)
					printf("Sorry! only %d is available and %d are already booked",c,c1);
				else
					printf("Sorry! only %d is available and %d are already booked",c,c1);			
				break;
			}
			if(c==seats)
			{				
				for(k=colpos;k<=colpos+seats-1;k++)
					a[rowpos][k]=1;
				c=0;flag=1;
				break;
			}
		}
	}
	if(flag==1)
		disp(a,rows,cols);
	printf("\n\n");
}

int cancel(int **a,int rows,int cols,int rowpos,int colpos,int seats)
{
	int i,j,k,c=0,flag=0;
	for(i=colpos;i<=colpos+seats-1;i++)
	{
		if( a[rowpos][i]==1 )
			c++;
	}
	if(c<seats)
	{
		printf("cancel error");
	}
	else if(c>=seats)
	{
		flag=1;
		for(i=colpos;i<=colpos+seats-1;i++)
			a[rowpos][i]=0;
	}
	printf("\n\n");
	if(flag==1)
		disp(a,rows,cols);
}
main()
{
	int **a;
	int m=5,n=10,seats=4;
	a=(int**)calloc(m,sizeof(int*));
	for(int i=0;i<=m-1;i++)
		a[i]=(int*)calloc(n,sizeof(int));
	int rp= 3 ;
	int cp= 3 ;
	book((int**)a,m,n,rp,cp,seats);
	book((int**)a,m,n,2,3,3);
	book((int**)a,m,n,2,6,6);
	cancel((int**)a,m,n,2,2,5);
	cancel((int**)a,m,n,2,3,3);
}


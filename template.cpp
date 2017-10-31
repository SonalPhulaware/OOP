#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
void read(T a[10][10],T r,T c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
}

template<class T>
void display(T a[10][10],T r,T c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			cout<<"\t"<<a[i][j];
		}
		cout<<"\n";
	}
}

template<class T>

void addition(T a[10][10],T b[10][10],int r1,int c1,int r2,int c2)
{
	T c[10][10];
	int i,j;
	if(r1!=r2 && c1!=c2)
	{
		cout<<"\n Addition is not possible \n";
		return;
	}
	for(i=0;i<r1;i++)	
	{
		for(j=0;j<c1;j++)
		{		
			c[i][j]=a[i][j]+b[i][j];
		}
	}
		
	cout<<"\n--------------Addition is----------------\n";
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			cout<<"\t"<<c[i][j];
		}
		cout<<"\n";
	}

}

template <class T>

void subtraction(T a[10][10],T b[10][10],int r1,int c1,int r2,int c2)
{
	T c[10][10];
	int i,j;
	if(r1!=r2 && c1!=c2)
	{
		cout<<"\n Subtraction is not possible \n";
		return;
	}
	for(i=0;i<r1;i++)	
	{
		for(j=0;j<c1;j++)
		{		
			c[i][j]=a[i][j]-b[i][j];
		}
	}
		
	cout<<"\n--------------Subtraction is----------------\n";
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			cout<<"\t"<<c[i][j];
		}
		cout<<"\n";
	}

}

template <class T>

void multiplication(T a[10][10],T b[10][10],int r1,int c1,int r2,int c2)
{
	T c[10][10];
	int i,j,k;
	if(r1!=c2)
	{
		cout<<"\n Multiplication is not possible \n";
		return;
	}
	for(i=0;i<r1;i++)	
	{
		for(j=0;j<c1;j++)
		{
			c[i][j]=0;
			for(k=0;k<c1;k++)	
			{		
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
		
	cout<<"\n--------------Multiplication is----------------\n";
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			cout<<"\t"<<c[i][j];
		}
		cout<<"\n";
	}

}


int main()
{
	int ch,a[10][10],b[10][10],r1,c1,r2,c2;
	cout<<"\n How many rows and cols you want for matrix A:\n";
	cin>>r1>>c1;

	cout<<"\n Enter the Elements \n";
	read(a,r1,c1);
	cout<<"\n----------------Matrix A---------------\n";
	display(a,r1,c1);

	cout<<"\n How many rows and cols you want for matrix B:\n";
	cin>>r2>>c2;

	cout<<"\n Enter the Elements \n";
	read(b,r2,c2);
	cout<<"\n----------------Matrix B---------------\n";
	display(b,r2,c2);

	do
	{
		cout<<"\n 1.Addition \n 2.Subtarction \n 3.Multiplication \n 4.Exit\n ";
		cout<<"\n Enter Your Choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				addition(a,b,r1,c1,r2,c2);
				break;
			case 2:
				subtraction(a,b,r1,c1,r2,c2);
				break;
			case 3:
				multiplication(a,b,r1,c1,r2,c2);
				break;
			case 4:
				exit(0);
			default:
				cout<<"\n Please Enter Correct choice\n";
		}
	}while(ch!=4);
	return 0;
}

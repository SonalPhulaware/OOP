/*
	Create a base class shape with two double type values and member functions to input data and compute area for calculationg are of figure. Derive three derived 
classes- rectangle,circle and cylinder.Make compute area as virtual function and redifine this function in derived classes. Write a program to that accepts 
dimensions of rectangle,circle and cylinder and display area.
*/

#include<iostream>
#include<stdlib.h>
using namespace std;
class shape
{
	protected:
		double dim1,dim2;
	public:
		void accept()
		{
			cout<<"\n Enter Dimension 1:\n";
			cin>>dim1;
			cout<<"\n Enter Dimension 2:\n";
			cin>>dim2;
		}
		virtual double cal_area()=0;	
};

class rectangle:public shape
{
	public:
		
		double cal_area()
		{
			return(dim1*dim2);
		}
};

class triangle:public shape
{
	public:
		
		double cal_area()
		{	
			return(0.5*dim1*dim2);
		}
};

class cylinder:public shape
{
public:
		
		double cal_area()
		{
			return(3.14*dim1*dim1*dim2);
		}

};

int main()
{
	
	int ch;
	rectangle  r;
	triangle t;
	cylinder c;
	shape *s;
	
	do
	{
		cout<<"\n\n 1.Area of Rectangle \n 2.Area of Traingle \n 3.Area of Cylinder \n 4.Exit\n";
		
		cout<<"\n Enter Your Choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s=&r;
				s->accept();
				cout<<"\n Area of Rectangle:"<<s->cal_area();
				break;
			case 2:
				s=&t;
				s->accept();
				cout<<"\n Area of Rectangle:"<<s->cal_area();
				break;
			case 3:
				s=&c;
				s->accept();
				cout<<"\n Area of Rectangle:"<<s->cal_area();
				break;
			case 4:
				exit(0);
			default:
				cout<<"\n Please Enter Correct Choice\n";
		}
	}while(ch!=4);
	return 0;
}

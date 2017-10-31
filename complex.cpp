/*	
 Designa class ‘Complex ‘with data members for real and imaginary part. Provide default and parameterized constructors. Write a program to perform arithmetic operations of two complex numbers using operator overloading. 
i. Addition and subtraction using friend functions 
ii. Multiplication and division using member functions 
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

class complex
{
	float real,img;
	
	public:
		complex()
		{
			real=0;
			img=0;
		}
		complex(int x,int y)
		{
			real=x;
			img=y;
		}
		friend ostream& operator <<(ostream& out,complex &c);
		friend istream& operator >>(istream& in,complex &c);
		friend complex operator +(complex c1,complex c2);
		friend complex operator -(complex c1,complex c2);
		complex operator *(complex c2);
		complex operator /(complex c2);		
};

ostream& operator <<(ostream& out,complex &c)
{
	out<<"\n"<<c.real;
	if(c.img>0)
	out<<"+"<<c.img<<"j";
	return  out;
}
istream& operator >>(istream& in,complex &c)
{
	cout<<"\n Enter the Real Part";
	in>>c.real;
	cout<<"\n Enter the imaginary part\n";
	in>>c.img;
	
	return in;
}

complex operator +(complex c1,complex c2)
{
	complex temp;
	temp.real=c1.real+c2.real;
	temp.img=c1.img+c2.img;
	return temp;
}
complex operator -(complex c1,complex c2)
{
	complex temp;
	temp.real=c1.real-c2.real;
	temp.img=c1.img-c2.img;
	return temp;
}
complex complex::operator *(complex c2)
{
	complex temp;
	temp.real=(real*c2.real)-(img*c2.img);
	temp.img=(real*c2.img)+(img*c2.real);
	return temp;
}
complex complex::operator /(complex c2)
{
	complex temp;
	temp.real=((real*c2.real)+(img*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
	temp.img=((img*c2.real)-(real*c2.img))/((c2.img*c2.img)+(c2.real*c2.real));
	return temp;
}

int main()
{
	complex c1,c2,c3;
	int ch;
	cin>>c1;
	cout<<c1<<"\n";
	cin>>c2;
	cout<<c2<<"\n";
	
	do
	{
		cout<<"\n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division \n 5.Exit\n  ";
		cout<<"\n Enter Your Choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				c3=c1+c2;
				cout<<c3<<"\n";
				break;
			case 2:
				c3=c1-c2;
				cout<<c3<<"\n";
				break;
			case 3:
				c3=c1*c2;
				cout<<c3<<"\n";
				break;
			case 4:
				c3=c1/c2;
				cout<<c3<<"\n";
				break;
			case 5:
				exit(0);
			default:
				cout<<"\n Please Enter Correct Choice\n";
				
		}
	}while(ch!=5);
	return 0;
}

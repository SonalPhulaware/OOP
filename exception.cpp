/*
	 Writea program in C++ which includes the code for following operations : 
i. A function to read two double type numbers from keyboard 
ii. A function to calculate the division of these two numbers 
iii. A try block to detect and throw an exception if the condition “divide-by-zero” occurs 
iv. Appropriate catch block to handle the exceptions thrown
*/

#include<iostream>
#include<stdlib.h>

using namespace std;
void accept(double &n1,double &n2)
{
	cout<<"\n Enter First No\n";
	cin>>n1;
	cout<<"\n Enter second No\n";
	cin>>n2;
}

void divide(double n1,double n2)
{
	double result;
	if(n2!=0)
	{
		result=n1/n2;
		cout<<"\n Division is :"<<result<<"\n";
	}
	else
	{
		throw(n2);
	}
	
}
int main()
{
	double n1, n2;
	accept(n1,n2);
	try
	{
		divide(n1,n2);
	}	
	catch(double x)
	{
		cout<<"\n Exception caught x:"<<x;
		cout<<"\n Divide by Zero\n";
	}
	return 0;
}


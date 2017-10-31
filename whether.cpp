/*
 Create a class named weather report that holds a daily weather report with data members day_of_month, hightemp, lowtemp,a mount_rain and amount_snow. Use different types of constructors to initialize the objects. Also include a function that prompts the user and sets values for each field so that you can override the default values. Write a menu driven program in C++ with options to enter data and generate monthly reportthat displays average of each attribute. 
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class whether
{
	int htemp,ltemp,amt_rain,amt_snow;
	public:
		void accept();
		void display(int i);
		
		int htemp1()
		{
			return htemp;
		}
		int ltemp1()
		{
			return ltemp;
		}
		int arain()
		{
			return amt_rain;
		}
		int asnow()
		{
			return amt_snow;
		}
		whether()
		{
			htemp=0;
			ltemp=0;
			amt_rain=0;
			amt_snow=0;
		}		
};

void whether::accept()
{
	cout<<"\n------------Enter Data-------------\n";
	cout<<"\n Enter Hight Tempreture\n";
	cin>>htemp;
	cout<<"\n Enter Low Tempreture\n";
	cin>>ltemp;
	cout<<"\n Enter Amount of rain\n";
	cin>>amt_rain;
	cout<<"\n EnterAmount of Snow\n";
	cin>>amt_snow;
}

void whether::display(int i)
{
	cout<<"\n "<<i+1<<"\t"<<htemp<<"\t"<<ltemp<<"\t"<<amt_rain<<"\t"<<amt_snow<<"\n";
}
int main()
{
	int ch,day,i;
	cout<<"\n How Many Days You want\n ";
	cin>>day;
	whether w[day];
	
	float sumh=0,suml=0,sumr=0,sums=0,avg;
	
	
	do
	{
		cout<<"\n 1.Accept \n 2.Display \n 3.Exit\n";
		cout<<"\n Enter Your Choice\n";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				for(i=0;i<day;i++)
				{
					w[i].accept();
				}
				break;
			case 2:
				cout<<"\n Day\t"<<"High"<<"\t"<<"Low"<<"\t"<<"Rain"<<"\t"<<"snow";
				cout<<"\n-----------------------------------------------------\n";
				for(i=0;i<day;i++)
				{
					w[i].display(i);
				}
				for(i=0;i<day;i++)
				{
					sumh=sumh+w[i].htemp1();
					suml=suml+w[i].ltemp1();
					sumr=sumr+w[i].arain();
					sums=sums+w[i].asnow();
				}
				cout<<"\n Avg:";
				cout<<"\t"<<sumh/day;
				cout<<"\t"<<suml/day;
				cout<<"\t"<<sumr/day;
				cout<<"\t"<<sums/day;		
				break;
			case 3:
				exit(0);
			default:
				cout<<"\n Please Enter Correct Choice\n";
		}
	}while(ch!=3);

	for(i=0;i<day;i++)
	{
		sumh=sumh+w[i].htemp1();
		suml=suml+w[i].ltemp1();
		sumr=sumr+w[i].arain();
		sums=sums+w[i].asnow();
	}
	cout<<"\n Avg:";
	cout<<"\t"<<sumh/day;
	cout<<"\t"<<suml/day;
	cout<<"\t"<<sumr/day;
	cout<<"\t"<<sums/day;
	
	return 0;		
}

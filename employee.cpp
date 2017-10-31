/*
Create an employee biodata by using multiple inheritance using c++.
accept personal information- name,address,date of birth,gender,contact number.
academic record- year of passing,percentage,grade,board,marks.
professional record- year of experience,organisation name,project name,salary details.

*/
#include<iostream>
using namespace std;
class personal
{
	protected:
		char name[10],dob[10],gender[20];
		char addr[30];
		int c_no;
	public:
		void p_accept()
		{
			cout<<"\n-------------Enter Biodata------------\n";
			cout<<"\n Enter Name:\n";
			cin>>name;
			cout<<"\n Enter Address:\n";
			cin>>addr;
			cout<<"\n Enter Date of Birth:\n";
			cin>>dob;
			cout<<"\n Enter Gender\n";
			cin>>gender;
			cout<<"\n Enter Contact Number\n";
			cin>>c_no;
		}	
};

class acedamic
{
	protected:
		int yr,marks;;
		char grade[10],board[20];
		float per;
	public:
		void acad_accept()
		{
			cout<<"\n Enter the Board name\n";
			cin>>board;			
			cout<<"\n Enter Year of passing\n";
			cin>>yr;
			cout<<"\n Enter Total marks:\n";
			cin>>marks;
			cout<<"\n Enter the Percentage:\n";
			cin>>per;
			cout<<"\n Enter the garde:\n";
			cin>>grade;
		}
};

class professional
{
	protected:
		int yre,salary;
		char org[20],prnm[20];
	public:
		void prof_accept()
		{
			cout<<"\n Enter the year of Experience\n";
			cin>>yre;
			cout<<"\n Enter salary:\n";
			cin>>salary;
			cout<<"\n Enter the Organisation name:\n";
			cin>>org;
			cout<<"\n Enter the Projet name\n";
			cin>>prnm;
		}
		
			
};


class biodata:public personal,public acedamic,public professional
{
	public:
		void display()
		{
			cout<<"\n\n------------------Personnal Details--------------------\n";
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<addr; 
			cout<<"\n DOB: "<<dob;
			cout<<"\n Gender: "<<gender;
			cout<<"\n Contact no: "<<c_no;

			cout<<"\n\n------------------Acedamic Details---------------------\n";
			cout<<"\n Board Name: "<<board;
			cout<<"\n Year of Passing: "<<yr;
			cout<<"\n Total marks: "<<marks;
			cout<<"\n Percentage: "<<per;
			cout<<"\n Grade: "<<grade;

			cout<<"\n\n------------------Professional Details---------------------\n";
			cout<<"\n Year of Experience: "<<yre;
			cout<<"\n Salary: "<<salary;
			cout<<"\n Orag.name: "<<org;
			cout<<"\n Project: "<<prnm;
			cout<<endl;
		}
};

int main()
{
	biodata b;
	b.p_accept();
	b.acad_accept();
	b.prof_accept();
	b.display();
}

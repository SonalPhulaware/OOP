/*
Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file.
*/
#include<iostream>
#include<fstream>
using namespace std;
class Test
{
	int roll;
	char name[20];
	int marks;
	public:
		void accept();
		void display();		
};

void Test::accept()
{
	cout<<"\n------------Enter Information--------------\n";
	cout<<"\n Enter Roll:\n";	
	cin>>roll;
	cout<<"\n Enter Name:\n";
	cin>>name;
	cout<<"\n Enter Marks:\n";
	cin>>marks;
}

void Test::display()
{
	cout<<"\n\t"<<roll<<"\t"<<name<<"\t"<<marks<<endl;
}

int main()
{
	ofstream out;
	Test t[10];
	int n,i;
	out.open("stud.txt",ios::binary);
	
	cout<<"\n How many Records you want to enter\n";
	cin>>n;

	for(i=0;i<n;i++)
	{
		t[i].accept();
		out.write((char*)&t[i],sizeof(t[i]));	
	}
	out.close();
	
	ifstream in;
	in.open("stud.txt",ios::binary);
	
	for(i=0;i<n;i++)
	{
		in.read((char*)&t[i],sizeof(t[i]));
		t[i].display();
	}
	in.close();
	return 0;
}

#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
class stud
{
	int adm_no;
	char name[20];
	int marks;
	public:
		void accept();
		void display();
		
		int get_ano()
		{
			return adm_no;
		}
		
};

void stud::accept()
{
	cout<<"\n -------------Enter Data-------------\n";
	cout<<"\n Enter Admission No:\n";
	cin>>adm_no;
	cout<<"\n Enter name:\n";
	cin>>name;
	cout<<"\n Enter Marks\n";
	cin>>marks;
}

void stud::display()
{
	cout<<"\n"<<adm_no<<"\t"<<name<<"\t"<<marks<<endl;
}

void create()
{
	int n,i;
	stud s;
	ofstream out;
	cout<<"\n How many enties you want to add\n";
	cin>>n;
	out.open("stud.txt",ios::binary);
	for(i=0;i<n;i++)
	{
		s.accept();
		out.write((char*)&s,sizeof(s));
	}
	out.close();	
}

void display()
{
	ifstream  in;
	stud s;
	in.open("stud.txt",ios::binary);
	cout<<"\nAD.NO"<<"\t"<<"Name"<<"\t"<<"Marks"<<"\n";
	while(in.read((char*)&s,sizeof(s)))
	{
		s.display();
	}
	in.close();
}

void insert()
{
	stud s;
	ofstream out;
	out.open("stud.txt",ios::binary|ios::app);
	s.accept();
	out.write((char*)&s,sizeof(s));
	out.close();
	cout<<"\n Insertion Done Successfully...\n";
}

void search()
{
	int ano,flag=0;
	ifstream in;
	stud s;
	in.open("stud.txt",ios::binary);
	cout<<"\n Enter the Admission no that you want to search\n";
	cin>>ano;
	
	while(in.read((char*)&s,sizeof(s)))
	{
		if(ano==s.get_ano())
		{
			flag=1;
			cout<<"\n Record is found....\n";
			s.display();
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\n Record Not Found\n";
	}
	in.close();
}

void modify()
{
	int ano,flag=0;
	ifstream in;
	ofstream out;
	stud s;
	in.open("stud.txt",ios::binary);
	out.open("temp.txt",ios::binary);
	cout<<"\n Enter the Admission no that you want to Modify\n";
	cin>>ano;

	while(in.read((char*)&s,sizeof(s)))
	{
		if(ano==s.get_ano())
		{
			flag=1;
			s.accept();
			out.write((char*)&s,sizeof(s));
		}
		else
		{
			out.write((char*)&s,sizeof(s));
		}
	}
	
	rename("temp.txt","stud.txt");
	//remove()
	in.close();
	out.close();
	
	if(flag==0)
	{
		cout<<"\n Record Not Found\n";
	}
	
}

void delete1()
{
	int ano,flag=0;
	ifstream in;
	ofstream out;
	stud s;
	in.open("stud.txt",ios::binary);
	out.open("temp.txt",ios::binary);
	cout<<"\n Enter the Admission no that you want to Delete\n";
	cin>>ano;

	while(in.read((char*)&s,sizeof(s)))
	{
		if(ano==s.get_ano())
		{
			flag=1;
			continue;
		}
		else
		{
			out.write((char*)&s,sizeof(s));
		}
	}
	if(flag==0)
	{
		cout<<"\n Record Not Found\n";
	}
	rename("temp.txt","stud.txt");
	//remove()
	in.close();
	out.close();
}
int main()
{
	int ch;
	do
	{
		cout<<"\n 1.Create \n 2.Display \n 3.Insert \n 4.Search \n 5.Modify \n 6.Delete \n 7.Exit\n";
		cout<<"\n Enter Your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				insert();
				break;
			case 4:
				search();
				break;
			case 5:
				modify();
				break;
			case 6:
				delete1();
				break;
			case 7:
				exit(0);
		}
	}while(ch!=7);
	return 0;
}

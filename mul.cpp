/*
	 Design a base class with name, date of birth, blood group and another base class consisting of the data members such as height and weight. Design one more base class consisting of the insurance policy number and contact address. The derived class contains the data members’ telephone numbers and driving license number.  Write a menu driven program to carry out the following things: 
i. Build a master table          ii. Display               
iii. Insert a new entry  iv. Delete entry  v.  Edit  
vi. Search for a record 5
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
using namespace std;
class general
{
	protected:
		char name[10],bl[10];
		char dob[20];
	public:
		general()
		{
			strcpy(name,"");
			strcpy(dob,"");
			strcpy(bl,"");
			
		}
		general(char n[10],char b[10],char db[20])
		{
			strcpy(name,n);
			strcpy(bl,b);
			strcpy(dob,db);
			
		}
		
		void  g_accept()
		{

			cout<<"\n---------------Enter Data----------\n";
			cout<<"\n Enter the name:\n";
			cin>>name;
			cout<<"\n Enter the dob:\n";
			cin>>dob;
			cout<<"\n Enter the blood group:\n";
			cin>>bl;
		}
	
		void g_display()
		{
			cout<<"\n"<<name<<"\t"<<dob<<"\t"<<bl;
		}

};

class  ht_wt
{
	protected:
		int ht,wt;
	public:
		ht_wt()
		{
			ht=0;
			wt=0;
		}
		ht_wt(int h,int w)
		{
			ht=h;
			wt=w;
		}
		void hw_accept()
		{
			cout<<"\n Enter the height:\n ";
			cin>>ht;
			cout<<"\n Enter the weight\n";
			cin>>wt;
		}
		void hw_display()
		{
			cout<<"\t"<<ht<<"\t"<<wt;
		}
};


class more_details
{
	protected:
		int  ins_no;
		char addr[20];
	public:
		more_details()
		{
			strcpy(addr,"");
			ins_no=0;
		}
		more_details(int i,char a[20])
		{
			ins_no=i;
			strcpy(addr,a);
		}
	
		void m_accept()
		{
			cout<<"\n Enter Insurance No:\n";
			cin>>ins_no;
			cout<<"\n Enter the Address::\n";
			cin>>addr;
		}
		void m_display()
		{
			cout<<"\t"<<ins_no<<"\t"<<addr;
		}
};


class master_list:public general,public ht_wt,public more_details
{
	int tel_no;	
	int lis_no;
	static int count;
	public:
		master_list()
		{
			tel_no=0;
			lis_no=0;	
		}
		master_list(int t,int l)
		{
			tel_no=t;
			lis_no=l;
		}

		void accept()
		{
			g_accept();
			hw_accept();
			m_accept();
			cout<<"\n Enter  the Telephone no:";
			cin>>tel_no;
			cout<<"\n Enter the Lisen no:\n";
			cin>>lis_no;
		}
		
		void display()
		{
			g_display();
			hw_display();
			m_display();
			cout<<"\t"<<tel_no<<"\t"<<lis_no<<"\n";	
		}

		void i_count()
		{
			count++;
		}

		static int get_count()
		{
			return count;
		}
		int get_lno()
		{
			return lis_no;
		}

		void count_de()
		{
			count--;
		}

		void change_nm(int h,int w,int t)
		{
			ht=h;
			wt=w;
			tel_no=t;
		}	
		void change_str(char n[20],char d[20],char b[20])
		{
			strcpy(name,n);
			strcpy(dob,d);
			strcpy(bl,b);
		}		
};

int master_list ::count=0;
int search(master_list  m [10],int  l)
{
	int x,i;			
	for(i=0;i<master_list::get_count();i++)
	{
		if(l==m[i].get_lno())
		{
			return i;
			break;
		}
		else
		{
			continue;
		}
	
	}
		return -1;			
}

void modify(master_list m[20],int x)
{
	int h,w,tno;
	char bg[20],d[20],n[20];
	cout<<"\n Enter the name:\n";
	cin>>n;
	cout<<"\n Enter Date  of  Birth:\n";
	cin>>d;
	cout<<"\n Enter the Blood_group:\n";
	cin>>bg;
	cout<<"\n Enter the Height:\n";
	cin>>h;
	cout<<"\n Enter the width:\n";
	cin>>w;
	cout<<"\nEnter the Telephone no:\n";
	cin>>tno;

	m[x].change_nm(h,w,tno);
	m[x].change_str(n,d,bg);
}

int main()
{
	int i,n,ch;
	master_list m[10];

	do
	{
		cout<<"\n 1.Create \n 2.Display \n 3.Insert \n 4.Search \n 5.Delete \n 6.Modify \n 7.Exit\n";
		cout<<"\n Enter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"\n How many Entries you want to add\n";
				cin>>n;
				for(i=0;i<n;i++)
				{				
					m[i].accept();
					m[i].i_count();
				}
				break;
			case 2:
				cout<<"\n Name\tDOB\tB.G\tHT\tWt\tINS.no\tAddr\tTel.no\tLIC.no\n";
				cout<<"\n------------------------------------------------------------------------------\n";
				for(i=0;i<master_list::get_count();i++)
				{
					m[i].display();
				}
				break;
			case 3:
				int c;
				c=master_list::get_count();
				m[c].accept();
				m[c].i_count();
				cout<<"\n Record Added Successfully\n";				
				break;
			case 4:
				int lno;
				cout<<"\n Enter  the  Listen_no That  you want to search\n";
				cin>>lno;
				int x;
				x=search(m,lno);
				if(x!=-1)
				{
					cout<<"\n Record  is Found\n";
					m[x].display();
				}
				else
				{
					cout<<"\n Not Found\n";
				}
				break;
			case  5:
				
				cout<<"\n Enter  the  Listen_no That  you want to Delete\n";
				cin>>lno;
				
				x=search(m,lno);
				if(x!=-1)
				{
					
					for(i=x;i<master_list::get_count();i++)
					{
						m[i]=m[i+1];
					}
					m[i].count_de();
					cout<<"\n Deletion Done Successfully\n";
				}
				else
				{
					cout<<"\n Not Found\n";
				}
				break;
			case  6:
				cout<<"\n Enter  the  Listen_no That  you want to Modify\n";
				cin>>lno;
				
				x=search(m,lno);
				if(x!=-1)
				{
					modify(m,x);
					cout<<"\n Modification Done Successfully\n";
				}
				else
				{
					cout<<"\n Not Found\n";
				}
				break;
				
			case 7:
				exit(0);
			default:
				cout<<"\n Please Enter Correct choice\n";
		}	
	}while(ch!=7);
	
	return 0;	
}

/*
 A Book shop maintains the inventory of books that are being sold at the shop. The list includes details such as title, author, publisher, priceand available stock. Write a program in C++ which will have a class called books with suitable member functions for i. Add ii. Update iii. Search a book iv. Purchase a book (update the stock and display the total cost) v. Record number of successful/unsuccessful transactions (use static data members to keep count of transactions) Use new operator in constructors to allocate memory space required.
*/
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
class Book
{
	static int copies;
	char *title,*author,*publisher;
	int price,stock;
	
	public:
		void accept();
		void display();
		int search(char bsearch[10]);
		void purchase(int c);
		void update();
		static int showcopies();
		
		
		Book()
		{
			price=0;
			stock=0;
			title=new char[20];
			author=new char[20];
			publisher=new char[20];
			strcpy(title,"");
			strcpy(author,"");
			strcpy(publisher,"");
		}
		~Book()
		{
			delete title;
			delete author;
			delete publisher;
		}
};
int Book::copies;
int Book::showcopies()
{
	return copies;
} 		
void Book::accept()
{
	cout<<"\n-----Enter Information For Bookshop--------\n\n";
	cout<<"\n Enter Title:\n";
	cin>>title;
	cout<<"\n Enter Author:\n";
	cin>>author;
	cout<<"\n Enter Publisher :\n";
	cin>>publisher;
	cout<<"\n Enter Stock:\n";
	cin>>stock;
	cout<<"\n Enter price:\n";
	cin>>price;
	
	copies=copies+stock;
	
}

void Book::display()
{
	cout<<"\n\t"<<title<<"\t"<<author<<"\t"<<publisher<<"\t"<<stock<<"\t"<<stock*price<<"\n";
}

int Book::search(char bsearch[10])
{
	if(strcmp(bsearch,title)==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void Book::purchase(int c)
{
	stock=stock-c;
	copies=copies-c;
	
	cout<<"\n Total Amount to be paid is "<<c<<"(copies)"<<"*"<<"(price)"<<(price)<<"="<<c*price;
		

}

void Book::update()
{
	int m;
	cout<<"\n Enter Title:\n";
	cin>>title;
	cout<<"\n Enter Author:\n";
	cin>>author;
	cout<<"\n Enter Publisher :\n";
	cin>>publisher;
	m=stock;
	cout<<"\n Enter Stock:\n";
	cin>>stock;
	cout<<"\n Enter price:\n";
	cin>>price;
	
	copies=copies-m;
	copies=copies+stock;
}
int main()
{
	Book *b[10];
	int n=0,ch,i,ans,flag=0,c;
	char bsearch[10];
	do
	{
		cout<<"\n\n\n 1.Add \n 2.Display \n 3.Search \n 4.Purchase \n 5.Modify \n 6.Exit\n";
		cout<<"\n Enter Your Choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				b[n]=new Book;			
				b[n]->accept();
				n++;
				break;
			case 2:
				cout<<"\n\tTitle\tAuthor\tPublisher\tStock\tPrice\n";
				cout<<"\n----------------------------------------------------\n";
				for(i=0;i<n;i++)
				{
					b[i]->display();
				}
				cout<<"\n\nTotal Copies:\n"<<Book::showcopies();
				break;
			case 3:
				cout<<"\n Enter the Title of Book that you want to search\n";
				cin>>bsearch;
				for(i=0;i<n;i++)
				{
					flag=0;
					ans=b[i]->search(bsearch);
					if(ans==1)
					{
						flag=1;
						break;
					}	
				}
				
				if(flag==1)
				{
					cout<<"\n Book is Present\n";
				}
				else
				{
					cout<<"\n Not Present\n";
				}
				break;
			case 4:
				cout<<"\n Enter the Title of Book that you want to purchase\n";
				cin>>bsearch;
				for(i=0;i<n;i++)
				{
					flag=0;
					ans=b[i]->search(bsearch);
					if(ans==1)
					{
						flag=1;
						cout<<"\n Enter the no of Copies\n";
						cin>>c;
						b[i]->purchase(c);
						cout<<"\n Total Stock is Aailable:"<<Book::showcopies();
						break;
					}	
				}
				if(flag==0)
				{
					cout<<"\n Record  Not Found\n";
				}
				break;
			case 5:
				cout<<"\n Enter the Title of Book that you want to update\n";
				cin>>bsearch;
				for(i=0;i<n;i++)
				{
					flag=0;
					ans=b[i]->search(bsearch);
					if(ans==1)
					{
						flag=1;
						b[i]->update();
						cout<<"\n Updation Done Successfully";
						break;
					}	
				}
				if(flag==0)
				{
					cout<<"\n Record  Not Found\n";
				}
				break;
			case 6:
				exit(0);
			default:
				cout<<"\n Please Enter Correct choice\n";
						
		}
	}while(ch!=6);
	return 0;
}



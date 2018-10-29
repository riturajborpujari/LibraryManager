#include <iostream>
#include <vector>

#include "recordsmanager.h"
#include "book.h"

using namespace std;

int main()
{
	BOOK book;
	RECORDS_MANAGER library;
	vector<BOOK> bookList;
	unsigned long int id = -1;

	int choice =0;
	while(choice!= -1)
	{
		cout<<"---------------------------------------------------------------"<<endl;
		cout<<"1(Add), 2(Delete), 3(view all), -1(exit)...Enter your choice...";
		cin>>choice;
		
		fflush(stdin);
		switch(choice)
		{
		case 1:
			cout<< "Enter the name of the book...";
			cin.getline(book.name, 60);
			cout<< "Enter the author of the book...";
			cin.getline(book.author, 30);
		
			library.AddBook(&book);
			break;
		case 2:
			cout<<"Enter id of the book to be deleted...";
			cin>>id;
			cout<<library.DeleteBook(id);
			break;
		case 3:
			library.GetAllBooks(&bookList);
			
			for(vector<BOOK>::iterator it = bookList.begin(); it !=bookList.end(); it++)
			{
				book = *(it);
				cout<<"Name\t: "<<book.name<<"\tAuthor\t: "<<book.author<<" with id : "<<book.id<<endl;
			}
			//bookList.clear();
			break;
		}
	}

	return 0;
}

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

	int choice = 0;
	while (choice != -1)
	{
		cout << "---------------------------------------------------------------" << endl;
		cout << "1. Add\n2. Delete\n3. View all\n4. Exit\nEnter your choice...";
		cin >> choice;

		fflush(stdin);
		switch (choice)
		{
		case 1:
			cout << "Enter the name of the book...";
			cin.getline(book.name, 60);
			cout << "Enter the author of the book...";
			cin.getline(book.author, 30);

			library.AddBook(&book);
			break;
		case 2:
			cout << "Enter id of the book to be deleted...";
			cin >> id;
			cout << library.DeleteBook(id);
			break;
		case 3:
			cout << "------------------------------------" << endl;
			cout << "All Books" << endl;
			cout << "------------------------------------" << endl;

			library.GetAllBooks(&bookList);
			for (auto book : bookList)
			{
				cout << "Name\t: " << book.name << "\nAuthor\t: " << book.author << "\nID\t: " << book.id << endl;
				cout << "------------------------------------\n";
			}
			break;
		default:
			cout << "Exiting..." << endl;
			choice = -1;
			break;
		}
	}

	return 0;
}

#include <iostream>
#include "book.h"
#include "filehandler.h"

using namespace std;

int main()
{
	BOOK book;

	cout<< "Enter the name of the book...";
	cin.getline(book.name, 60);
	cout<< "Enter the author of the book...";
	cin.getline(book.author, 30);
	book.id = 1;

	// write the book data to the file
	FILE_HANDLER file = FILE_HANDLER("data.bin");
	file.Write((char*)&book, sizeof(BOOK));

	BOOK r;
	// read the book back from file
	file.Read((char*)&r, sizeof(BOOK));
	cout<< r.name << ", " << r.author;

	fflush(stdin);
	cin.get();

	return 0;
}

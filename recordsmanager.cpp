#include "recordsmanager.h"

#include <iostream>

using namespace std;

RECORDS_MANAGER::RECORDS_MANAGER()
{
	// try to open the records file in read mode
	file.open("bookrecords.bin", ios::in | ios::out | ios::binary);
	if(!file.is_open())
	{
		// file not yet created
		// open the file in write mode, which creates a new file if file is
		// not present
		file.open("bookrecords.bin", ios::out | ios::binary);
		file.close();

		// close the file and open it again for enabling both read and write access
		file.open("bookrecords.bin", ios::in | ios::out | ios::binary);
	}

	// go to the end of the file 
	file.seekg(0, ios::end);
	file.seekp(0, ios::beg);
	
	// if end of file is same as begining then there is no book present
	if(file.tellg() == file.tellp())
		lastId = 0;

	// else initialize lastId with the id of the last book in the record
	else
	{
		// come backwards in records file from end by the size of one book record
		int bookSize = sizeof(BOOK);
		file.seekg(-bookSize, ios::end);
		BOOK b;

		// read the last book to get it's id
		file.read((char*)&b, sizeof(BOOK));
		lastId = b.id;
	}
	file.close();
}

RECORDS_MANAGER::~RECORDS_MANAGER()
{
}

void RECORDS_MANAGER::AddBook(BOOK* book)
{
	file.open("bookrecords.bin", ios::out | ios::binary | ios::app);
	
	// go to the end of the record file
	file.seekp(0, ios::end);
	
	// id's of book is incremented everytime. 
	book->id = (++lastId);
	file.write((char*)book, sizeof(BOOK));
	
	file.close();
}

bool RECORDS_MANAGER::DeleteBook(unsigned long int id)
{
	file.open("bookrecords.bin", ios::in | ios::binary);
	bool found = false;
	// create a temporary file and copy the contents of the records file
	//  book by book but skipping the book with id matching the id given as
	//  paraeter to this function.
	ofstream temp;
	temp.open("temp.data",ios::out | ios::binary );

	temp.seekp(0, ios::beg);
	
	BOOK t;
	file.seekg(0, ios::beg);
	unsigned long int tId = -1;
	while(!file.eof())
	{
		file.read((char*)&t, sizeof(BOOK));
		if(file.good())
		{
			// if the current book's id does not match the id of the book 
			// to be deleted, then copy that book record to temp file
			if(t.id != id)
			{
				temp.write((char*)&t, sizeof(BOOK));
				tId = t.id;
			}
			else
				found = true; // book to be deleted is found, skipping copy
		}
	}
	temp.close();
	file.close();
	remove("bookrecords.bin");
	rename("temp.data", "bookrecords.bin");
	
	file.open("bookrecords.bin", ios::in | ios::out | ios::binary);
	lastId = tId;
	
	file.close();
	return found;

}


void RECORDS_MANAGER::GetAllBooks(vector<BOOK>* _out_books)
{
	file.open("bookrecords.bin", ios::in | ios::binary);
	file.seekg(0, ios::beg);	// go to the start of the file
	_out_books->clear();

	// read the contents of the record file book by book while adding them to the 
	// list _out_books
	BOOK temp;
	while(1)
	{
		file.read((char*)&temp, sizeof(BOOK));

		// if read operation was successful, add the book to the list
		if(file.good())	
			_out_books->push_back(temp);
		else
			break;
	}
	file.close();
}

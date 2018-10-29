//////////////////////////////////////////////////////////////////////////////////////////////////
// File		: recordsmanager.h								//
// Author	: Rituraj Borpujari								//
//////////////////////////////////////////////////////////////////////////////////////////////////
// Desc		: Prototypes RECORDS_MANAGER class. It provides functions to 			//
// 			Add, Delete and View books						//
// 		  The parameter to GetAllBooks() should ideally be an empty vector to hold	//
// 		  BOOK objects. The function will populate it with the books present in the 	//
// 		  library.									//
//////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __RECORDS_MANAGER__H__
#define __RECORDS_MANAGER__H__

#include <fstream>
#include <vector>
#include "book.h"


class RECORDS_MANAGER
{
private:
	std::fstream file;
	unsigned long int lastId;	// the unique id of the last book present in the library
public:
	RECORDS_MANAGER();
	~RECORDS_MANAGER();

	void AddBook(BOOK* book);
	bool DeleteBook(unsigned long int id);
	
	void GetAllBooks(std::vector<BOOK>* _out_books);
};

#endif

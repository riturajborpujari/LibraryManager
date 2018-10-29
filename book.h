//////////////////////////////////////////////////////////////////////////////////////////
// File		: book.h								//
// Author	: Rituraj Borpujari							//
// Desc		: contains the structure for keeping details of a book.			// 
// 		   serves as a model for LibraryManager					//
//////////////////////////////////////////////////////////////////////////////////////////

#ifndef __BOOK__H__
#define __BOOK__H__

struct BOOK
{
	unsigned long int id;		// a unique id for each book
	char name[60];
	char author[30];
};

#endif

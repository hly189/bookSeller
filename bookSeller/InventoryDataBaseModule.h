#ifndef InventoryDataBaseModule_h
#define InventoryDataBaseModule_h

#include<string>
#include<iostream>
#include "BookInfo.h"


class InventoryDataBaseModule {
public: 
	// Object pointer which will contains all the BookInfo Object
	BookInfo *bookList; 

private: 
	InventoryDataBaseModule(); 
	InventoryDataBaseModule(BookInfo *list);

	// Function to get all the book Info
	void getAllBookInfo(); 

	// Function to look up book by ISBN
	BookInfo bookLookUpByISBN(string isbn); 
	
	// Function to look up book by author
	BookInfo bookLookUpByAuthor(string author); 

	// Function to look up book by title 
	BookInfo bookLoopUpByTitle(string titile); 

};
#endif

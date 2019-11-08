#ifndef InventoryDataBaseModule_h
#define InventoryDataBaseModule_h

#include<string>
#include<iostream>
#include "BookInfo.h"


class InventoryDataBaseModule {
private:
	// Object pointer which will contains all the BookInfo Object
	BookInfo* bookList; 
	int bookListSize; 
public: 
	InventoryDataBaseModule(); 
	InventoryDataBaseModule(BookInfo list[], int size);

	// Function to get pointer
	BookInfo * getBookListPointer(); 

	// Function to get Inventory Size
	int getInventorySize();

	// Function to get all the book Info
	void getAllBookInfo(); 

	// Function to look up book by ISBN
	void bookLookUpByISBN(string isbn); 
	
	// Function to look up book by author
	void bookLookUpByAuthor(string author); 

	// Function to look up book by title 
	void bookLoopUpByTitle(string titile); 

	// Function to look up book by publisher
	void bookLookUpByPublisher(string publiser); 

	// Function to edit book information 
	void bookEdit(); 

	// Function to add new book
	void addNewBook(BookInfo newBook); 

};
#endif

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

	// Function to look up book by ISBN
	int bookLookUpByISBN(string isbn); 
	
	// Function to show loop up result by ISBN
	void showLookUpByISBN(string isbn);

	// Function to look up book by author
	void bookLookUpByAuthor(string author); 

	// Function to look up book by title 
	int bookLoopUpByTitle(string titile); 

	// Function to show look up result by title 
	void showLookUpByTitle(string title); 

	// Function to look up book by publisher
	int bookLookUpByPublisher(string publiser); 

	// Function to edit book information 
	void bookEdit(); 

	// Function to add new book
	void addNewBook(BookInfo newBook); 

	// Function to delete book object by position 
	void deleteBookObjectFromInventory(int position); 

	// Function to show remove Screen and remove book
	void removeBook(string removeInfo);

	// show Section of each Field 
	void showBookField();
};
#endif

#ifndef InventoryDataBaseModule_h
#define InventoryDataBaseModule_h

#include<string>
#include<iostream>
#include <iomanip>
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

	// Function to look up position in array of book by ISBN or Author
	int bookLookUpByISBNTitle(string lookupInfo, int option); 

	// Function to show look up result by title 
	void showLookUpByISBNTitle(string lookUpInfo, int option);

	// Function to look up book by publisher
	void bookLookUpByPublisherOrAuthor(string publiser, int option); 

	// Function to look up book by Date Added or Quantity
	void bookLoopUpByMonthDayYearQuantity(int lookupInfo, int option);

	// Function to look up by whole sale cost or retail price
	void bookLookUpByWholeSaleOrRetailPrice(double priceLookUp, int option);

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

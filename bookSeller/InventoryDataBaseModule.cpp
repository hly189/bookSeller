#include<string>
#include<iostream>
#include <iterator>
#include "pch.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"

using namespace std; 

//Default constructor 
InventoryDataBaseModule::InventoryDataBaseModule() {}

InventoryDataBaseModule::InventoryDataBaseModule(BookInfo list[], int size) {
	// Asign array list[] to pointer *bookList
	bookList = list; 
	bookListSize = size; 
}

// Function to return bookList pointer
BookInfo* InventoryDataBaseModule::getBookListPointer() {
	// since *bookList is private, this function will return it, so it can be accessible
	return bookList; 
}

// Function to get size of Inventory
int InventoryDataBaseModule::getInventorySize() {
	return bookListSize; 
}

// Function to show all the book info: 
void InventoryDataBaseModule::getAllBookInfo() {

	// Loop through the bookList and get infomation of each book by calling 
	// method getBookInfo() in BookInfo class
	for (int i = 0; i < bookListSize; i++) {
		bookList[i].getBookInfo(); 
	}
}

// Function to add new Book to Inventory
void InventoryDataBaseModule::addNewBook(BookInfo newbook) {
	// get the current size of inventory
	int currentSizeInventory = getInventorySize();

	// update the size of the inventory 
	bookListSize++; 

	// Create a new temp pointer array to reallocate new size
	BookInfo *newTempInventoryList = new BookInfo[currentSizeInventory + 1]; 

	// Start copying from bookList to new temp pointer
	for (int i = 0; i < currentSizeInventory; i++) {
		newTempInventoryList[i] = bookList[i]; 
	}
	// Add new book to the last element of the temp pointer
	newTempInventoryList[currentSizeInventory] = newbook; 

	// Copy from new temp pointer to origial list
	bookList = newTempInventoryList; 
}

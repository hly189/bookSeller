#include<string>
#include<iostream>
#include<iomanip>
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

// Function to look up book by ISBN 
int InventoryDataBaseModule::bookLookUpByISBN(string isbn) {
	// position of element which is founded. Default is -1 meaning there is no book 
	// with given  isbn number
	int foundPosition = -1; 

	// Loop through the list to look for book with given isbn
	for (int i = 0; i < bookListSize; i++) {
		string currentISBN = bookList[i].getBookIsbn(); 
		if (currentISBN == isbn) {
			foundPosition = i; 
			break; 
		}
	}
	return foundPosition; 
}

// Function to show loop up result by ISBN
void InventoryDataBaseModule::showLookUpByISBN(string isbn) {

	// Search position of the book in array bookList by 
	// calling bookLookUpByISBN function
	int bookPosition = bookLookUpByISBN(isbn); 

	// If no found then return and let user knows
	if (bookPosition < 0) {
		cout << "No Book with ISBN " << isbn << " found." << endl; 
		return; 
	}

	// Otherwise show search result
	bookList[bookPosition].getBookInfo(); 
}


// Function to look up book by title 
int InventoryDataBaseModule::bookLoopUpByTitle(string title) {
	// position of element which is founded. Default is -1 meaning there is no book 
	// with given  title
	int foundPosition = -1;

	// Loop through the list to look for book with given title
	for (int i = 0; i < bookListSize; i++) {
		string currentTitle = bookList[i].getBookTitle();
		if (currentTitle == title) {
			foundPosition = i;
			break;
		}
	}
	return foundPosition;
}

// Function to show look up result by title
void InventoryDataBaseModule::showLookUpByTitle(string title) {
	// Search position of the book in array bookList by 
	// calling bookLoopUpByTitle function
	int bookPosition = bookLoopUpByTitle(title); 

	// If no found the exit function and let user knows 
	if (bookPosition < 0) {
		cout << "No Book with title " << title << " found." << endl;
		return;
	}

	// Otherwise show search result
	bookList[bookPosition].getBookInfo(); 
}

// Function to look up book by author
void InventoryDataBaseModule::bookLookUpByAuthor(string author) {
	// Get inventory Size
	int currentSize = getInventorySize(); 

	// Marker for found author 
	bool authorMarker = false; 
	// Loop through Inventory to look for book(s)
	// with given author
	for (int i = 0; i < currentSize; i++) {
		string currentAuthor = bookList[i].getBookAuthor(); 
		// If author is found, then show book info
		// and change marker to true
		if (currentAuthor == author) {
			if (authorMarker == false) {
				bookList[i].showBookField();
			}
			bookList[i].getBookInfo(); 
			authorMarker = true; 
		}
	}

	// if no author is found, meaning authorMarker is still false
	// then let user know and exit functino 
	if (authorMarker == false) {
		cout << "No " << author << " found in Inventory" << endl; 
		return; 
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

	// Start copying from bookList to new temp array
	for (int i = 0; i < currentSizeInventory; i++) {
		newTempInventoryList[i] = bookList[i]; 
	}
	// Add new book to the last element of the temp arrat
	newTempInventoryList[currentSizeInventory] = newbook; 

	// Copy from new temp array to origial list
	bookList = newTempInventoryList; 
}

// Function to delete book object by position
void InventoryDataBaseModule::deleteBookObjectFromInventory(int position) {
	// get the current size of inventory 
	int currentSizeInventory = getInventorySize(); 

	// Create temp inventory array with size less than current size of inventory by 1 
	BookInfo *newTempInvetoryList = new BookInfo[currentSizeInventory - 1]; 

	// Update new size for inventory 
	bookListSize--; 

	// Copy element from position to end from bookList array to temp array 
	for (int i = position; i < bookListSize; i++) {
		newTempInvetoryList[i] = bookList[i + 1]; 
	}

	// Copy element from 0 to position from bookList array to temp array 
	for (int i = 0; i < position; i++) {
		newTempInvetoryList[i] = bookList[i]; 
	}

	// Copy from new temp array to original list 
	bookList = newTempInvetoryList; 
}

// Function to show remove Screen and remove book
void InventoryDataBaseModule::removeBook(string removeInfo) {
	int removePosition; 

	// Start searching on given input information
	// Start looking by ISBN first
	removePosition = bookLookUpByISBN(removeInfo); 
	if (removePosition < 0) {
		// Continue looking by Title if ISBN not found
		removePosition = bookLoopUpByTitle(removeInfo); 
		// If not found then exit function 
		if (removePosition < 0) {
			cout << "No " << removeInfo << " is found" << endl;
			return; 
		}
	}
	// Remove book out of inventory by calling function deleteBookObject
	deleteBookObjectFromInventory(removePosition);

	cout << "Removed " << removeInfo << " out of Inventory" << endl;
	cout << "Total Title(s) in Inventory: " << getInventorySize() << endl;
	cout << endl; 


}

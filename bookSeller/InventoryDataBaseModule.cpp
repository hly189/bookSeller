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


// Function to look up position of book in array by ISBN Number or Title
int InventoryDataBaseModule::bookLookUpByISBNTitle(string lookUpInfo, int option) {
	// option 1 is looking by ISBN
	// option 2 is looking by title 

	// position of element which is founded. Default is -1 meaning there is no book 
	// with given  information
	int foundPosition = -1; 

	// get size of current Inventory 
	int currentSize = getInventorySize(); 

	// get copy of BookList Array 
	BookInfo* tempInventoryArray = getBookListPointer(); 

	// Loop through the list to look for book with given isbn
	for (int i = 0; i < currentSize; i++) {
		string currenInfo;
		if (option == 1) {
			currenInfo = tempInventoryArray[i].getBookIsbn(); 
		}else {
			currenInfo = tempInventoryArray[i].getBookTitle();
		}
		if (currenInfo == lookUpInfo) {
			foundPosition = i; 
			break;
		}
	}
	return foundPosition;

}


// Function to show loop up result by ISBN or Title
void InventoryDataBaseModule::showLookUpByISBNTitle(string lookUpInfo, int option) {

	// Search position of the book in array bookList by 
	// calling bookLookUpByISBNTitle function
	int bookPosition = bookLookUpByISBNTitle(lookUpInfo, option);

	// If no found then return and let user knows
	if (bookPosition < 0) {
		cout << "No Book with Information " << lookUpInfo << " found." << endl; 
		return; 
	}

	// Otherwise show search result
	bookList[bookPosition].showBookField();
	bookList[bookPosition].getBookInfo(); 
}


// Function to look up book by author or publisher
void InventoryDataBaseModule::bookLookUpByPublisherOrAuthor(string lookUpInfo, int option) {
	//option 1 is looking up by publisher
	//option 2 is look up by author
	
	// Get inventory Size
	int currentSize = getInventorySize(); 

	// Get copy of Inventory 
	BookInfo* tempInventoryArray = getBookListPointer();

	// Marker for found author 
	bool marker = false; 
	// Loop through Inventory to look for book(s)
	// with given author
	for (int i = 0; i < currentSize; i++) {
		string currentInfo; 
		if (option == 1) {
			currentInfo = tempInventoryArray[i].getBookPublisher();
		}else {
			currentInfo = tempInventoryArray[i].getBookAuthor();
		}
		// If author is found, then show book info
		// and change marker to true
		if (currentInfo == lookUpInfo) {
			if (marker == false) {
				tempInventoryArray[i].showBookField();
			}
			tempInventoryArray[i].getBookInfo();
			marker = true;
		}
	}

	// if no author or publisher is found, meaning marker is still false
	// then let user know and exit functino 
	if (marker == false) {
		cout << "No " << lookUpInfo << " found in Inventory" << endl;
		return; 
	}
}


// Function to look up book information by day, month, year or quantity
void  InventoryDataBaseModule::bookLoopUpByMonthDayYearQuantity(int lookupInfo, int option) {
	// Get inventory Size
	int currentSize = getInventorySize();

	// Marker for found day 
	bool marker = false;
	// Loop through Inventory to look for book(s)
	// with given day, month or year
	// option 1 is searching by day
	// option 2 is searching by month 
	// option 3 is searching by year
	// option 4 is searching by quantity
	for (int i = 0; i < currentSize; i++) {
		int currentDateInfo; 
		if (option == 1) {
			currentDateInfo = bookList[i].getBookDay(); 
		}
		else if (option == 2) {
			currentDateInfo = bookList[i].getBookMonth(); 
		}
		else if (option == 3) {
			currentDateInfo = bookList[i].getBookYear();
		}
		else {
			currentDateInfo = bookList[i].getBookQuantity();
		}
		// If day is found, then show book info
		// and change marker to true
		if (currentDateInfo == lookupInfo) {
			if (marker == false) {
				bookList[i].showBookField();
			}
			bookList[i].getBookInfo();
			marker = true;
		}
	}

	// if no day is found, meaning dayMarker is still false
	// then let user know and exit functino 
	if (marker == false) {
		cout << "No " << lookupInfo << " found in Inventory" << endl;
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
	removePosition = bookLookUpByISBNTitle(removeInfo,1);
	if (removePosition < 0) {
		// Continue looking by Title if ISBN not found
		removePosition = bookLookUpByISBNTitle(removeInfo,2);
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

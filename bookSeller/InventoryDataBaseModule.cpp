#include<string>
#include<iostream>
#include<iomanip>
#include "pch.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "RunningModule.h"

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
	BookInfo* tempBookList = new BookInfo[getInventorySize()]; 
	tempBookList = bookList;
	return tempBookList; 
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
	showBookField();
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
				showBookField();
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
				showBookField();
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

// Function to look up book by whole sale cost or retail price
void InventoryDataBaseModule::bookLookUpByWholeSaleOrRetailPrice(double priceLookUp, int option) {
	// option 1 look up by whole sale cost
	// option 2 look up by retail price 
	
	// Get inventory Size
	int currentSize = getInventorySize();

	// Get copy of bookList
	BookInfo *tempInventory = getBookListPointer(); 

	// Marker for found day 
	bool marker = false;

	for (int i = 0; i < currentSize; i++) {
		double currentPiceInfo;
		if (option == 1) {
			currentPiceInfo = tempInventory[i].getBookWholeSaleCost();
		}
		else {
			currentPiceInfo = tempInventory[i].getBookRetailPrice();
		}
		// If price is found, then show book info
		// and change marker to true
		if (currentPiceInfo == priceLookUp) {
			if (marker == false) {
				showBookField();
			}
			tempInventory[i].getBookInfo();
			marker = true;
		}
	}

	// if no price is found, meaning dayMarker is still false
	// then let user know and exit functino 
	if (marker == false) {
		cout << "No Price " << priceLookUp << " found in Inventory" << endl;
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

// Function to edit book information
void InventoryDataBaseModule::bookEdit() {
	string bookInformation; 
	cout << "Please enter Book Title or ISBN Number: "; 
	getline(cin, bookInformation);

	// position of book in array 
	int bookPosition; 
	
	// Create copy of Inventory 
	BookInfo *tempInventory = getBookListPointer(); 

	//Start looking by ISBN first
	bookPosition = bookLookUpByISBNTitle(bookInformation, 1);
	// If no ISBN found, then countiue searching by title
	if (bookPosition < 0) {
		bookPosition = bookLookUpByISBNTitle(bookInformation, 2);
		// If no title found, let user know
		// and exit function. 
		if (bookPosition < 0) {
			cout << "No " << bookInformation << " found in Inventory" << endl;
			return;
		}
	}
	// Show Current Book Information 
	showBookField();
	tempInventory[bookPosition].getBookInfo();
	cout << endl; 
	// Asking which information user wants to edit
	string answer; 
	do {
			int option; 
			cout << "Which information do you want to edit" << endl;
			cout << "1. Title" << endl; 
			cout << "2. ISBN" << endl; 
			cout << "3. Author" << endl; 
			cout << "4. Publisher" << endl; 
			cout << "5. Quantity" << endl; 
			cout << "6. WHole Sale Cost" << endl; 
			cout << "7. Retail Price" << endl; 
			cout << "8. Day Added" << endl; 
			cout << "9. Month Added" << endl; 
			cout << "10. Year Added" << endl; 
			cout << "11. Exit Change" << endl; 
			cout << "Please choose from 1 - 11: "; 
			cin >> option; 
			cin.ignore(); 
			option = Utilities::correctingOption(option, 1, 11);

			// Start editing on book information
			if (option == 1) {
				string editTitle; 
				cout << "Please enter new Title: "; 
				getline(cin, editTitle); 
				tempInventory[bookPosition].setBookTitle(editTitle); 
			}
			else if (option == 2) {
				string editIsbn; 
				cout << "Please enter new ISBN: "; 
				getline(cin, editIsbn); 
				tempInventory[bookPosition].setBookIsbnNumber(editIsbn); 
			}
			else if (option == 3) {
				string editAuthor; 
				cout << "Please enter new Author: "; 
				getline(cin, editAuthor); 
				tempInventory[bookPosition].setBookAuthor(editAuthor);
			}
			else if (option == 4) {
				string editPublisher;
				cout << "Please enter new Publisher: ";
				getline(cin, editPublisher);
				tempInventory[bookPosition].setBookPublisher(editPublisher);
			}
			else if (option == 5) {
				int editQuantity;
				cout << "Please enter new Quantity: ";
				cin >> editQuantity; 
				cin.ignore(); 
				tempInventory[bookPosition].setBookQuantity(editQuantity);
			}
			else if (option == 6) {
				double editWholeSaleCost;
				cout << "Please enter new Whole Sale Cost: ";
				cin >> editWholeSaleCost;
				cin.ignore();
				tempInventory[bookPosition].setWholeSaleCost(editWholeSaleCost);
			}
			else if (option == 7) {
				double editRetailPrice;
				cout << "Please enter new Retail Price: ";
				cin >> editRetailPrice;
				cin.ignore();
				tempInventory[bookPosition].setBookRetailPrice(editRetailPrice);
			}
			else if (option == 8) {
				int editDay;
				cout << "Please enter new Day Added: ";
				cin >> editDay;
				cin.ignore();
				tempInventory[bookPosition].setBookDay(editDay);
			}
			else if (option == 9) {
				int editMonth;
				cout << "Please enter new Month Added: ";
				cin >> editMonth;
				cin.ignore();
				tempInventory[bookPosition].setBookMonth(editMonth);
			}
			else if (option == 10) {
				int editYear;
				cout << "Please enter new Year Added: ";
				cin >> editYear;
				cin.ignore();
				tempInventory[bookPosition].setBookYear(editYear);
			}
			else {
				break; 
			}
			cout << "Current Book Info: " << endl;
			showBookField();
			tempInventory[bookPosition].getBookInfo(); 
			cout << endl; 
			cout << "Do you want to continue editing ? y/n: "; 
			getline(cin, answer); 
		} while (answer != "n");
	cout << endl; 
	cout << "New Book Info " << endl; 
	showBookField();
	tempInventory[bookPosition].getBookInfo();

		// Copy temp Inventory List after editing to original inventory 
		bookList = tempInventory; 

		// Free memory since temp array is no longer used 
		//delete[] tempInventory; 
	}

void InventoryDataBaseModule::showBookField() {
	cout << left << setw(60) << "Title";
	cout << setw(25) << "Author";
	cout << setw(25) << "Publisher";
	cout << setw(25) << "ISBN Number";
	cout << setw(15) << "Quantity";
	cout << setw(15) << "Whole Sale";
	cout << setw(20) << "Retail Price";
	cout << setw(35) << "Date" << endl;
}


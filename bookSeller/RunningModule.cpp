#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "pch.h"
#include "RunningModule.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "ReportModule.h"

using namespace std;


// Default constructor
RunningModule::RunningModule() {}
RunningModule::RunningModule(InventoryDataBaseModule currentInventory, cashierModule cashierObject) {
	inventory = currentInventory;
	cashier = cashierObject; 
}

//Function to show main menu and choosing sub-menu
void RunningModule::mainMenu(){
	// Option to choose
	int option; 

	// Main menu 
	do {
		cout << "Book Store Menu" << endl;
		cout << "1. Inventory Menu." << endl;
		cout << "2. Report Menu." << endl;
		cout << "3. Cashier Menu." << endl;
		cout << "4. Exit." << endl;
		cout << "Please choose option 1 - 4: ";
		cin >> option;
		cout << endl; 
		option = Utilities::correctingOption(option, 1, 4);
		if (option == 1) {
			inventoryMenu();
		}
		else if (option == 2) {
			reportMenu(); 
		}
		else if (option == 3) {
			cashierMenu(); 
		}
	} while (option != 4);
}

// Inventory Menu
void RunningModule::inventoryMenu() {
	int option; 
	do {
		cout << "Inventory Menu:" << endl;
		cout << "1. Add new Book." << endl;
		cout << "2. Delete Book." << endl;
		cout << "3. Look up book by Title." << endl;
		cout << "4. Look up book by ISBN Number." << endl;
		cout << "5. Look up book(s) by Author." << endl;
		cout << "6. Look up book(s) by Publisher." << endl;
		cout << "7. Look up book(s) by Day Added." << endl;
		cout << "8. Look up book(s) by Month Added." << endl;
		cout << "9. Look up book(s) by Year Added." << endl;
		cout << "10. Look up book(s) by Quantity." << endl;
		cout << "11. Look up book(s) by Whole Sale Cost." << endl;
		cout << "12. Look up book(s) by Retail Price." << endl;
		cout << "13. Change book information." << endl;
		cout << "14. Exit Inventory" << endl; 
		cout << "Please choose option 1 - 14: ";
		cin >> option;
		cout << endl; 
		option = Utilities::correctingOption(option, 1, 14);
		cin.ignore(); 

		if (option == 1){
			// Gathering information of new book by calling addingBook() 
			// from BookInfo class
			BookInfo newBook = addingBook();
			// Adding new book to Inventory by calling addNewBook 
			// from InventoryDataBaseModule Class
			inventory.addNewBook(newBook);
			// Show current title in inventory and New Book Info
			cout << "Total Book(s) in Inventory: " << inventory.getInventorySize() << endl;
			cout << "New Book Info: " << endl; 
			inventory.showBookField(); 
			newBook.getBookInfo();
			cout << endl; 
		}
		else if (option == 2) {
			string removeInfo;
			cout << "Please enter ISBN Number or Titile of the Book: ";
			getline(cin, removeInfo);
			inventory.removeBook(removeInfo);
		}
		else if (option == 3) {
			string title;
			cout << "Please enter Title of the Book: ";
			getline(cin, title);
			inventory.showLookUpByISBNTitle(title,2);
			cout << endl;
		}
		else if (option == 4) {
			string isbn; 
			cout << "Please enter ISBN Number of the Book: "; 
			getline(cin, isbn); 
			inventory.showLookUpByISBNTitle(isbn,1);
			cout << endl;
		}
		else if (option == 5) {
			string author;
			cout << "Please enter Author's Name: ";
			getline(cin, author);
			inventory.bookLookUpByPublisherOrAuthor(author,2);
			cout << endl;
		}
		else if (option == 6) {
			string publisher;
			cout << "Please enter Publisher's Name: ";
			getline(cin, publisher);
			inventory.bookLookUpByPublisherOrAuthor(publisher, 1);
			cout << endl;
		}
		else if (option == 7) {
			int day;
			cout << "Please enter Day Added to Inventory: ";
			cin >> day; 
			cin.ignore(); 
			inventory.bookLoopUpByMonthDayYearQuantity(day,1);
			cout << endl;
		}
		else if (option == 8) {
			int month;
			cout << "Please enter Month Added to Inventory: ";
			cin >> month;
			cin.ignore();
			inventory.bookLoopUpByMonthDayYearQuantity(month,2);
			cout << endl;
		}
		else if (option == 9) {
			int year;
			cout << "Please enter Month Added to Inventory: ";
			cin >> year;
			cin.ignore();
			inventory.bookLoopUpByMonthDayYearQuantity(year, 3);
			cout << endl;
		}
		else if (option == 10) {
			int quantity;
			cout << "Please enter Quanity which has Inventory: ";
			cin >> quantity;
			cin.ignore();
			inventory.bookLoopUpByMonthDayYearQuantity(quantity, 4);
			cout << endl;
		}
		else if (option == 11) {
			double wholesale;
			cout << "Please enter Whole Sale Cost which has Inventory: ";
			cin >> wholesale;
			cin.ignore();
			inventory.bookLookUpByWholeSaleOrRetailPrice(wholesale, 1);
			cout << endl;
		}
		else if (option == 12) {
			double retailPrice;
			cout << "Please enter Retail Price which has Inventory: ";
			cin >> retailPrice;
			cin.ignore();
			inventory.bookLookUpByWholeSaleOrRetailPrice(retailPrice, 2);
			cout << endl;
		}
		else if (option == 13) {
			cout << endl;
			inventory.bookEdit();
			cout << endl;
		}
	} while (option != 14);
}

//Function to show adding screen and return BookInfo Object for new book 
BookInfo RunningModule::addingBook() {
	string title, isbn, author, publisher; 
	int quantity, day, month, year; 
	double wholeSaleCost, retailPrice; 
	cout << "Please enter Book Title: "; 
	getline(cin, title); 
	cout << "Please enter Book ISBN Number: "; 
	getline(cin, isbn);
	cout << "Please enter Book Author: "; 
	getline(cin, author);
	cout << "Please enter Book Publisher: "; 
	getline(cin, publisher);
	cout << "Please enter quantity: "; 
	cin >> quantity;
	cin.ignore();
	cout << "Please enter Whole Salse Cost: "; 
	cin >> wholeSaleCost;
	cin.ignore();
	cout << "Please enter Retail Price: "; 
	cin >> retailPrice;
	cin.ignore();
	cout << "Please enter day which adds to inventory: "; 
	cin >> day; 	
	cin.ignore();
	cout << "Please enter month which adds to inventory: "; 
	cin >> month; 
	cin.ignore();
	cout << "Please enter year which adds to inventory: "; 
	cin >> year; 
	cout << endl; 
	BookInfo newBook = BookInfo(isbn, title, author, publisher, quantity, wholeSaleCost, retailPrice, day, month, year); 
	return newBook; 
}

// Function to show Report Menu
void RunningModule::reportMenu() {
	int option;
	do {
		cout << "Report Menu:" << endl;
		cout << "1. Inventory List." << endl;
		cout << "2. Inventory Wholesale Value." << endl;
		cout << "3. Inventory Retail Value." << endl;
		cout << "4. List by Quantity ." << endl;
		cout << "5. List by Cost." << endl;
		cout << "6. List by Age." << endl;
		cout << "7. Exit Report Menu" << endl;
		cout << "Please choose option 1 - 7: ";
		cin >> option;
		cout << endl;
		option = Utilities::correctingOption(option, 1, 7);
		cin.ignore();

		if (option == 1) {
			ReportModule::getAllBookInfo(inventory);
		}
		else if (option == 2) {
			// option 1 is get data and show whole sale cost
			ReportModule::getBookWholeSaleOrRetail(inventory,1);
		}
		else if (option == 3) {
			// option 2 is get data and show retail price
			ReportModule::getBookWholeSaleOrRetail(inventory, 2);
		}
		else if (option == 4){
			// option 1 is show data by sorting by Quantity
			ReportModule::showSortResult(inventory, 1);
		}
		else if (option == 5) {
			// option 3 is show data by sorting whole sale cost
			ReportModule::showSortResult(inventory, 3); 
		}
		else if (option == 6) {
			// option 2 is show data by sorting Purchased Date
			ReportModule::showSortResult(inventory, 2);
		}
	} while (option != 7); 
}

// Function to show Cashier Menu 
void RunningModule::cashierMenu() {
	int option;
	do {
		cout << "Cashier Menu" << endl;
		cout << "1. Cashier" << endl;
		cout << "2. Show Sale(s) Record" << endl;
		cout << "3. Exit" << endl; 
		cout << "Please choose option 1 - 3: ";
		cin >> option;
		cout << endl;
		option = Utilities::correctingOption(option, 1, 3);
		cin.ignore();

		if (option == 1) {
			string answer; 
			do {
				string information;
				int quantity, day, month, year;
				double saleTax;
				int saleRecordSize = cashier.getSaleRecordArraySize(); 

				cout << "Please enter Book Title or ISBN Number: "; 
				getline(cin, information); 
				cout << "Please enter quantity sold: "; 
				cin >> quantity; 
				cin.ignore(); 
				cout << "Please enter Sale Tax: "; 
				cin >> saleTax; 
				cin.ignore();
				cout << "Please enter Day Sold: "; 
				cin >> day; 
				cin.ignore(); 
				cout << "Please enter Month Sold: "; 
				cin >> month; 
				cin.ignore(); 
				cout << "Please enter Year Sold: "; 
				cin >> year; 
				cin.ignore(); 
				cout << endl; 
				cashier.cashierFunction(information, quantity, saleTax, day, month, year); 
				// Compare current size with saleRecordSize, if current size is greater, 
				// meaning new sale is added to sale array. Otherwise, it will be back 
				// to beginning 
				int currentIndex = cashier.getSaleRecordArraySize();
				if (currentIndex <= saleRecordSize) {
					cout << "No Book(s) was sold by " << information << " entered" << endl; 
					continue; 
				}
				else {
					BookSaleInfo *currentSaleRecord = cashier.getSaleArray(); 
					cout << "Current Sale Record" << endl; 
					cout << "Book Title: " << currentSaleRecord[currentIndex - 1].getSaleBookTitle() << endl;
					cout << "Book Author: " << currentSaleRecord[currentIndex - 1].getBookSaleAuthor() << endl;
					cout << "Book ISBN: " << currentSaleRecord[currentIndex - 1].getBookSaleISBN() << endl;
					cout << "Retail Price: " << currentSaleRecord[currentIndex - 1].getBookSaleRetailPrice() << endl;
					cout << "Sale Tax: " << saleTax << endl; 
					cout << "Quantity Sold: " << currentSaleRecord[currentIndex - 1].getBookQuantitySold() << endl; 
					cout << "Quantity Remaining: " << currentSaleRecord[currentIndex - 1].getBookSaleQuantityRemaining() << endl;
				}
				cout << endl; 
				cout << "Do you want to continue the sale (y/n): "; 
				getline(cin, answer); 

			} while (answer == "y"); 
		}
		else if (option == 2) {
			cashier.showSaleRecordSale(); 
		}
	} while (option != 3);
}

// Make user choose correct option which are available in menu
int Utilities::correctingOption(int inputNumber, int firstNumber, int lastNumber) {
	while (inputNumber < firstNumber || inputNumber > lastNumber) {
		cout << "Please input option from " << firstNumber << " to " << lastNumber << endl; 
		cin >> inputNumber; 
	}
	return inputNumber; 
}

// Function to calculate how many line in file
// Then returning size of inventory which will be used
int Utilities::getDataFIleSize(string fileName) {
	ifstream myFile;
	// Opening File to read data
	myFile.open(fileName);

	// initialize size variable to counting size of file 
	int size = 0;
	string line;

	// open file and calculate couting size of file

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			size++;
		}
	}

	// close file 
	myFile.close();
	return size;
}

// Function to show book and whole sale cose with total whole sale 
BookInfo * Utilities::installDataToInventory(string fileName, int fileSize) {

	// Initialzie empty inventory array with size of fileSize
	BookInfo * inventoryArrayPointer = new BookInfo[fileSize];

	// Open file to read data
	ifstream myFile;
	myFile.open(fileName);

	// Continue if file is open 
	if (myFile.is_open()) {
		string line, word;

		// initial count to for putting book info 
		// to approriate slot of inventory array 
		int count = 0;

		// Loop through the end of the file 
		while (getline(myFile, line)) {
			stringstream iss_line(line);

			// declare array with size 10 
			// each slot of array represend one field in Book 
			// book[0] - ISBN
			// book[1] - title 
			// book[2] - author 
			// book[3] - publisher
			// book[4] - quantity 
			// book[5] - wholesale 
			// book[6] - retail price
			// book[7] - day
			// book[8] - month
			// book[9] - year 
			string arrayString[10];

			// loop through array and put each field of text file 
			// to each slot in array
			for (int i = 0; i < 10; i++) {
				getline(iss_line, arrayString[i], '|');
			}

			// Start converting string to approriate int and double 
			int quantity = stoi(arrayString[4]); // quantity of book in inventory
			int day = stoi(arrayString[7]);  // day added to inventoty 
			int month = stoi(arrayString[8]); // month added to inventory 
			int year = stoi(arrayString[9]); // year added to inventoty 
			double wholesale = atof(arrayString[5].c_str()); // whole sale cost
			double retailPrice = atof(arrayString[6].c_str()); // retail price 
			//cout << quantity << endl; 

			// Construct BookInfo Object
			BookInfo tempBookInfo = BookInfo(arrayString[0], arrayString[1], arrayString[2], arrayString[3],
				quantity, wholesale, retailPrice, day, month, year);

			inventoryArrayPointer[count] = tempBookInfo;
			count++;
		}
	}

	myFile.close();

	return inventoryArrayPointer;
}

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
RunningModule::RunningModule(InventoryDataBaseModule currentInventory) {
	inventory = currentInventory;
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
			newBook.showBookField(); 
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
		cout << "4. List by Cost." << endl;
		cout << "5. List by Age." << endl;
		cout << "6. Exit Report Menu" << endl;
		cout << "Please choose option 1 - 6: ";
		cin >> option;
		cout << endl;
		option = Utilities::correctingOption(option, 1, 6);
		cin.ignore();

		if (option == 1) {
			ReportModule::getAllBookInfo(inventory);
		}
	} while (option != 6); 
}
// Make user choose correct option which are available in menu
int Utilities::correctingOption(int inputNumber, int firstNumber, int lastNumber) {
	while (inputNumber < firstNumber || inputNumber > lastNumber) {
		cout << "Please input option from " << firstNumber << " to " << lastNumber << endl; 
		cin >> inputNumber; 
	}
	return inputNumber; 
}

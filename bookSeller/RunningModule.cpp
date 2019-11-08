#include<string>
#include<iostream>
#include "pch.h"
#include "RunningModule.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "ReportModule.h"

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
		option = correctingOption(option, 1, 4);
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
		cout << "4. Look up book(s) by Author." << endl;
		cout << "5. Look up book(s) by Publisher." << endl;
		cout << "6. Look up book(s) by Day Added." << endl;
		cout << "7. Look up book(s) by Month Added." << endl;
		cout << "8. Look up book(s) by Year Added." << endl;
		cout << "9. Exit Inventory" << endl; 
		cout << "Please choose option 1 - 9: ";
		cin >> option;
		cout << endl; 
		option = correctingOption(option, 1, 9);
		cin.ignore(); 

		if (option == 1){
			BookInfo newBook = addingBook();
			inventory.addNewBook(newBook);
			cout << "Total Book(s) in Inventory: " << inventory.getInventorySize() << endl;
			cout << "New Book Info: ";
			newBook.getBookInfo();
			cout << endl; 
		}
	} while (option != 9);
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
		option = correctingOption(option, 1, 6);
		cin.ignore();

		if (option == 1) {
			ReportModule::getAllBookInfo(inventory);
		}
	} while (option != 6); 
}
// Make user choose correct option which are available in menu
int RunningModule::correctingOption(int inputNumber, int firstNumber, int lastNumber) {
	while (inputNumber < firstNumber || inputNumber > lastNumber) {
		cout << "Please input option from " << firstNumber << " to " << lastNumber << endl; 
		cin >> inputNumber; 
	}
	return inputNumber; 
}
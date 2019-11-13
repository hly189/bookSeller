#include<string>
#include<iostream>
#include <iomanip>
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "pch.h"
#include "cashierModuler.h"
#include "BookSaleInfo.h"


cashierModule::cashierModule() {};
cashierModule::cashierModule(InventoryDataBaseModule inventory) {
	bookInventory = inventory; 
	saleRecordArraySize = 0; 
}

// Function to get sale array 
BookSaleInfo * cashierModule::getSaleArray() {
	return saleRecordArray; 
}

// Function to get sale record array size 
int cashierModule::getSaleRecordArraySize() {
	return saleRecordArraySize; 
}

// Function to show title of each sale fields
void cashierModule::showSaleField() {
	cout << left << setw(60) << "Title";
	cout << setw(25) << "Author";
	cout << setw(25) << "ISBN";
	cout << setw(25) << "Quantity Sold";
	cout << setw(25) << "Quantity Remaining";
	cout << setw(25) << "Sale Tax";
	cout << setw(25) << "Total Price";
	cout << setw(35) << "Date Sold" << endl;
}

// Function to show sale record
void cashierModule::showSaleRecordSale(){
	
	// If no sale record, exit and let user knows 
	if (saleRecordArray == 0) {
		cout << "There is no Sale yet" << endl; 
		cout << endl; 
		return; 
	}
	
	showSaleField(); 
	// Loop through sale array and show record
	for (int i = 0; i < saleRecordArraySize; i++) {
		saleRecordArray[i].getBookSale(); 
	}
}

// Function to add book sold to sale array 
void cashierModule::addSoldBookToArray(BookSaleInfo bookSoldInformation) {
	
	// Declare new temp array
	BookSaleInfo *tempArray = new BookSaleInfo[saleRecordArraySize + 1];

	// Copy old array to new temp array 
	for (int i = 0; i < saleRecordArraySize; i++) {
		tempArray[i] = saleRecordArray[i]; 
	}

	// Add sold book to sale record at the end
	tempArray[saleRecordArraySize] = bookSoldInformation; 

	// Update sale record array 
	saleRecordArraySize++; 

	// Copy new array to original array 
	saleRecordArray = tempArray; 
}

// Function to calculate sale tax by quantity sold 
double cashierModule::calculateSaleTax(double saleTax, double retailPrice, int quantitySold) {
	saleTax = saleTax / 100; 

	// Calculate total sale tax 
	double totalSaleTax = retailPrice * saleTax; 

	// Calculate total price which customer will have to pay 
	double totalSalePrice = (totalSaleTax + retailPrice) * quantitySold; 

	return totalSalePrice; 
}

// Function to sell book, calculate total Prce, update inventory 
// and add new sale to sale array 
void cashierModule::cashierFunction(string saleInfo, int quantity, double saleTax, int day, int month, int year) {
	int lookupIndex; 
	
	// Create temp array of inventory
	BookInfo * currentInventory = bookInventory.getBookListPointer();

	// Start searching on given input information
	// Start looking by ISBN first
	lookupIndex = bookInventory.bookLookUpByISBNTitle(saleInfo, 1);
	if (lookupIndex < 0) {
		// Continue looking by Title if ISBN not found
		lookupIndex = bookInventory.bookLookUpByISBNTitle(saleInfo, 2);
		// If not found then exit function 
		if (lookupIndex < 0) {
			cout << "No " << saleInfo << " is found" << endl;
			return;
		}
	}
	
	// Check if there is book remaining in inventory 
	if (quantity > currentInventory[lookupIndex].getBookQuantity()) {
		cout << "Quantity input is greater than book in inventory" << endl; 
		return; 
	}

	// Calculate saletax of current book by given information 
	double totalPriceSold = calculateSaleTax(saleTax,
		currentInventory[lookupIndex].getBookRetailPrice(),
		quantity); 

	// Update quantity of inventory 
	int newInventoryQuantity = currentInventory[lookupIndex].getBookQuantity() - quantity;
	currentInventory[lookupIndex].setBookQuantity(newInventoryQuantity);

	// Create bookSaleObject
	BookSaleInfo bookSaleObject = BookSaleInfo(currentInventory[lookupIndex], quantity,
		saleTax, totalPriceSold, day, month, year); 

	// Add bookSaleObject to sale array 
	addSoldBookToArray(bookSaleObject); 

}


#include<string>
#include<iostream>
#include <iterator>
#include <iomanip>
#include "pch.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "ReportModule.h"

using namespace std; 

// Function to show all the book info:
void ReportModule::getAllBookInfo(InventoryDataBaseModule inventory){

	// Get bookList pointer and bookListSize in InventoryDataBaseModule
	BookInfo *inventoryList = inventory.getBookListPointer(); 
	int inventorySize = inventory.getInventorySize(); 
	
	// Loop through the bookList and get infomation of each book by calling 
	// method getBookInfo() in BookInfo class
	for (int i = 0; i < inventorySize; i++) {
		// Show Section for each field 
		// for only once
		if (i == 0) {
			inventory.showBookField();
		}
		inventoryList[i].getBookInfo(); 
	}
	// free memory since inventoryList is temporary array
	cout << endl; 
}

// Function to show book and whole sale cose with total whole sale 
void ReportModule::getBookWholeSaleOrRetail(InventoryDataBaseModule inventory, int option) {

	// option 1: get list book with whole sale cost 
	// option 2: get list of book with retail price
	
	// Name for the 2nd field. Default is Whole sale cost
	string secondField = "Whole Sale Cost"; 
	if (option == 2) {
		secondField = "Retail Price"; 
	}

	cout << left << setw(60) << "Title";
	cout << setw(15) << secondField << endl;

	// Total of whole sale cost 
	double total = 0; 

	// get size of inventory 
	int sizeInventory = inventory.getInventorySize(); 

	// get copy of inventory pointer 
	BookInfo* copyInventory = inventory.getBookListPointer(); 

	// Loop through inventory to get book title andn whole sale cost 
	// then add each whole sale cost to total 

	for (int i = 0; i < sizeInventory; i++) {
		double currentInventoryPrice; 
		if (option == 1) {
			currentInventoryPrice = copyInventory[i].getBookWholeSaleCost();
		}
		else {
			currentInventoryPrice = copyInventory[i].getBookRetailPrice();
		}
		cout << left << setw(60) << copyInventory[i].getBookTitle();
		cout << setw(15) << currentInventoryPrice << endl;
		total = total + currentInventoryPrice;

	}
	cout << endl; 
	cout << "Total " << secondField << ": " << total << endl; 
	cout << endl;
}

// Function to sort by whole sale cost 
BookInfo*  ReportModule::sortByWholeSaleCost(InventoryDataBaseModule inventory, int size) {
	BookInfo* tempBookInventory = inventory.getBookListPointer(); 
	
	// temporary variable to store minium index
	int minIndex; 

	// Loop from 0 to end of Inventory 
	for (int i = 0; i < size; i++) {
		minIndex = i;
		// Loop from next element of Inventory until the end  
		for (int j = i + 1; j < size; j++) {
			// If Next element of Inventory is greater than the minimum value, 
			// then set minimum index equal to next element
			if (tempBookInventory[j].getBookWholeSaleCost() > tempBookInventory[minIndex].getBookWholeSaleCost()) {
				minIndex = j;
			}
		}
		// Swap the minimum index and current element 
		swap(tempBookInventory[minIndex], tempBookInventory[i]);
	}
	return tempBookInventory; 
}


// Function to sort by Quantity

BookInfo* ReportModule::sortByQuantity(InventoryDataBaseModule inventory, int size) {
	BookInfo* tempBookInventory = inventory.getBookListPointer();

	// temporary variable to store minium index
	int minIndex;
	
	// Loop from 0 to end of Inventory 
	for (int i = 0; i < size; i++) {
		minIndex = i;
		// Loop from next element of Inventory until the end  
		for (int j = i + 1; j < size; j++) {
			int minValue, jValue; 
	
			// get quantity of book of each book
			jValue = tempBookInventory[j].getBookQuantity();
			minValue = tempBookInventory[minIndex].getBookQuantity(); 

			// If Next element of Inventory is greater than the minimum value, 
			// then set minimum index equal to next element
			if (jValue > minValue) {
				minIndex = j;
			}
		}
		// Swap the minimum index and current element 
		swap(tempBookInventory[minIndex], tempBookInventory[i]);
	}

	return tempBookInventory;
}


// Function to sort by Purchased Date
BookInfo* ReportModule::sortByPurchasedDate(InventoryDataBaseModule inventory, int size) {
	BookInfo* tempBookInventory = inventory.getBookListPointer();

	// temporary variable to store minium index
	int minIndex;

	// Loop from 0 to end of Inventory 
	for (int i = 0; i < size; i++) {
		minIndex = i;
		// Loop from next element of Inventory until the end  
		for (int j = i + 1; j < size; j++) {
			int minValue, jValue;

			// get day, month and year of each book and concatenate them
			jValue = concatenateDate(tempBookInventory[j].getBookDay(), tempBookInventory[j].getBookMonth(),
					tempBookInventory[j].getBookYear());
			minValue = concatenateDate(tempBookInventory[minIndex].getBookDay(), tempBookInventory[minIndex].getBookMonth(),
					tempBookInventory[minIndex].getBookYear());

			// If Next element of Inventory is greater than the minimum value, 
			// then set minimum index equal to next element
			if (jValue < minValue) {
				minIndex = j;
			}
		}
		// Swap the minimum index and current element 
		swap(tempBookInventory[minIndex], tempBookInventory[i]);
	}

	return tempBookInventory;
}


// Function to show search result
// option 1: Sort by Quantity
// option 2: Sort by Purchased Date
// option 3: Sort by Whole Sale Cost
void ReportModule::showSortResult(InventoryDataBaseModule inventory, int option) {
	// Get the current size of inventory
	int currentSize = inventory.getInventorySize(); 
	
	// Create temp Inventory  
	BookInfo *tempInventory = new BookInfo[currentSize];

	// Checking option 
	if (option == 1) {
		tempInventory = sortByQuantity(inventory, currentSize);
	}else if (option == 2){
		tempInventory = sortByPurchasedDate(inventory, currentSize);
	}else{
		tempInventory = sortByWholeSaleCost(inventory, currentSize); 
	}

	// Show sort result regarding option given
	inventory.showBookField(); 
	for (int i = 0; i < currentSize; i++) {
		tempInventory[i].getBookInfo(); 
	}
	cout << endl;
}

// Function to concatenate day, month and year
int ReportModule::concatenateDate(int day, int month, int year) {
	int dateValue; 
	string dayString = to_string(day); 
	string monthString = to_string(month); 
	string yearString = to_string(year); 
	if (day < 10) {
		dayString = "0" + dayString; 
	}

	if (month < 10) {
		yearString = "0" + yearString; 
	}
	string dateValueString = yearString + monthString + dayString; 
	dateValue = stoi(dateValueString);
	return dateValue; 
}
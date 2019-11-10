#include<string>
#include<iostream>
#include <iterator>
#include "pch.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "ReportModule.h"
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
			inventoryList[i].showBookField();
		}
		inventoryList[i].getBookInfo(); 
	}
	// free memory since inventoryList is temporary array
	//delete[] inventoryList; 
	cout << endl; 
}

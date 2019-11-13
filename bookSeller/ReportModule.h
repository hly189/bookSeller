#ifndef ReportModule_h
#define ReportModule_h
#include<string>
#include<iostream>
#include <iomanip>
#include "pch.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"

namespace ReportModule {

	// Get all the book info
	void getAllBookInfo(InventoryDataBaseModule inventory);

	// Show list of book by wholesale cost or retail price
	void getBookWholeSaleOrRetail(InventoryDataBaseModule inventory, int option);

	// Selection sort by Quantity or Purchased Date 

	BookInfo * sortByQuantity(InventoryDataBaseModule inventory, int size);

	// Selection sort by Purchase Date
	BookInfo * sortByPurchasedDate(InventoryDataBaseModule inventory, int size);


	// Selection sort by Whole Sale
	BookInfo * sortByWholeSaleCost(InventoryDataBaseModule inventory, int size);

	// Function to show search result
	// option 1: Sort by Quantity
	// option 2: Sort by Purchased Date
	// option 3: Sort by Whole Sale Cost
	void showSortResult(InventoryDataBaseModule inventory, int option);

	// Function to concatenate day, month and year
	int concatenateDate(int day, int month, int year); 

};

#endif

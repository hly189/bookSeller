#ifndef cashierModule_h
#define cashierModule_h
#include<string>
#include<iostream>
#include <iomanip>
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "BookSaleInfo.h"
#include "pch.h"

using namespace std; 


class cashierModule {
private: 
	InventoryDataBaseModule bookInventory; 
	BookSaleInfo *saleRecordArray; 
	int saleRecordArraySize; 
public: 
	cashierModule(); 
	cashierModule(InventoryDataBaseModule inventory); 

	// Function to get sale array 
	BookSaleInfo * getSaleArray(); 

	// Function to get sale record array size 
	int getSaleRecordArraySize(); 

	// Function to show title of each sale fields
	void showSaleField();

	// add sold book to sale array 
	void addSoldBookToArray(BookSaleInfo bookSoldInfo); 

	//Function to sell book 
	void cashierFunction(string saleInfo, int quantity, double saleTax, int day, int month, int year);

	// Function to calculate sale tax by quantity sold 
	double calculateSaleTax(double saleTax, double retailPrice, int quantitySold);

	// Show sale record
	void showSaleRecordSale(); 

};

#endif

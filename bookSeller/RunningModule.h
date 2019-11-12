#ifndef RunningModule_h
#define RunningModule_h

#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "BookInfo.h"
#include "InventoryDataBaseModule.h"

namespace Utilities {
	// Function to Correct opttion for user
	int correctingOption(int inputNumber, int firstOptionNumber, int lastOptionNumber);

	// Function to calculate how many line in file
	// Then returning size of inventory which will be used
	int getDataFIleSize(string fileName);

	//Function to get install data file to inventory
	BookInfo * installDataToInventory(string fileName, int fileSize);
}

class RunningModule {
private: 
	InventoryDataBaseModule inventory;
public: 
	RunningModule();
	RunningModule(InventoryDataBaseModule currentInventory);
	// Main Menu Screen
	void mainMenu(); 
	// Inventory Menu Screen 
	void inventoryMenu();
	// Report Menu Screen
	void reportMenu();
	// Cashier Menu Screen
	void cashierMenu();
	// Function for adding book screen and return BookInfo object for new Book 
	BookInfo addingBook(); 
};


#endif

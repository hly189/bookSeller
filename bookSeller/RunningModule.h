#ifndef RunningModule_h
#define RunningModule_h

#include<string>
#include<iostream>
#include "BookInfo.h"
#include "InventoryDataBaseModule.h"

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
	// Function to Correct opttion for user
	int correctingOption(int inputNumber, int firstOptionNumber, int lastOptionNumber);
};



#endif

// bookSeller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BookInfo.h"
#include "InventoryDataBaseModule.h"
#include "ReportModule.h"
#include "RunningModule.h"
#include "cashierModuler.h"
#include <string>


using namespace std; 


int main()
{
	// Initialize Inventory database by getting data file to inventory
	string fileName = "C:\\Users\\Hoa\\source\\repos\\bookSeller\\bookSeller\\bookdata.txt"; 
	int fileSize = Utilities::getDataFIleSize(fileName);
	BookInfo * tempArray = Utilities::installDataToInventory(fileName, fileSize);

	InventoryDataBaseModule inventory = InventoryDataBaseModule(tempArray, fileSize);
	cashierModule cashierObject = cashierModule(inventory); 
	RunningModule runningMenu = RunningModule(inventory, cashierObject);
	runningMenu.mainMenu(); 

	// free mmory 
	delete[] tempArray;


}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

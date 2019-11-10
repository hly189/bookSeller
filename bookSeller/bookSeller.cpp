// bookSeller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BookInfo.h"
#include "InventoryDataBaseModule.h"
#include "ReportModule.h"
#include "RunningModule.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std; 

// Function to calculate how many line in file
// Then returning size of inventory which will be used
int getDataFIleSize(string fileName) {
	ifstream myFile;
	// Opening File to read data
	myFile.open(fileName);

	// initialize size variable to counting size of file 
	int size = 0;
	string line;

	// open file and calculate couting size of file

	if (myFile.is_open()) {
		while (!myFile.eof()) {
			getline(myFile, line);
			size++;
		}
	}

	// close file 
	myFile.close();
	return size;
}

BookInfo * installDataToInventory(string fileName, int fileSize) {

	// Initialzie empty inventory array with size of fileSize
	BookInfo * inventoryArrayPointer = new BookInfo[fileSize];

	// Open file to read data
	ifstream myFile;
	myFile.open(fileName);

	// Continue if file is open 
	if (myFile.is_open()) {
		string line, word;

		// initial count to for putting book info 
		// to approriate slot of inventory array 
		int count = 0; 

		// Loop through the end of the file 
		while (getline(myFile, line)) {
			stringstream iss_line(line);
			
			// declare array with size 10 
			// each slot of array represend one field in Book 
			// book[0] - ISBN
			// book[1] - title 
			// book[2] - author 
			// book[3] - publisher
			// book[4] - quantity 
			// book[5] - wholesale 
			// book[6] - retail price
			// book[7] - day
			// book[8] - month
			// book[9] - year 
			string arrayString[10]; 

			// loop through array and put each field of text file 
			// to each slot in array
			for (int i = 0; i < 10; i++) {
				getline(iss_line, arrayString[i], '|'); 
			}
			
			// Start converting string to approriate int and double 
			int quantity = stoi(arrayString[4]); // quantity of book in inventory
			int day = stoi(arrayString[7]);  // day added to inventoty 
			int month = stoi(arrayString[8]); // month added to inventory 
			int year = stoi(arrayString[9]); // year added to inventoty 
			double wholesale = atof(arrayString[5].c_str()); // whole sale cost
			double retailPrice = atof(arrayString[6].c_str()); // retail price 
			//cout << quantity << endl; 

			// Construct BookInfo Object
			BookInfo tempBookInfo = BookInfo(arrayString[0], arrayString[1], arrayString[2], arrayString[3],
				quantity, wholesale, retailPrice, day, month, year);

			inventoryArrayPointer[count] = tempBookInfo;
			count++;
		}
	}

	myFile.close();

	return inventoryArrayPointer;
}


int main()
{
	// Initialize Inventory database by getting data file to inventory
	string fileName = "C:\\Users\\Hoa\\source\\repos\\bookSeller\\bookSeller\\bookdata.txt"; 
	int fileSize = getDataFIleSize(fileName); 
	BookInfo * tempArray = installDataToInventory(fileName, fileSize); 

	InventoryDataBaseModule inventory = InventoryDataBaseModule(tempArray, fileSize);
	RunningModule runningMenu = RunningModule(inventory);
	runningMenu.mainMenu(); 


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

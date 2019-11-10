#ifndef BookInfo_h
#define BookInfo_h
#include<string>
#include<iostream>
#include "Date.h"

using namespace std; 

class BookInfo {
private: 
	string bookIsbn; 
	string bookTitile; 
	string bookAuthor; 
	string bookPublisher; 
	int bookQuantity; 
	double bookWholeSaleCost; 
	double bookRetailPrice; 
	Date bookDate; 

public:
	// Default constructor
	BookInfo(); 
	BookInfo(string isbn, string title, string author, string publisher, int quantity, double wholeSaleCost, double retailPrice, int day, int month, int year);

	// Destructor 
	~BookInfo();
	//Functions to get book info
	// get book ISBN number: 

	string getBookIsbn(); 

	// get book titile
	string getBookTitle(); 

	// get author of the book
	string getBookAuthor(); 

	// get publisher of the book 
	string getBookPublisher();

	// get quantity of the Book
	int getBookQuantity(); 

	// get whole sale cost of the book
	double getBookWholeSaleCost(); 

	// get retail price of the book
	double getBookRetailPrice(); 

	// get full date of the book which added to inventory
	string getFullDate(); 

	// get full info of the book 
	void getBookInfo(); 

	// get day of the bok which added to inventory
	int getBookDay(); 

	// get month of the book which added to inventory
	int getBookMonth(); 

	//get year of the book which added to inventory
	int getBookYear(); 

	// Function to set book Info
	// set ISBN number of the book
	void setBookIsbnNumber(string isbnNumber); 

	// set titile of the book
	void setBookTitle(string title); 

	// set author of the book 
	void setBookAuthor(string author); 

	// set publisher of the book
	void setBookPublisher(string publisher); 

	// set quanity of the book 
	void setBookQuantity(int quantity); 

	//set whole sale price of the book 
	void setWholeSaleCost(double cost); 

	// set retail price of the book
	void setBookRetailPrice(double retailPrice); 

	// set day of the book which adds to inventory
	void setBookDay(int bookday); 

	// set month of the book which adds to inventory
	void setBookMonth(int bookMonth); 

	// set year of the book which adds to inventory
	void setBookYear(int bookYear); 

	void showBookField(); 
};


#endif

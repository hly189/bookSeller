#include "pch.h"
#include<string>
#include<iostream>
#include <iomanip>
#include "BookInfo.h"
#include "Date.h"

// Default constructor
BookInfo::BookInfo() {
	bookIsbn = ""; 
	bookAuthor = ""; 
	bookTitile = ""; 
	bookPublisher = ""; 
	bookQuantity = 0; 
	bookWholeSaleCost = 0.0;
	bookRetailPrice = 0.0;
	bookDate; 
}

BookInfo::BookInfo(string isbn, string title, string author, string publisher, int quantity, double wholeSaleCost, double retailPrice, int day, int month, int year) {
	bookIsbn = isbn; 
	bookTitile = title; 
	bookAuthor = author;
	bookPublisher = publisher; 
	bookQuantity = quantity; 
	bookWholeSaleCost = wholeSaleCost; 
	bookRetailPrice = retailPrice; 
	// pass day, month and year to Date Object to construc day, month and year for the book
	bookDate = Date(day, month, year); 
}

// Function to get ISBN Number the book
string BookInfo::getBookIsbn() {
	return bookIsbn; 
}

// Function to get Title of the book
string BookInfo::getBookTitle(){
	return bookTitile; 
}

// Function to get author of the book
string BookInfo::getBookAuthor() {
	return bookAuthor; 
}

// Function to get publisher of the book
string BookInfo::getBookPublisher() {
	return bookPublisher; 
}

// Function to get quantiy of the book
int BookInfo::getBookQuantity() {
	return bookQuantity; 
}

// Function to get whole sale cost of the book
double BookInfo::getBookWholeSaleCost() {
	return bookWholeSaleCost; 
}

// Function to get retail price of the book 
double BookInfo::getBookRetailPrice() {
	return bookRetailPrice; 
}

//Function to get full Date of for the book 
string BookInfo::getFullDate() {
	// call toString() function from Date class to get format dd/mm/yyyy
	return bookDate.toString(); 
}

// Function to get day of the book which add to inventory 
int BookInfo::getBookDay() {
	// call getDay() function from Date class to get day of the book
	return bookDate.getDay(); 
}

// Function to get month of the book which add to inventory 
int BookInfo::getBookMonth() {
	// call getMonth()function from Date class to get month of the book
	return bookDate.getMonth(); 
}

// Funciton to get year of the book which add to inventory
int BookInfo::getBookYear() {
	// call getYear() function from Date class to get year of the book
	return bookDate.getYear(); 
}

// Function to set isbn number of the book 
void BookInfo::setBookIsbnNumber(string isbn) {
	bookIsbn = isbn; 
}

// Function to set title for the book 
void BookInfo::setBookTitle(string title) {
	bookTitile = title; 
}

//Function to set author for the book
void BookInfo::setBookAuthor(string author) {
	bookAuthor = author; 
}

// Function to set publisher for the book
void BookInfo::setBookPublisher(string publisher) {
	bookPublisher = publisher; 
}

// Function to set quantity for the book
void BookInfo::setBookQuantity(int quantity) {
	bookQuantity = quantity; 
}

// Function to set whole sale cost for the book
void BookInfo::setWholeSaleCost(double cost) {
	bookWholeSaleCost = cost; 
}

// Function to set Retail price for the book 
void BookInfo::setBookRetailPrice(double retailPrice){
	bookRetailPrice = retailPrice; 
}

// Function to set day of the book which adds to inventory 
void BookInfo::setBookDay(int day) {
	// call setDay function in Date class to set day for the book
	bookDate.setDay(day); 
}

// Function to set month of the book which adds to inventory
void BookInfo::setBookMonth(int month) {
	// call setMonth function in Date class to set month for the book
	bookDate.setMonth(month); 
}

// Function to set year of the book which adds to inventory
void BookInfo::setBookYear(int year) {
	// call setYear function in Date class to set year for the book
	bookDate.setYear(year); 
}

// Function to get full info of the book
void BookInfo::getBookInfo() {
	cout << left << setw(50) << getBookTitle(); 
	cout << setw(15) << getBookAuthor(); 
	cout << setw(15) << getBookPublisher();
	cout << setw(15) << getBookIsbn();
	cout << setw(15) << getBookQuantity(); 
	cout << setw(15) << getBookWholeSaleCost(); 
	cout << setw(10) << getBookRetailPrice(); 
	cout << setw(35) << getFullDate() << endl;

}
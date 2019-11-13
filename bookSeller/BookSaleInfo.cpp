#include<string>
#include<iostream>
#include <iomanip>
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "pch.h"
#include "pch.h"
#include "BookSaleInfo.h"

// Constructor
BookSaleInfo::BookSaleInfo() {
	bookInfomation; 
	bookSaleTax = 0.0; 
	totalPrice = 0.0; 
	bookQuantitySold = 0; 
	bookSaleDate;
}
BookSaleInfo::BookSaleInfo(BookInfo information, int sold, double saleTax, double total, int day, int month, int year) {
	bookInfomation = information; 
	bookQuantitySold = sold; 
	bookSaleTax = saleTax; 
	totalPrice = total; 
	bookSaleDate = Date(day, month, year); 
}
// get book title which was sold
string BookSaleInfo::getSaleBookTitle(){
	return bookInfomation.getBookTitle(); 
}

// get book author which was sold
string BookSaleInfo::getBookSaleAuthor() {
	return bookInfomation.getBookAuthor(); 
}

// get book quantity
int BookSaleInfo::getBookSaleQuantityRemaining(){
	return bookInfomation.getBookQuantity();
}

// get book quantity sold
int BookSaleInfo::getBookQuantitySold(){
	return bookQuantitySold; 
}

//get book sale tax 
double BookSaleInfo::getBookSaleTax() {
	return bookSaleTax; 
}

// get book sale day
int BookSaleInfo::getBookSaleDay() {
	return bookSaleDate.getDay(); 
}

// get book sale month 
int BookSaleInfo::getBookSaleMonth() {
	return bookSaleDate.getMonth(); 
}

// get book sale year
int BookSaleInfo::getBookSaleYear() {
	return bookSaleDate.getYear(); 
}

// get purchased date in format mm/dd/yyyy
string BookSaleInfo::getBookSaleDateFull() {
	return bookSaleDate.toString(); 
}

// get book isbn
string BookSaleInfo::getBookSaleISBN() {
	return bookInfomation.getBookIsbn(); 
}

// get book retail price
double BookSaleInfo::getBookSaleRetailPrice() {
	return bookInfomation.getBookRetailPrice(); 
}

// get book sale total price 
double BookSaleInfo::getBookSaleTotalPrice() {
	return totalPrice; 
}

// set book sale tax
void BookSaleInfo::setBookSaleTax(double saleTax) {
	bookSaleTax = saleTax; 
}

// set book sale quantity 
void BookSaleInfo::setBookSaleQuantity(int quantity) {
	bookInfomation.setBookQuantity(quantity); 
}

//set book sale day 
void BookSaleInfo::setBookSaleDay(int day) {
	bookInfomation.setBookDay(day); 
}

// set book sale month 
void BookSaleInfo::setBookSaleMonth(int month) {
	bookInfomation.setBookMonth(month); 
}

// set book sale year 
void BookSaleInfo::setBookSaleYear(int year) {
	bookInfomation.setBookYear(year); 
}

// show book sale info
void BookSaleInfo::getBookSale() {
		cout << left << setw(60) << getSaleBookTitle();
		cout << setw(25) << getBookSaleAuthor();
		cout << setw(25) << getBookSaleISBN(); 
		cout << setw(25) << getBookQuantitySold();
		cout << setw(25) << getBookSaleQuantityRemaining();
		cout << setw(25) << getBookSaleTax();
		cout << setw(25) << getBookSaleTotalPrice();
		cout << setw(35) << getBookSaleDateFull() << endl;
}
#ifndef BookSaleInfo_h
#define BookSaleInfo_h
#include<string>
#include<iostream>
#include <iomanip>
#include "Date.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"
#include "pch.h"

class BookSaleInfo{
private: 
	BookInfo bookInfomation; 
	int bookQuantitySold; 
	double bookSaleTax; 
	double totalPrice;
	Date bookSaleDate; 
public: 
	BookSaleInfo(); 
	BookSaleInfo(BookInfo information, int sold, double saleTax, double total, int day, int month, int year); 
	
	// get book title
	string getSaleBookTitle(); 

	// get book sale author 
	string getBookSaleAuthor(); 

	// get book quantity sold
	int getBookQuantitySold(); 

	// get book sale quantity 
	int getBookSaleQuantityRemaining();

	// get book sale tax 
	double getBookSaleTax(); 

	// get book sale total price 
	double getBookSaleTotalPrice(); 

	// get book sale day
	int getBookSaleDay(); 

	// get book sale month; 
	int getBookSaleMonth(); 

	// get book sale year; 
	int getBookSaleYear(); 

	// get book sale ISBN 
	string getBookSaleISBN(); 

	// get retail price 
	double getBookSaleRetailPrice();

	// get full sale date in format mm/dd/yyyy
	string getBookSaleDateFull(); 

	// set book sale tax
	void setBookSaleTax(double saleTax); 

	// set book sale quantity
	void setBookSaleQuantity(int quantity); 

	// set book sale day
	void setBookSaleDay(int day); 

	// set book sale month
	void setBookSaleMonth(int month); 

	// set book sale year 
	void setBookSaleYear(int year); 

	// show book sale info 
	void getBookSale();
};

#endif

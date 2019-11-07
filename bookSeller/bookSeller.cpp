// bookSeller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BookInfo.h"
#include <iostream>
int main()
{
	BookInfo bookTitile;
	bookTitile.setBookIsbnNumber("15-2233");
	bookTitile.setBookAuthor("Halminton");
	bookTitile.setBookTitle("Gone with the wind");
	bookTitile.setBookPublisher("New York");
	bookTitile.setBookQuantity(10);
	bookTitile.setBookRetailPrice(10.5);
	bookTitile.setWholeSaleCost(9.5);
	bookTitile.setBookMonth(12);
	bookTitile.setBookDay(10);
	bookTitile.setBookYear(1995);
	bookTitile.getBookInfo();

	BookInfo book2 = BookInfo("15-123", "Harry Potter", "J.K Rowling", "New York", 100, 11.5, 13.5, 12, 12, 2017);
	
	book2.getBookInfo();
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

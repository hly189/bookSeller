#ifndef ReportModule_h
#define ReportModule_h
#include<string>
#include<iostream>
#include <iterator>
#include "pch.h"
#include "InventoryDataBaseModule.h"
#include "BookInfo.h"

namespace ReportModule {

	// Get all the book info
	void getAllBookInfo(InventoryDataBaseModule inventory);

};

#endif

/****************************************************************************************************************
 * Programmer: Josh Abbott																						*
 * Class: CptS 122; Lab Section 10																				*
 * Programming Assignment: 8																					*
 * Date: 4/14/22																								*
 *																												*
 * Description: This program reads in product data from a csv file, sorts it, and then analyzes it by			*
 *              seperating it by smallest and largest amount of units sold.										*
 *																												*
 * Format of record in input files (data.csv):																	*
 *	Units, Type, Transaction																					*
 ***************************************************************************************************************/

#pragma once

#include "pa8.h"
#include "BST.h"

class DataAnalysis
{
public:
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;

	bool openFile();
	void readLine(string line);
	void readFile();
	void treeSorter(int units, string type, string transaction);
	void displayToScreen();

};

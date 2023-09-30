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
#include "Node.h"

class TransactionNode : public Node
{
public:
	TransactionNode(string newData = "", int newUnits = 0);
	~TransactionNode();

	void setUnits(const int newUnits);

	int getUnits();
	void printData();

private:
	int mUnits;

};

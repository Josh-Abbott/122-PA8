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

#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData, int newUnits) : Node(newData)
{
	mUnits = newUnits;
}

TransactionNode::~TransactionNode()
{

}

int TransactionNode::getUnits()
{
	return mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

void TransactionNode::printData()
{
	cout << "Data: " << mData << " Units: " << mUnits << endl;
}
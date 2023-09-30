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

class Node
{
public:
	Node(string newData = "", Node* left = nullptr, Node* right = nullptr);
	virtual ~Node();

	void setData(const string newData);
	void setLeft(Node* const newLeft);
	void setRight(Node* const newRight);

	string getData() const;
	Node* &getLeft();
	Node* &getRight();

	virtual void printData() = 0;

protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;

};

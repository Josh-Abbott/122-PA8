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
#include "TransactionNode.h"

class BST
{
public:
	BST(Node* newRoot = nullptr);
	~BST();

	void setRoot(Node* newRoot);
	Node* getRoot();

	void insert(string& newData, int& newUnit);
	void inOrderTrav();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();

private:
	Node* mpRoot;

	void destroyTree(Node*& pTree);
	void insert(Node*& pTree, string& newData, int& newUnit);
	void inOrderTrav(Node* pTree);
};

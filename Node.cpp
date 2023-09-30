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

#include "Node.h"

Node::Node(string newData, Node* newLeft, Node* newRight)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{

}

void Node::setData(const string newData)
{
	mData = newData;
}

void Node::setLeft(Node* const newLeft)
{
	mpLeft = newLeft;
}

void Node::setRight(Node* const newRight)
{
	mpRight = newRight;
}

string Node::getData() const
{
	return mData;
}

Node*& Node::getLeft()
{
	return mpLeft;
}

Node*& Node::getRight()
{
	return mpRight;
}
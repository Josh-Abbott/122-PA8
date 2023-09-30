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

#include "BST.h"

BST::BST(Node* newRoot)
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

/*************************************************************
 * Function: destroyTree ()		                             *
 * Date Created: 4/12/22									 *
 * Date Last Modified: 4/12/22                               *
 * Description: This function recursively destroys the tree  *
 *				 in postOrder.							     *
 * Input parameters: A Node*&.					             *
 * Returns: Nothing.								         *
 * Preconditions: None.					  .					 *
 * Postconditions: The tree is destroyed succesfully.	     *
 *************************************************************/

void BST::destroyTree(Node*& pTree)
{
	if (pTree != nullptr)
	{
		destroyTree(pTree->getLeft());
		destroyTree(pTree->getRight());
		delete pTree;
	}
}

void BST::setRoot(Node* newRoot)
{
	mpRoot = newRoot;
}

Node* BST::getRoot()
{
	return mpRoot;
}

void BST::insert(string& newData, int& newUnit) // public (helper)
{
	insert(mpRoot, newData, newUnit);
}

/*************************************************************
 * Function: insert ()			                             *
 * Date Created: 4/13/22									 *
 * Date Last Modified: 4/14/22                               *
 * Description: This function inserts the data into the BST  *
 *				 using the units amount to compare.			 *
 * Input parameters: A Node*&, string&, and int&.		     *
 * Returns: Nothing.								         *
 * Preconditions: None.					  .					 *
 * Postconditions: The data is succesfully inserted.	     *
 *************************************************************/

void BST::insert(Node*& pTree, string& newData, int& newUnit) // private
{
	if (pTree == nullptr) 
	{
		this->mpRoot = new TransactionNode(newData, newUnit);
	}
	else
	{
		if (((TransactionNode*)pTree)->getUnits() < newUnit) // ?
		{
			if (pTree->getRight() == nullptr)
			{
				pTree->setRight(new TransactionNode(newData, newUnit));
			}
			else
			{
				insert(pTree->getRight(), newData, newUnit);
			}
		}
		else if (newUnit < ((TransactionNode*)pTree)->getUnits()) // ?
		{
			if (pTree->getLeft() == nullptr)
			{
				pTree->setLeft(new TransactionNode(newData, newUnit));
			}
			else
			{
				insert(pTree->getLeft(), newData, newUnit);
			}
		}
	}
}

/*************************************************************
 * Function: findSmallest ()	                             *
 * Date Created: 4/13/22									 *
 * Date Last Modified: 4/13/22                               *
 * Description: This function loops through the BST until    *
 *				 it finds the smallest unit.			     *
 * Input parameters: Nothing.					             *
 * Returns: A reference to a TransactionNode.		         *
 * Preconditions: None.					  .					 *
 * Postconditions: The smallest node is returned.		     *
 *************************************************************/

TransactionNode& BST::findSmallest()
{
	TransactionNode* pTemp = (TransactionNode*)mpRoot;

	while (pTemp->getLeft() != nullptr)
	{
		pTemp = (TransactionNode*)pTemp->getLeft();
	}
	return *pTemp;
}

/*************************************************************
 * Function: findLargest ()		                             *
 * Date Created: 4/13/22									 *
 * Date Last Modified: 4/13/22                               *
 * Description: This function loops through the BST until    *
 *				 it finds the largest unit.				     *
 * Input parameters: Nothing.					             *
 * Returns: A reference to a TransactionNode.		         *
 * Preconditions: None.					  .					 *
 * Postconditions: The largest node is returned.		     *
 *************************************************************/

TransactionNode& BST::findLargest()
{
	TransactionNode* pTemp = (TransactionNode*)mpRoot;

	while (pTemp->getRight() != nullptr)
	{
		pTemp = (TransactionNode*)pTemp->getRight();
	}
	return *pTemp;
}

void BST::inOrderTrav()
{
	inOrderTrav(mpRoot);
}

/*************************************************************
 * Function: inOrderTrav ()		                             *
 * Date Created: 4/13/22									 *
 * Date Last Modified: 4/13/22                               *
 * Description: This function recursively goes through the   *
 *				 BST in order and prints out the data.	     *
 * Input parameters: A pointer to a Node.		             *
 * Returns: Nothing.								         *
 * Preconditions: None.					  .					 *
 * Postconditions: The data is printed succesfully.		     *
 *************************************************************/

void BST::inOrderTrav(Node* pTree)
{
	if (pTree != nullptr)
	{
		inOrderTrav(pTree->getLeft());
		cout << pTree->getData() << endl;
		inOrderTrav(pTree->getRight());
	}
}
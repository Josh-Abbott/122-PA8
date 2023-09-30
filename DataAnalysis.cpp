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

#include "DataAnalysis.h"

 /*************************************************************
  * Function: runAnalaysis ()		                          *
  * Date Created: 4/14/22									  *
  * Date Last Modified: 4/14/22                               *
  * Description: This function opens the file, reads it in,   *
  *				 displays it, and closes it.			      *
  * Input parameters: Nothing.					              *
  * Returns: Nothing.								          *
  * Preconditions: None.					  .				  *
  * Postconditions: The analysis is ran succesfully.	      *
  *************************************************************/

void DataAnalysis::runAnalysis()
{
	bool fileStatus = openFile();
	
	if (fileStatus == true)
	{
		readFile();
		displayToScreen();
		mCsvStream.close();
	}
}

/*************************************************************
 * Function: openFile ()		                             *
 * Date Created: 4/14/22									 *
 * Date Last Modified: 4/14/22                               *
 * Description: This function opens the file, checks if it   *
 *				 was opened succesfully, and returns that.   *
 * Input parameters: Nothing.					             *
 * Returns: A bool value.							         *
 * Preconditions: None.					  .					 *
 * Postconditions: The status of the file is returned.	     *
 *************************************************************/

bool DataAnalysis::openFile()
{
	mCsvStream.open("data.csv");
	if (mCsvStream.good())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*************************************************************
 * Function: readLine ()		                             *
 * Date Created: 4/14/22									 *
 * Date Last Modified: 4/14/22                               *
 * Description: This function reads in the line, splits it,  *
 *				 sets data into values, and calls to sort.	 *
 * Input parameters: A string.					             *
 * Returns: Nothing.								         *
 * Preconditions: None.					  .					 *
 * Postconditions: The line is read in succesfully.		     *
 *************************************************************/

void DataAnalysis::readLine(string line)
{
	string input, type, transaction;

	stringstream newLine(line);
	int units;

	getline(newLine, input, ',');

	if (input != "")
	{
		units = stoi(input);

		getline(newLine, input, ',');
		type = input;

		getline(newLine, input, ',');
		transaction = input;

		treeSorter(units, type, transaction);
	}
}

/*************************************************************
 * Function: readFile ()		                             *
 * Date Created: 4/14/22									 *
 * Date Last Modified: 4/14/22                               *
 * Description: This function goes through the file,	     *
 *				 calls readLine, and prints the BSTs out.    *
 * Input parameters: Nothing.					             *
 * Returns: Nothing.								         *
 * Preconditions: None.					  .					 *
 * Postconditions: The file is read in and the BSTs printed. *
 *************************************************************/

void DataAnalysis::readFile()
{
	string line;

	while (!mCsvStream.eof())
	{
		getline(mCsvStream, line);
		readLine(line);
	}

	cout << "mTreePurchased: " << endl;
	mTreePurchased.inOrderTrav();
	cout << endl;
	cout << "mTreeSold: " << endl;
	mTreeSold.inOrderTrav();
}

/*************************************************************
 * Function: treeSorter ()		                             *
 * Date Created: 4/14/22									 *
 * Date Last Modified: 4/14/22                               *
 * Description: This function seperates the data by the	     *
 *				 transaction type and inserts into the BSTs. *
 * Input parameters: An int, and two strings.	             *
 * Returns: Nothing.								         *
 * Preconditions: None.					  .					 *
 * Postconditions: The data is sorted and inserted.		     *
 *************************************************************/

void DataAnalysis::treeSorter(int units, string type, string transaction)
{
	if (transaction == "Purchased")
	{
		mTreePurchased.insert(type, units);
	}
	else if (transaction == "Sold")
	{
		mTreeSold.insert(type, units);
	}
}

/*************************************************************
 * Function: displayToScreen ()		                         *
 * Date Created: 4/14/22									 *
 * Date Last Modified: 4/14/22                               *
 * Description: This function gets the largest and smallest  *
 *				 values of both BSTs and prints them.	     *
 * Input parameters: Nothing.					             *
 * Returns: Nothing.								         *
 * Preconditions: None.					  .					 *
 * Postconditions: The values are printed succesfully.	     *
 *************************************************************/

void DataAnalysis::displayToScreen()
{
	TransactionNode pTemp;

	cout << endl;
	cout << "mTreePurchased: " << endl;
	cout << "Largest: " << endl;
	pTemp = mTreePurchased.findLargest();
	pTemp.printData();
	cout << "Smallest: " << endl;
	pTemp = mTreePurchased.findSmallest();
	pTemp.printData();
	cout << endl;
	cout << "mTreeSold: " << endl;
	cout << "Largest: " << endl;
	pTemp = mTreeSold.findLargest();
	pTemp.printData();
	cout << "Smallest: " << endl;
	pTemp = mTreeSold.findSmallest();
	pTemp.printData();
}
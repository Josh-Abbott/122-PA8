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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::getline;
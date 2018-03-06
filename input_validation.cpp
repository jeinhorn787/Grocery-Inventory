/**********************************************************************************************
** Program Name: Project 2 (Grocery List)
** Author: Jeremy Einhorn
** Date: July 18, 2017
** Description:  This is the implementation file for my Input Validation.  This program only
needs to check for a valid string and a valid positive integer.
**********************************************************************************************/


#include "input_validation.hpp"
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::remove;
using std::atoi;

//properly gathers a positive integer from the user
int getUnsignedInt()
{
	//user input is stored as string
	string input;
	//integer variable to store the returned unsigned integer
	int uint;

	do 
	{
		//getline will get every character from the string
		getline(cin, input);

		//the following code taken from 
		//https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		//end of copied code. this code will remove
		//all whitespace from the string

		//if the string is found NOT to be an unsigned integer
		if (!(isUnsignedInt(input)))
			cout << "Error.  Please enter a postitive integer." << endl;

	} while (!(isUnsignedInt(input)));

	//converts string to integer
	uint = atoi(input.c_str());

	return uint;
}

//checks to see if the string that holds the user input is in fact 
//an unsigned int
bool isUnsignedInt(string input)
{	
	bool status;
	
	for (int index = 0; index < input.size(); index++)
	{
		if (isdigit(input[index]))
			status = true;
		//if any element in the string is anything but number
		//it automatically returns false
		else
			return false;
	}

	return status;
}

//gathers a string from a user that only accepts alphabetical chars
//or whitespaces
string getString()
{
	//holds string input
	string input;

	//will continually do until a valid string is input
	do
	{
		//gathers all input including whitespaces
		getline(cin, input);

		//if the string was not entered properly, an error message
		if (!(isString(input)))
			cout << "Error.  Please input a valid string." << endl;
	} while (!(isString(input)));

	return input;
}

//checks for any non-alphabetical chars or non-spaces
bool isString(string input)
{
	bool status;
	
	for (int index = 0; index < input.size(); index++)
	{
		input[index] = tolower(input[index]);
		
		if (isalpha(input[index]) || input[index] == ' ')
			status = true;

		//if there are any non-alphabetical chars or
		//non-whitespaces
		else
			return false;
	}

	return status;
}
/**********************************************************************************************
** Program Name: Project 2 (Grocery List)
** Author: Jeremy Einhorn
** Date: July 18, 2017
** Description:  This is the implementation file for my menu. The user has 4 choices and must
choose one of the 4.
**********************************************************************************************/


#include"menu.hpp"
#include"input_validation.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int menu()
{
	int choice;

	cout << "		Grocery Menu" << endl;
	cout << "1: Add an Item" << endl;
	cout << "2: Remove an Item" << endl;
	cout << "3: Print List" << endl;
	cout << "4: Quit" << endl;

	cout << "Please enter a number, from 1 to 4, for you choice." << endl;
	//input validation for a positive integer
	choice = getUnsignedInt();

	//the user must re-enter if their choice is
	//more than 4 or less than 1
	while (choice > 4 || choice < 1)
	{
		cout << "Error.  Please choose a number from the menu list above." << endl;

		choice = getUnsignedInt();
	}

	//case numbers match the menu items
	switch (choice)
	{
	case 1:
		return 1;

	case 2:
		return 2;

	case 3:
		return 3;

	case 4:
		return 4;

	}

	return choice;
}
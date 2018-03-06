/**********************************************************************************************
** Program Name: Project 2 (Grocery List)
** Author: Jeremy Einhorn
** Date: July 18, 2017
** Description:  This is the main file.  An empty list is created upon execution of the program.
If the user chooses to add, they must input the Item's information.
**********************************************************************************************/


#include"List.hpp"
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;


int main()
{
	cout << "Welcome to the Grocery Store.  Please choose from the following options." << endl;
	cout << "An empty list is already made for you to work with." << endl;

	//an empty List is created 
	List list;
	//integer to hold the users choice
	int choice = menu();

	while (choice != 4)
	{
		//local variables to hold the info needed to create the Item
		string name, unit;
		int quantity, price;

		//if the user wants to add an Item
		if (choice == 1)
		{
			cout << "What is the name of the item?  Please enter only alphabetical characters"
				" or spaces only." << endl;
			name = getString();

			cout << "What is the unit type for the item?  Please enter only alphabetical characters"
				" or spaces only." << endl;
			unit = getString();

			cout << "How much of the item is available?  Please only enter a positive integer." << endl;
			quantity = getUnsignedInt();

			cout << "What is the cost of one unit of the item?  Please only enter a positive integer." << endl;
			price = getUnsignedInt();

			//using the info that was input, a new Item is created
			Item item(name, unit, quantity, price);

			//Item will be added to new array or new Item may update old Item
			//if there is a match
			list.addItem(item);
		}

		//if the user wants to remove an Item
		if (choice == 2)
		{
			cout << "The last item on the list will be removed." << endl;
			list.removeItem();
		}

		//if the user wants to see the list
		if (choice == 3)
			list.print();

		choice = menu();
	}


	//exit program
	if (choice == 4)
		return 0;
}
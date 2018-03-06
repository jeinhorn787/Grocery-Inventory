/**********************************************************************************************
** Program Name: Project 2 (Grocery List)
** Author: Jeremy Einhorn
** Date: July 18, 2017
** Description:  This is the implementation file for the class List.  It sets up an array of
Items then has the ability to add and remove from the array.
**********************************************************************************************/

#include"List.hpp"
#include<iostream>
using std::cout;
using std::endl;

//default constructor dynamically allocates a 4 element Item array
//that can be resized.  It is filled with default Items
List::List()
{
	//default Item
	Item newItems;
	
	listSize = 4;

	//dynamic allocation of Item array
	itemlist = new Item[listSize];

	//all elements filled with the default Item
	for (int item = 0; item < listSize; item++)
		itemlist[item] = newItems;
}

//destructor properly frees space taken to make dynamically
//allocated array for Items.  This is automatically called
//before the program terminates
List::~List()
{
	delete[] itemlist;
	itemlist = nullptr;
	listSize = 0;
}

//if the Item to be added is similar in name to an Item already in the list
//the user can either update it to the new Item or just leave it as is and no
//new Item will be added.  Otherwise, a new dynamically allocated array will
//be created that is 1 larger then the array that is already being pointed to.
//The user entered Item will be added to the new array and the oringinal pointer
//will point to the new array while freeing the old array space
void List::addItem(Item item)
{
	for (int index = 0; index < listSize; index++)
	{
		//overloaded == allows two Item names to be compared
		if (item == itemlist[index])
		{
			cout << "That item already exists in the list.  Would you like to update "
				"it with what you entered?  Type 1 for yes, 2 for no." << endl;
			//input validation for postitive integer
			int confirm = getUnsignedInt();

			//if the input is anything other than 1 or 2
			while (confirm != 1 && confirm != 2)
			{
				cout << "Error. Please only enter either 1 or 2." << endl;

				confirm = getUnsignedInt();
			}
			
			//if the user chose yes, the Item at index is now replaced with
			//the new Item the user typed out
			if (confirm == 1)
			{
				itemlist[index] = item;
				return;
			}

			//if the user chose no, the function exits
			else
				return;
		}
	}

	//dyanmically allocated array that is 1 size larger than the list size
	//before this
	Item *biggerList = new Item[listSize + 1];

	//copy all elements from the old array into the new
	//this means there is just 1 more space to fill at the end
	for (int item = 0; item < listSize; item++)
		biggerList[item] = itemlist[item];

	//free the old space and set the original pointer to
	//point to the new array
	delete[] itemlist;
	itemlist = biggerList;
	biggerList = nullptr;

	//add new Item to the very end of the new array
	itemlist[listSize] = item;

	//the list size is now 1 larger
	listSize += 1;
}

//since there are 4 default Items, if the list size is
//greater than 4, that means there is at least 1 Item
//that is not default, so it can be removed
//an array that is 1 element smaller is created
//this will remove the last Item in the array
void List::removeItem()
{
	//if list size is greater than 4, remove can execute
	if (listSize > 4)
	{
		//list size is now 1 less than before
		listSize -= 1;
		
		//dynamically allocated array that is 1 less than the last
		Item *smallerList = new Item[listSize];

		//copies all of the old Items into the new array
		for (int item = 0; item < listSize; item++)
			smallerList[item] = itemlist[item];

		//free the old array and update pointer to new array
		delete[] itemlist;
		itemlist = smallerList;
		smallerList = nullptr;
	}
}

//prints the info of all Items.  If the last element in the
//list is a default Item, this means all elements are currently
//default items and the user is told the list is empty
void List::print()
{
	//accum for grand total price of list
	int total = 0;
	
	for (int item = 0; item < listSize; item++)
	{
		//if the Item has a real name, unlike the default does
		if (itemlist[item].getName() != "")
		{
			cout << "Name: " << itemlist[item].getName() << endl;
			cout << "Unit: " << itemlist[item].getUnit() << endl;
			cout << "Quantity: " << itemlist[item].getQuantity() << endl;
			cout << "Unit Price: $" << itemlist[item].getPrice() << endl;
			cout << "Extended Price: $" << itemlist[item].extendedPrice() << endl;
			cout << endl;

			total += itemlist[item].extendedPrice();
		}
	}

	//last element is a default Item
	if (itemlist[listSize - 1].getName() == "")
		cout << "The list is empty." << endl;

	cout << "The grand total of the list is: $" << total << endl;
}

//this allows the name of two Items to be compared
//this is used in addItem() to check to see if the
//user is trying to add an Item already in the list
bool operator==(Item a, Item b)
{
	return a.getName() == b.getName();
}
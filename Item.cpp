/**********************************************************************************************
** Program Name: Project 2 (Grocery List)
** Author: Jeremy Einhorn
** Date: July 18, 2017
** Description:  This is the implementation file for the class Item.  It sets up an Item
containing it's name, it's unit type, the quantity of it, and the price of 1 of the Item.
**********************************************************************************************/

#include"Item.hpp"

//Item default constructor sets a default Item to an item with no name,
//unit type, quantity, or price
Item::Item()
{
	name = "";
	unit = "";
	quantity = 0;
	price = 0;
}

//Item constructor sets up an Item using the input from the user
Item::Item(string n, string u, int q, int p)
{
	name = n;
	unit = u;
	quantity = q;
	price = p;
}

//returns the Item's name
string Item::getName()
{
	return name;
}

//returns the Item's unit type
string Item::getUnit()
{
	return unit;
}

//returns the quantity of the Item
int Item::getQuantity()
{
	return quantity;
}

//returns the price of one of the Item
int Item::getPrice()
{
	return price;
}

//calculates the price of all of the Item that is available
int Item::extendedPrice()
{
	int eprice;

	eprice = quantity * price;

	return eprice;
}
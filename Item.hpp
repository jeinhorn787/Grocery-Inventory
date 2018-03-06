/**********************************************************************************************
** Program Name: Project 2 (Grocery List)
** Author: Jeremy Einhorn
** Date: July 18, 2017
** Description:  This is the header file for the class Item.
**********************************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include<string>
using std::string;

class Item
{
private:
	string name, unit;
	int quantity, price;

public:
	Item();
	Item(string, string, int, int);
	string getName();
	string getUnit();
	int getQuantity();
	int getPrice();
	int extendedPrice();
};

#endif
/**********************************************************************************************
** Program Name: Project 2 (Grocery List)
** Author: Jeremy Einhorn
** Date: July 18, 2017
** Description:  This is the header file for the class List.  This class will have an overloaded
== operator to use to compare Items in the list.
**********************************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include"Item.hpp"
#include"input_validation.hpp"
#include"menu.hpp"

class List
{
private:
	Item *itemlist;
	int listSize;

public:
	List();
	~List();
	void addItem(Item);
	void removeItem();
	void print();
	friend bool operator==(Item, Item);
};

#endif
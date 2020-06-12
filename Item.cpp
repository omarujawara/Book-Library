//
//  Item.cpp
//
//  Created by Omaru Jawara on 4/16/19.
//  Copyright © 2019 Omaru Jawara. All rights reserved.
//

#include <stdio.h>
#include "Item.h"
#include <iostream>

// class Item

/* Copy constructor performs member-wise copy */
Item::Item(const Item &other)
{
    id = other.id;
    price = other.price;
    title = other.title;
}


/* Create an instance from the parameter values. */
Item::Item(const int id, const string title, const double price)
{
    this->id = id;
    this->title = title;
    this->price = price;
}

/* Performs member-wise copy */
Item& Item::operator=(const Item &other)
{
    id = other.id;
    price = other.price;
    title = other.title;
    return *this;
}

/* getter for ID */
long Item::getId() const { return id; }

/* getter for price */
double Item::getPrice() const { return price; }

/* getter for title */
string Item::getTitle() const { return title; }

/*
 * Reads values from the command prompt
 */
istream& operator>>(istream &in, Item &item)
{
    in >> item.id;
    in >> item.title;
    in >> item.price;
    return in;
}

/*
 * Prints values from the command prompt
 */
ostream& operator<<(ostream &out, const Item &item)
{
    out << item.id << " ";
    out << item.title << " ";
    out << item.price << " ";
    return out;
}

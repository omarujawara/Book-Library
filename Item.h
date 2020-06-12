//
//  Item.h
//  Created by Omaru Jawara on 4/14/19.
//  Copyright © 2019 Omaru Jawara. All rights reserved.
/*
 * Name: Omaru Jawara ID: 23745948
 */
#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Item {
protected:
    
    /* holds the item's id */
    int id;
    
    /* holds the item's price*/
    double price;
    
    /* holds the item's title
     * Assume that all
     * titles are exactly 18 characters long
     */
    string title;
    
public:
    
    static const int TITLE_NUM_BYTES = 18;
    
    /* Copy constructor performs member-wise copy */
    Item(const Item &other);
    /* Create an instance from the parameter values. */
    Item(const int id, const string title, const double price);
    
    /* Performs member-wise copy */
    Item& operator=(const Item &other);
    
    /* getter for ID */
    long getId() const;
    
    /* getter for price */
    double getPrice() const;
    
    /* getter for title */
    string getTitle() const;
    
    /*
     *invoke this from the derived class' operator>>
     */
    friend istream& operator>>(istream &in, Item &item);
    
    /**
     * Prints values from the command prompt in the following order
     * 1. id
     * 2. title
     * 3. price
     *  invoke this from the derived class' operator<<
     */
    friend ostream& operator<<(ostream &out, const Item &item);
};

#endif /* ITEM_H_ */


//
//  Book.h

//
//  Created by Omaru Jawara on 4/14/19.
//  Copyright © 2019 Omaru Jawara. All rights reserved.
//
/*
 * Name: Omaru Jawara ID: 23745948
 */

#ifndef BOOK_H_
#define BOOK_H_

#include <iostream>

#include "Item.h"

using namespace std;

class Book: public Item {
    
private:
    /*  Assume that all
     * authors are exactly 10 characters long
     */
    string author;
    
public:
    
    static const int AUTHOR_NUM_BYTES = 10;
    
    Book();
    
    /**
     * Create an instance from the parameter values.
     */
    Book(const int id, const string title, const double price, const string author);
    
    /* Copy constructor performs member-wise copy */
    Book(const Book &other);
    
    
    Book& operator=(Book&other);
    
    /* getter for author */
    string getAuthor() const;
    
    /*
     * Reads values from the command prompt in
     */
    friend istream& operator>>(istream &in, Book &book);
    
    /**
     * Prints the values from the command prompt
     */
    friend ostream& operator<<(ostream &out, Book &book);
};

#endif /* BOOK_H_ */


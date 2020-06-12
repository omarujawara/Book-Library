#include "Book.h"
#include <iostream>


string file = "TestCode.txt";

// class Book
/* Creates an instance with default values
 */
Book::Book(): Item(-1,"",-1)
{
    author = "";
    
}

/**
 * Create an instance from the parameter values.
 */
Book::Book(const int id, const string title, const double price, const string author):Item(id,title,price)
{
    this->author = author;
}

/* Copy constructor performs member-wise copy */
Book::Book(const Book &other):
Item(other)
{ author = other.author; }


Book& Book::operator=(Book&other)
{
    Item::operator=(other);
    author = other.author;
    return *this;
    
}

/* getter for author */
string Book::getAuthor() const { return author; }

 istream& operator>>(istream &in, Book &book)
{
    Item *item = ((Item*)&book);
    operator>>(in,*item);
    in >> book.author;
    return in;
}

/*
 * Prints the values from the command prompt
 */
 ostream& operator<<(ostream &out, Book &book)
{
    Item *item = ((Item*)&book);
    operator<<(out,*item);
    out << book.author << endl;
    return out;
    
}


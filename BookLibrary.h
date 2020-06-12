//
//  BookLibrary.h
//  CSC 211 Final Project
//
//  Created by Omaru Jawara on 4/14/19.
//  Copyright © 2019 Omaru Jawara. All rights reserved.
/*
 * Name: Omaru Jawara ID: 23745948
 */
#ifndef BOOK_LIBRARY_H_
#define BOOK_LIBRARY_H_

const static int MAX_CHAR_ARR_SIZE = 64;

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Book.h"

using namespace std;

class BookLibrary {
private:
    vector<Book> *vecBookLibrary;
    
public:
    
    /* Initialize vector pointer */
    BookLibrary();
    
    /* deallocates membory */
    ~BookLibrary();
    
    /**
     * Adds a new book instance to the vector libarary
     */
    void add(const Book &book) const;
    
    /**
     * Reads objects from the specified binary file and adds them to the vector
     * Return true if the read operation succeeds, false otherwise.
     * Any existing objects in the vector are removed
     */
    bool loadFromFile(const string fileName);
    
    /**
     * Writes the vector to Disk in binary format. Each object is written as a
     * fixed-width character array.
     *
     * use the object's char conversion operator
     */
    bool serializeToDisk(const string fileName);
    
    /* Formats and prints the contents of the vector to the command line */
    void printFormatted() const {
        
        for (unsigned int i = 0; i < vecBookLibrary->size(); ++i)
            cout << "Book " << i << ": " << (*vecBookLibrary)[i] << endl;
    }
    
    // B
    /**
     * Reads a single object from disk NOT from the vector
     * if the index is invalid, return null
     */
    Book* readSingleObjectFromDisk(const string fileName, const unsigned int index);
    
    // B
    /**
     * Deletes an object from disk and the vector at the specified index
     * if the index is invalid, no records will be deleted
     */
    void deleteFromDisk(const string fileName, const unsigned int index);
};

#endif /* BOOK_LIBRARY_H_ */

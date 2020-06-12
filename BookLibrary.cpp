////
////  BookLibrary.cpp
////  Created by Omaru Jawara on 4/16/19.
////  Copyright © 2019 Omaru Jawara. All rights reserved.
////
//
#include <stdio.h>
#include "BookLibrary.h"
#include <iostream>

// class BookLibrary
/* Initialize vector pointer */
BookLibrary::BookLibrary() { vecBookLibrary = new vector<Book>; }

/* deallocates memory */
BookLibrary::~BookLibrary() { delete vecBookLibrary; vecBookLibrary = nullptr;}

/**
 * Adds a new book instance to the vector libarary
 */
void BookLibrary::add(const Book &book) const { vecBookLibrary->push_back(book); }

/**
 * Reads objects from the specified binary file and adds them to the vector
 * Return true if the read operation succeeds, false otherwise.
 * Any existing objects in the vector are removed
 */

bool BookLibrary::loadFromFile(const string fileName) {

    unsigned long sizeOfVector = vecBookLibrary->size() - 1;
    vecBookLibrary->clear();

    fstream read_file;
    read_file.open(fileName, ios::in|ios::binary);

    if (read_file.is_open()) {
        for (unsigned int i = 0; i < sizeOfVector; i++) {
            int id;
            read_file.read(reinterpret_cast<char *>(&id), sizeof(int));
            string title;
            read_file.read(reinterpret_cast<char *>(&title), 19);
            double price;
            read_file.read(reinterpret_cast<char *>(&price), sizeof(double));
            string author;
            read_file.read(reinterpret_cast<char *>(&author), 11);
           
            Book bookInfo(id, title, price, author);
            vecBookLibrary->push_back(bookInfo);
        }
        read_file.close();
        return true;
    }

    return false;

}

/**
 * Writes the vector to Disk in binary format. Each object is written as a
 * fixed-width character array.
 */

bool BookLibrary::serializeToDisk(const string fileName) {

    fstream write_file(fileName, ios::out | ios::binary);
    if (write_file.is_open()){
        for (unsigned int i = 0; i< vecBookLibrary->size(); i++) {
            
            long id = (*vecBookLibrary)[i].getId();
            write_file.write(reinterpret_cast<char *>(&id), sizeof(int));

            string title = (*vecBookLibrary)[i].getTitle();
            write_file.write(reinterpret_cast<char *>(&title), 19);

            double price = (*vecBookLibrary)[i].getPrice();
            write_file.write(reinterpret_cast<char *>(&price), sizeof(double));

            string author = (*vecBookLibrary)[i].getAuthor();
            write_file.write(reinterpret_cast<char *>(&author), 11);
        }
        write_file.flush();
        write_file.close();
        return true;
    }
    return false;
}



/**
 * Reads a single object from disk NOT from the vector
 * if the index is invalid, return null
 */
 Book* BookLibrary::readSingleObjectFromDisk(const string fileName, const unsigned int index){
     int count =1;  
     int id; double price; string title,author;
     fstream read_file(fileName,ios::in|ios::binary);
     if (read_file.is_open()) {
         if((index >= 1) && (index <= 20)){
             while (!read_file.eof()) {
                 read_file.read(reinterpret_cast<char *>(&id),sizeof(int));
                 read_file.read(reinterpret_cast<char *>(&title),19);
                 read_file.read(reinterpret_cast<char *>(&price),sizeof(double));
                 read_file.read(reinterpret_cast<char *>(&author),11);
                 if ( count == index) {
                     Book* ptrBook = new Book(id,title,price,author);
                     return ptrBook;
                 }
                 count++;
             }
         }
     }
        return NULL;
     
 }


/**
 * Deletes an object from disk and the vector at the specified index
 * if the index is invalid, no records will be deleted
 */
  void BookLibrary::deleteFromDisk(const string fileName, const unsigned int index){
      fstream read_file;
      read_file.open(fileName,ios::in|ios::binary);
      if(read_file.is_open()){
          vector<Book>* newVector = new vector<Book>;
          for (unsigned int i = 0 ; i < vecBookLibrary->size(); ++i) {
              if (!(i == index))
                  newVector->push_back((*vecBookLibrary)[i]);
          }
          vecBookLibrary = newVector;
//          delete newVector;
//          newVector = nullptr;
      }
      else
       cout << "File cannot be opened " << endl;
  }



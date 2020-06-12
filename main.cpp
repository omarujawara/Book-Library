//
//  main.cpp
//
//  Created by Omaru Jawara on 4/14/19.
//  Copyright © 2019 Omaru Jawara. All rights reserved.
//

/*
 * Name: Omaru Jawara ID: 23745948
 */

#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "BookLibrary.h"

using namespace std;


const string LIBRARY_OUTPUT_FILE = "bookLibrary";

int main() {

    BookLibrary bookLibrary;
    // read 20 test records from command line
    // each record is added to the instance BookLibrary
    for (int i = 0; i < 20; ++i) {
        
        cout << "Enter books # " << (i + 1) << " (ID, Title, Price, Author): ";
        
        Book book;
        cin >> book;
        bookLibrary.add(book);
        
        cout << endl;
    }
    
    cout << " -----------------------------------\n";
    cout << "|    Test #1: Write to disk call    |\n";
    cout << " ----------------------------------" << endl;
    
    bool result = bookLibrary.serializeToDisk(LIBRARY_OUTPUT_FILE);
    
    if (result)
        cout << "Write to disk succeeded.";
    else {
        
        cout << "Write to disk Failed" << endl;
        return 0;
    }
    
    cout << endl << endl << endl;
    cout << " -----------------------------------\n";
    cout << "|    Test #2: Reading from disk     |\n";
    cout << " ----------------------------------" << endl;
    
    // test for loading vector from binary file
    // the dummyBook object should not be printed
    Book dummyBook;
    bookLibrary.add(dummyBook);

    result = bookLibrary.loadFromFile(LIBRARY_OUTPUT_FILE);

    if (result)
        bookLibrary.printFormatted();
    else
        cout << "Load operation Failed" << endl;

    // Uncomment for the bonus question
    
     cout << endl << endl << endl;
     cout << " --------------------------------------------\n";
     cout << "|    Test #3: Reading 1 object from disk     |\n";
     cout << " --------------------------------------------" << endl;

     cout << " The 2nd book: ";
     cout << *bookLibrary.readSingleObjectFromDisk(LIBRARY_OUTPUT_FILE, 2) << endl;

     cout << endl << endl << endl;
     cout << " --------------------------------------------\n";
     cout << "|    Test #4: Deleting 1 object from disk    |\n";
     cout << " --------------------------------------------" << endl;
      bookLibrary.deleteFromDisk(LIBRARY_OUTPUT_FILE, 1);

     bookLibrary.printFormatted();
    
    return 0;
}

#include "WordCatVec.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

char WordCatVec::menu()
{
    cout << "=========  Menu: =========\n";
    cout << "1. Print all Categories\n";
    cout << "2. Add a New Category (sorted)\n";
    cout << "3. Remove a Category\n";
    cout << "4. Clear a Category\n";
    cout << "5. Interact with a Category\n";
    cout << "6. Show Words in All Categories (Sorted)\n";
    cout << "7. Show All Categories (Sorted Individually)\n";
    cout << "8. Load from Text File\n";
    cout << "9. Save to Text File\n";
    cout << "0. Exit\n";
    char choice;
    cin >> choice; // user inputs a character
    return choice;
}

void WordCatVec::handleOption(int option)
{
    string name;
    string filename;
    vector<string> allWords; // a vector to hold all words from all categories
    switch (option)
    {
    case '1':
        if (theVector.empty()) // if the vector is empty
        {
            cout << "\nNo categories.\n\n";
        }
        else
            cout << "\nCategories:\n";
        cout << *this; // calls the overloaded << operator to print the current WordCatVec object / current instance of the class WordCatVec
                       // * this is a pointer (to the current object)
                       // we know what is the current object because we are inside a member function of that class -> WordCatVec::handleOption(int option)
                       //// Since WordCatVec contains a vector<WordCat>, the function can iterate over this vector and print each WordCat.
        break;
    case '2':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do
        {
            cout << "Enter new category name: ";
            getline(cin, name);

            if (name != "exit")
            {

                theVector.push_back(WordCat(name));
                sort(theVector.begin(), theVector.end(), [](const WordCat &a, const WordCat &b)
                     { return a.getCatName() < b.getCatName(); });
            }
        } while (name != "exit");
        break;
    case '3':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter category name to remove: ";
        getline(cin, name);
        theVector.erase(remove_if(theVector.begin(), theVector.end(), [&](const WordCat &wc)
                                  { return wc.getCatName() == name; }),
                        theVector.end());
        break;
    case '4':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter category name to clear: ";
        getline(cin, name);
        for (auto &wc : theVector) // for each WordCat object in the vector
        {
            if (wc.getCatName() == name) // if the category name matches the input
            {
                // get the WordList object from the WordCat object and clear it
                wc.getWordList().clear();
            }
        }
        break;
    case '5':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter category name to interact with: ";
        getline(cin, name);
        for (auto &wc : theVector) // for each WordCat object in the vector
        {
            if (wc.getCatName() == name) // if the category name matches the input
            {
                wc.run(); // call the run function of the WordCat object
            }
        }
        break;
    case '6': // display all words of every category mixed together (sorted)
              // Create a new vector to hold all words

        // Add all words from all categories to the new vector
        for (const auto &wc : theVector)
        {
            vector<string> words = wc.getWords(); //  getWords() returns the words of a category
            allWords.insert(allWords.end(), words.begin(), words.end());
        }

        // Sort the new vector
        sort(allWords.begin(), allWords.end());

        // Print the sorted words
        for (const auto &word : allWords)
        {
            cout << word << '\n';
        }

        break;
        // display cateogries and their words, sorted alphabetically
    case '7': // sort the vector of WordCat objects by category name (alphabetically)
              // sort takes 3 arguments: the start of the range, the end of the range, and a lambda function
              // // the lambda function takes two WordCat objects as arguments (a and b) and returns a boolean
        sort(theVector.begin(), theVector.end(), [](const WordCat &a, const WordCat &b)
             {
    string catNameA = a.getCatName();
    string catNameB = b.getCatName();

    return catNameA < catNameB; }); // if true the first object will be placed before the second object (so goes from a to z)

        // CAPTURE LIST (uncecessary and empty in this case)
        // the [] is the capture list, which captures variables from the surrounding scope (surrounding scope meaning the return value(s) of the lambda function)
        // [=] captures all variables in the lambda by value (gets copy of values and does not affect original values)
        // [&] captures all variables by reference
        //[var]: Capture the variable var by value.
        //[&var]: Capture the variable var by reference.
        //[=, &var]: Capture all variables by value, but capture var by reference.
        //[&, var]: Capture all variables by reference, but capture var by value.

        for (const auto &wc : theVector)
        {
            cout << wc.getCatName() << '\n';
            wc.show_sorted(cout, 1);
        }
        break;
    case '8':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter filename to load from: ";
        getline(cin, filename);
        loadFromFile(filename);
        break;
    case '9':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter filename to save to: ";
        getline(cin, filename);
        saveToFile(filename);
        break;
    case '0':
        cout << "Goodbye!\n";
        break;
    default:
        cout << "Invalid option. Please try again.\n";
        break;
    }
}

void WordCatVec::run()
{
    char choice;
    do
    {
        choice = menu();      // calls the menu function and stores the return value in choice
        handleOption(choice); // calls the handleOption function with the choice as an argument
    } while (choice != '0');
}

void WordCatVec::write(ostream &sout, int n) const // eg. wcv.write(cout, 5);
{
    for (const auto &wc : theVector) // for each WordCat object in the vector
    {
        wc.write(sout, n);
    }
}

void WordCatVec::saveToFile(const string &filename) const
{
    ofstream outFile(filename, ios::app); // ios::app appends to the end of the file rather than overwriting it
    if (!outFile)                         // if the file cannot be opened
    {
        cerr << "Error opening file for writing: " << filename << '\n';
        return;
    }
    for (const auto &wc : theVector) // for each WordCat object in the vector
    {
        wc.saveToFile(filename); // save the WordCat object to the file
    }
    outFile.close();
}

void WordCatVec::loadFromFile(const string &filename)
{
    ifstream inFile(filename); // open the file
    if (!inFile)               // if the file cannot be opened
    {
        cerr << "Error opening file for reading: " << filename << '\n';
        return;
    }

    string line;                  // a string to store each line of the file
    while (getline(inFile, line)) // read each line from the file
    {
        if (line[0] == '#')
        {
            string categoryName = line.substr(1);
            WordCat wc(categoryName);
            wc.loadFromFile(filename);
            theVector.push_back(move(wc));
        }
    }

    inFile.close();
}

ostream &operator<<(ostream &out, const WordCatVec &wcv) // eg. cout << wcv;
{
    wcv.write(out, 1); // calls the write function with the output stream and 5 as arguments
    return out;
}

#include "WordCat.h"
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

// Conversion constructor : creating a WordCat object from a string
// eg WordCat wc = "Category Name"; means that wc is a WordCat object with the name "Category Name"
WordCat::WordCat(const string &name) : cat_name(name), word_list() {}

char WordCat::menu()
{
    cout << "\n=========  Menu: =========\n";
    cout << "1. Print Words in Category\n";
    cout << "2. Append Word to Category\n";
    cout << "3. Remove Word from Category\n";
    cout << "4. Clear Category\n";
    cout << "5. Modify Category Name\n";
    cout << "6. Search for Word in Category\n";
    cout << "7. Show Sorted Words in Category\n";
    cout << "8. Load Category from Text File\n";
    cout << "9. Save Category to Text File\n";
    cout << "0. Exit\n";
    char choice;
    cin >> choice;
    return choice;
}

void WordCat::handleOption(int option)
{
    string word; // these variables are declared here because they are only used in this function
    string filename;
    switch (option)
    {
    case '1':
        // if empty list, print "No words in category."
        if (word_list.isEmpty())
        {
            cout << "No words in category.\n";
        }
        else
            cout << "Category Name:" << cat_name << '\n'
                 << word_list << "\n\n"; // calls the overloaded << operator to print the current WordList object / current instance of the class WordList
        break;
    case '2':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        do
        {
            cout << "Enter word to append: "; // adds word to the end of the list
            getline(cin, word);
            // getline reads a line from the input stream and stores it in the word variable
            if (word != "exit")
            {

                word_list.push_back(Word(word)); // makes word into a Word object and adds it to the end of the list
            }
        } while (word != "exit");
        break;
    case '3':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter word to remove: ";
        getline(cin, word);
        word_list.remove(Word(word));
        break;
    case '4':
        word_list.clear();
        break;
    case '5':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter new category name: ";
        getline(cin, cat_name); // public member functions of a class have access to the private members of the class, but functions in other classes do not
        break;
    case '6':
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter word to search: ";
        getline(cin, word);
        if (word_list.lookup(Word(word)))
        {
            cout << "Word found in category.\n";
        }
        else
        {
            cout << "Word not found in category.\n";
        }
        break;
    case '7':
        cout << "Sorted words of " << cat_name << endl;
        show_sorted(cout, 1); // cout is the output stream, 5 is the number of words per line
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
        cout << "Exiting...\n";
        break;
    default:
        cout << "Invalid option. Please try again.\n";
        break;
    }
}

void WordCat::run()
{
    char choice;
    do // at least one iteration of the loop
    {
        choice = menu();      // calling the menu function and assigning the return value to choice
        handleOption(choice); // calling the handleOption function with the choice as an argument
    } while (choice != '0'); // display menu while choice is not 0
}

// sout vs cout : sout is an output stream that is passed as an argument to the function
// cout is the standard output stream
// so could feed cout or ofstream (object for writing to a file) to sout
// ofstream outFile("filename.txt"); creates a file called filename.txt
// outFile is an object / instance of class found in fstream library

void WordCat::write(ostream &sout, int n) const
{
    int wordsPerLine = 5;
    sout << "\n\nCategory Name:" << cat_name << "\n";
    word_list.write(sout, wordsPerLine); // referring to the write function in WordList.cpp so need to input a number of how many words per line
}

void WordCat::show_sorted(ostream &sout, int n) const
{
    forward_list<Word> sorted_list = word_list.getSinglyLinkedList(); // want a singly linked list because it is faster to sort
                                                                      // don't just use word_list because it is a doubly linked list
    // Sort the list in a case-insensitive manner
    sorted_list.sort([](const Word &a, const Word &b)
                     {
        string lower_a = a.getWordAsString(), lower_b = b.getWordAsString();
        transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b; });               // .sort() sorts the list in ascending order
    for (const auto &word : sorted_list) // for each word in the list
    {
        sout << word << '\n';
    }
    sout << '\n';
}

// eg. .saveToFile("filename.txt") saves the category to a file called filename.txt
void WordCat::saveToFile(const string &filename) const
{
    ofstream outFile(filename, ios::app); // ios::app appends to the end of the file rather than overwriting it ! if did not write ios::app, it would overwrite the file
    if (!outFile)                         // if the file cannot be opened
    {
        cerr << "Error opening file for writing: " << filename << '\n';
        return;
    }
    // else
    outFile << "#" << cat_name << '\n'; // # is used to indicate the start of a category
    word_list.write(outFile, 1);        // write function handles the writing of the words to the file since takes an output stream as an argument
    //  !!!!!!! ATTENTION : scared that it will double the categoryName since it is already written in the write function !!!!!!!!!!
    outFile.close(); // close the file
}

void WordCat::loadFromFile(const string &filename)
{
    ifstream inFile(filename); // inFile is an object of the ifstream class that reads from a file
    if (!inFile)
    {
        cerr << "Error opening file for reading: " << filename << '\n';
        return;
    }

    string line; // create a string variable called line
    bool categoryFound = false;

    while (getline(inFile, line)) // while getLine returns true (ie. there is a line to read)
    {
        if (line == "#" + cat_name)
        {
            categoryFound = true;
            break;
        }
    }

    if (!categoryFound)
    {
        cerr << "Category not found in file: " << cat_name << '\n';
        return;
    }

    while (getline(inFile, line) && !line.empty() && line[0] != '#') // while the line is not empty and does not start with a #
    {
        word_list.push_back(Word(line)); // add the word to the end of the list
    }

    inFile.close(); // stop reading from the file
}

ostream &operator<<(ostream &sout, const WordCat &wc)
{
    wc.write(sout, 10);
    return sout;
}

// Get the name of the category
string WordCat::getCatName() const
{
    return cat_name;
}

// Get the list of words in the category
WordList &WordCat::getWordList()
{
    return word_list;
}

vector<string> WordCat::getWords() const
{
    vector<string> words;
    for (const auto &word : word_list.getSinglyLinkedList())
    {
        words.push_back(word.getWordAsString());
    }
    return words;
}

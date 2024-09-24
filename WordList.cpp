#include "WordList.h"
using namespace std;

Word &WordList::front() { return theList.front(); } // .front() returns a reference to the first element in the list
Word &WordList::back() { return theList.back(); }   // .back() returns a reference to the last element in the list
const Word &WordList::front() const { return theList.front(); }
const Word &WordList::back() const { return theList.back(); }
// the difference between const and non-const functions is that the const functions do not modify the object
// the reason why we need both is because the compiler will not allow us to call a non-const function on a const object

void WordList::push_front(const Word &word) { theList.push_front(word); } // .push_front() adds an element to the front of the list
void WordList::push_back(const Word &word) { theList.push_back(word); }   // .push_back() adds an element to the back of the list
void WordList::pop_front() { theList.pop_front(); }                       // .pop_front() removes the first element in the list
void WordList::pop_back() { theList.pop_back(); }                         // .pop_back() removes the last element in the list
void WordList::remove(const Word &word) { theList.remove(word); }         // .remove() removes all elements in the list that are equal to the argument
// all these . functions are member functions of the std::list class

Word WordList::get(int n) // takes parameter n and returns the nth element in the list
{
    auto it = theList.begin(); // auto is a placeholder for the type of the variable
                               // it is used when the type of the variable is too long or too complicated to write out
                               // .begin() returns an iterator to the first element in the list
                               // an iterator is a pointer to an element in the list
                               // it is not like .front() which returns a reference to the first element
                               // the reason why we use an iterator is because we can use it to traverse the list
    std::advance(it, n);       // .advance() moves the iterator n elements forward
    return *it;
}

// .write() writes the contents of the list to the output stream sout
// the n parameter is the number of elements to write to the output stream before starting a new line
void WordList::write(std::ostream &sout, int n) const
{
    int count = 0;
    for (const auto &word : theList) // the : operator means "in" so this loop reads as "for each word in the list" that you can't modify
    {
        sout << word << ' ';  // print the word to the output stream
        if (++count % n == 0) // and if you reach the nth word
        {
            sout << '\n'; // skip to the next line
                          // ps, The ++count inside the loop is doing exactly what you want: incrementing count by 1 on each iteration of the loop it is in.
        }
    }
}

bool WordList::isEmpty() const { return theList.empty(); } // .empty() returns true if the list is empty, false otherwise

bool WordList::lookup(const Word &word) const
{
    for (const auto &w : theList) // for every word (variable here called w, could be anything) in the list
    {
        if (w == word) // if the word is equal to the argument / pararmeter word you passed in
        {
            return true;
        }
    }
    return false; // else return false
}

std::forward_list<Word> WordList::getSinglyLinkedList() const // .getSinglyLinkedList() returns a singly linked list of the elements in the list
{
    return std::forward_list<Word>(theList.begin(), theList.end()); // forward_list is a singly linked list
}

void WordList::clear() { theList.clear(); } // .clear() removes all elements from the list

std::ostream &operator<<(std::ostream &sout, const WordList &wordList) // << is the stream insertion operator
{
    wordList.write(sout, 1); // write the contents of the list to the output stream
    return sout << endl;     // return the output stream and skip to the next line
}

#ifndef WORDLIST_H
#define WORDLIST_H

#include "Word.h"
#include <stdexcept>
#include <iostream>
#include <list>
#include <forward_list>

class WordList
{
private:
    std::list<Word> theList; // list<Word> is a doubly linked list

public:
    /**
     * Default constructor. Initializes an empty WordList.
     */
    WordList() = default;

    /**
     * Copy constructor. Creates a new WordList as a copy of an existing one.
     * @param array The WordList to copy.
     */
    WordList(const WordList &array) = default;

    /**
     * Move constructor. Creates a new WordList by moving the contents of an existing one.
     * @param array The WordList to move.
     */
    WordList(WordList &&array) = default;

    /**
     * Copy assignment operator. Copies the contents of one WordList to another.
     * @param rhs The WordList to copy.
     * @return A reference to the WordList that the contents were copied to.
     */
    WordList &operator=(const WordList &rhs) = default;

    /**
     * Move assignment operator. Moves the contents of one WordList to another.
     * @param rhs The WordList to move.
     * @return A reference to the WordList that the contents were moved to.
     */
    WordList &operator=(WordList &&rhs) = default;

    /**
     * Destructor. Cleans up when a WordList is destroyed.
     */
    virtual ~WordList() = default;

    /**
     * Returns a reference to the first Word in the list.
     * @return A reference to the first Word in the list.
     */
    Word &front();

    /**
     * Returns a reference to the last Word in the list.
     * @return A reference to the last Word in the list.
     */
    Word &back();

    /**
     * Returns a const reference to the first Word in the list.
     * @return A const reference to the first Word in the list.
     */
    const Word &front() const;

    /**
     * Returns a const reference to the last Word in the list.
     * @return A const reference to the last Word in the list.
     */
    const Word &back() const;

    /**
     * Adds a Word to the front of the list.
     * @param word The Word to add.
     */
    void push_front(const Word &word);

    /**
     * Adds a Word to the back of the list.
     * @param word The Word to add.
     */
    void push_back(const Word &word);

    /**
     * Removes the first Word from the list.
     */
    void pop_front();

    /**
     * Removes the last Word from the list.
     */
    void pop_back();

    /**
     * Removes all occurrences of a specific Word from the list.
     * @param word The Word to remove.
     */
    void remove(const Word &word);

    /**
     * Returns the Word at a specific position in the list.
     * @param n The position of the Word to return.
     * @return The Word at the specified position.
     */
    Word get(int n);

    /**
     * Writes the contents of the list to an output stream, with a specified number of words per line.
     * @param sout The output stream to write to.
     * @param n The number of words per line.
     */
    void write(std::ostream &sout, int n = 5) const;

    /**
     * Returns true if the list is empty, false otherwise.
     * @return True if the list is empty, false otherwise.
     */
    bool isEmpty() const;

    /**
     * Returns true if a specific Word is in the list, false otherwise.
     * @param word The Word to look for.
     * @return True if the Word is in the list, false otherwise.
     */
    bool lookup(const Word &word) const;

    /**
     * Removes all Words from the list.
     */
    void clear();

    /**
     * Returns a singly linked list containing the same words as this list.
     * @return A singly linked list containing the same words as this list.
     */
    std::forward_list<Word> getSinglyLinkedList() const;

    /**
     * @brief Output stream operator overload for WordList.
     * @param sout The output stream.
     *
     */
    friend std::ostream &operator<<(std::ostream &sout, const WordList &wl);
};

#endif // WORDLIST_H
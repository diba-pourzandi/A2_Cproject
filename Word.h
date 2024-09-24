#ifndef WORD_H // to avoid multiple inclusion
#define WORD_H

#include <string>
#include <iostream>
using namespace std;

class Word
{
private:
    string word;

public:
    /**
     * Default constructor. Initializes an empty Word.
     */
    Word() = default;

    /**
     * Copy constructor. Creates a new Word as a copy of an existing one.
     * @param other The Word to copy.
     */
    Word(const Word &other) = default;

    /**
     * Move constructor. Creates a new Word by moving the contents of an existing one.
     * @param other The Word to move.
     */
    Word(Word &&other) noexcept = default;

    /**
     * Copy assignment operator. Copies the contents of one Word to another.
     * @param other The Word to copy.
     * @return A reference to the Word that the contents were copied to.
     */
    Word &operator=(const Word &other) = default;

    /**
     * Move assignment operator. Moves the contents of one Word to another.
     * @param other The Word to move.
     * @return A reference to the Word that the contents were moved to.
     */
    Word &operator=(Word &&other) noexcept = default;

    /**
     * Destructor. Cleans up when a Word is destroyed.
     */
    ~Word() = default;

    /**
     * Constructor that initializes the Word with a string.
     * @param input The string to initialize the Word with.
     */
    Word(const string &input);

    /**
     * Sets the Word to a copy of another Word.
     * @param input The Word to copy.
     */
    void set(const Word &input);

    /**
     * Sets the Word to a string.
     * @param input The string to set the Word to.
     */
    void set(const string &input);

    /**
     * Returns the Word as a string.
     * @return The Word as a string.
     */
    string get() const;

    /**
     * Returns a copy of the Word.
     * @return A copy of the Word.
     */
    Word getWord() const;

    /**
     * Returns the Word as a string.
     * @return The Word as a string.
     */
    string getWordAsString() const;

    /**
     * Returns the length of the Word.
     * @return The length of the Word.
     */
    size_t length() const;

    /**
     * Returns the Word as a C-style string.
     * @return The Word as a C-style string.
     */
    const char *c_str() const;

    /**
     * Changes the Word to a new Word.
     * @param newWord The new Word.
     */
    void changeWord(const Word &newWord);

    /**
     * Changes the Word to a new string.
     * @param newWord The new string.
     */
    void changeWord(const string &newWord);

    /**
     * Concatenates the Word with another Word, with an optional delimiter.
     * @param other The Word to concatenate.
     * @param delimiter The delimiter to use. Defaults to " ".
     * @return The concatenated Word.
     */
    Word concat(const Word &other, const string &delimiter = " ") const;

    /**
     * Returns true if the Word is less than another Word, false otherwise.
     * @param other The Word to compare to.
     * @return True if the Word is less than the other Word, false otherwise.
     */
    bool isLess(const Word &other) const;

    /**
     * Returns the character at a specific position in the Word.
     * @param n The position of the character to return.
     * @return The character at the specified position.
     */
    char at(size_t n) const;

    /**
     * Prints the Word to an output stream.
     * @param os The output stream to print to.
     */
    void write(ostream &os) const;

    /**
     * Reads a Word from an input stream.
     * @param is The input stream to read from.
     */
    void read(istream &is);

    /**
     * Overloads the << operator to print a Word to an output stream.
     * @param os The output stream to print to.
     * @param word The Word to print.
     * @return The output stream.
     */
    friend ostream &operator<<(ostream &os, const Word &word);

    /**
     * Overloads the >> operator to read a Word from an input stream.
     * @param is The input stream to read from.
     * @param word The Word to read into.
     * @return The input stream.
     */
    friend istream &operator>>(istream &is, Word &word);

    /**
     * Overloads the >= operator to compare two Words.
     * @param other The Word to compare to.
     * @return True if the Word is greater than or equal to the other Word, false otherwise.
     */
    bool operator>=(const Word &other) const;

    /**
     * Overloads the <= operator to compare two Words.
     * @param other The Word to compare to.
     * @return True if the Word is less than or equal to the other Word, false otherwise.
     */
    bool operator<=(const Word &other) const;

    /**
     * Overloads the < operator to compare two Words.
     * @param other The Word to compare to.
     * @return True if the Word is less than the other Word, false otherwise.
     */
    bool operator<(const Word &other) const;

    /**
     * Overloads the == operator to compare two Words.
     * @param other The Word to compare to.
     * @return True if the Word is equal to the other Word, false otherwise.
     */
    bool operator==(const Word &other) const;
};

#endif // WORD_H

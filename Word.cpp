#include "Word.h"

/* NOT NECESSARY BECAUSE WE ARE USING DEFAULT CONSTRUCTORS, DESTRUCTORS, AND OPERATORS
// Word:: is a scope resolution operator, used to define member functions outside of the class definition (class definition is in Word.h)

// Default constructor : (Word w;)
Word::Word() : word("") {} // Word() (in yellow here) takes in no arguments, so we set the word (seen in blue) to an empty string

// Copy constructor (Word w1(w2);)
Word::Word(const Word &other) : word(other.word) {} // the word member of the other object is copied to the word member of the new object

// Move constructor (Word w1 = move(w2);)
Word::Word(Word &&other) noexcept : word(move(other.word)) {}
// move is a function that casts its argument to an rvalue reference
// rvalue (&&) references are references that can bind to temporary objects
// in this case, w2 is moving its word to w1, so w2's word is now empty / unspecified
// noexcept is a specifier that tells the compiler that the program will terminate if it throws an exception

// Copy assignment operator (Word w1 = w2;)
Word &Word::operator=(const Word &other)
{
    if (this != &other)
    {
        word = other.word;
    }
    return *this; // else
}

// Move assignment operator
Word &Word::operator=(Word &&other) noexcept
{
    if (this != &other)
    {
        word = move(other.word); // use move to cast other.word to an rvalue reference instead of copying it
    }
    return *this;
}

// Destructor
Word::~Word(){}; // no need to do anything here because string automatically manages memory and ~ denotes a destructor

*/

// Conversion constructor : Word w("hello") or Word w = "hello";
Word::Word(const string &input) : word(input) {} // "&" allows the function to access the input argument directly, rather than creating a copy of it.
                                                 // const means that the function promises not to modify the input argument, so can accept a const string (or not)

// Other member functions

// set *this to word
void Word::set(const Word &input) { word = input.word; } // sets the word to the input word
// eg. Word w1("hello"); Word w2("world"); w1.set(w2); // w1 = "world"

void Word::set(const string &input) { word = input; } // sets the word to the input string
// eg. Word w; w.set("hello");

string Word::get() const { return word; } // returns the word
// eg. Word w("hello"); string s = w.get(); // s = "hello"

Word Word::getWord() const { return *this; } // returns the word
// eg. Word w("hello"); Word w2 = w.getWord(); // w2 = "hello"

string Word::getWordAsString() const { return word; } // returns the word as a string

size_t Word::length() const { return word.length(); }
// size_t is a positive integer type, used for sizes of objects

const char *Word::c_str() const { return word.c_str(); } // returns a pointer to the first character of the string

// eg. Word w("hello"); w.changeWord("world");
void Word::changeWord(const Word &newWord) { word = newWord.word; }

void Word::changeWord(const string &newWord) { word = newWord; }
// diference between the two functions is that one takes a Word object and the other takes a string object
// eg  Word w("hello"); w.changeWord("world") vs Word w("hello"); Word w2("world"); w.changeWord(w2);

Word Word::concat(const Word &other, const string &delimiter) const { return Word(word + delimiter + other.word); }
// delimiter is a string that separates the two words
// eg . Word w1("hello"); Word w2("world"); Word w3 = w1.concat(w2, " "); // w3 = "hello world"

bool Word::isLess(const Word &other) const { return word < other.word; }
// returns true if the word is less than the other word (in lexicographical order)

char Word::at(size_t n) const { return word.at(n); }
// returns the character at the nth position in the word

void Word::write(ostream &os) const { os << word; } // printing the word variable of the Word object
// prints the word to the output stream
// eg. Word w("hello"); w.print(cout); // prints "hello"

void Word::read(istream &is) { is >> word; }
// reads a word from the input stream
// eg. Word w; w.read(cin); // reads a word from the user

std::istream &operator>>(std::istream &in, Word &word)
{
    // Use Word's read function to read from the input stream
    word.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Word &word)
{
    // Use Word's write function to write to the output stream
    word.write(out);
    return out;
}

bool Word::operator>=(const Word &other) const { return word >= other.word; }
// returns true if the word is greater than or equal to the other word

bool Word::operator<=(const Word &other) const { return word <= other.word; }

bool Word::operator<(const Word &other) const { return word < other.word; }

bool Word::operator==(const Word &other) const { return word == other.word; }
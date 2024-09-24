#ifndef WORDCAT_H
#define WORDCAT_H

#include "WordList.h"
#include <string>
#include <vector>

/**
 * @class WordCat
 * @brief Models a list of Word objects in a category.
 */
class WordCat
{
private:
    std::string cat_name; ///< The name of this category.
    WordList word_list;   ///< The underlying container storing the words in this category.
    vector<string> words; ///< The list of words in this category but as a vector of strings

    /**
     * @brief Displays a menu of options and prompts for user input.
     * @return The selected menu option.
     */
    char menu(); // menu is private because it is only used by the WordCat class

    /**
     * @brief Handles the selected menu option.
     * @param option The selected menu option.
     */
    void handleOption(int option);

public:
    /**
     * @brief Default constructor is deleted.
     */
    WordCat() = delete;

    /**
     * @brief Constructs a WordCat with the given name.
     * @param name The name of the category.
     */
    WordCat(const std::string &name);

    /**
     * @brief Copy constructor.
     */
    WordCat(const WordCat &other) = default;

    /**
     * @brief Move constructor.
     */
    WordCat(WordCat &&other) = default;

    /**
     * @brief Copy assignment operator.
     * @return A reference to this WordCat.
     */
    WordCat &operator=(const WordCat &other) = default;

    /**
     * @brief Move assignment operator.
     * @return A reference to this WordCat.
     */
    WordCat &operator=(WordCat &&other) = default;

    /**
     * @brief Destructor.
     */
    virtual ~WordCat() = default;

    /**
     * @brief Runs the menu-driven interface for this WordCat.
     */
    void run();

    /**
     * @brief Writes the category name and words to the output stream.
     * @param sout The output stream.
     * @param n The number of words per line.
     */
    void write(std::ostream &sout, int n) const;

    /**
     * @brief Writes the sorted words in the category to the output stream.
     * @param sout The output stream.
     * @param n The number of words per line.
     */
    void show_sorted(std::ostream &sout, int n) const;

    /**
     * @brief Saves the category to a specified text file.
     * @param filename The name of the file to save to.
     */
    void saveToFile(const std::string &filename) const;

    /**
     * @brief Loads the category from a specified text file.
     * @param filename The name of the file to load from.
     */
    void loadFromFile(const std::string &filename);

    /**
     * @brief Output stream operator overload for WordCat.
     * @param out The output stream.
     * @param wc The WordCat object to output.
     * @return The output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const WordCat &wc);

    /**
     * @brief Returns the name of this category.
     * @return The name of this category.
     */
    std::string getCatName() const;

    /**
     * @brief Returns the list of words in this category.
     * @return The list of words in this category.
     */
    WordList &getWordList();

    /**
     * @brief Returns the list of words in this category.
     * @return The list of words in this category.
     */
    vector<string> getWords() const;

#endif // WORDCAT_H
};

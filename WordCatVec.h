#ifndef WORDCATVEC_H
#define WORDCATVEC_H

#include "WordCat.h"
#include <vector>
#include <string>

/**
 * @class WordCatVec
 * @brief Models a list of WordCat objects.
 */
class WordCatVec
{
private:
    std::vector<WordCat> theVector; ///< The underlying container storing WordCat objects.

    /**
     * @brief Displays a menu of options and prompts for user input.
     * @return The selected menu option.
     */
    char menu();

    /**
     * @brief Handles the selected menu option.
     * @param option The selected menu option.
     */
    void handleOption(int option);

public:
    /**
     * @brief Default constructor.
     */
    WordCatVec() = default;

    /**
     * @brief Copy constructor.
     */
    WordCatVec(const WordCatVec &other) = default;

    /**
     * @brief Move constructor.
     */
    WordCatVec(WordCatVec &&other) = default;

    /**
     * @brief Copy assignment operator.
     * @return A reference to this WordCatVec.
     */
    WordCatVec &operator=(const WordCatVec &other) = default;

    /**
     * @brief Move assignment operator.
     * @return A reference to this WordCatVec.
     */
    WordCatVec &operator=(WordCatVec &&other) = default;

    /**
     * @brief Destructor.
     */
    virtual ~WordCatVec() = default;

    /**
     * @brief Runs the menu-driven interface for this WordCatVec.
     */
    void run();

    /**
     * @brief Writes the categories and their words to the output stream.
     * @param sout The output stream.
     * @param n The number of words per line.
     */
    void write(std::ostream &sout, int n) const;

    /**
     * @brief Saves the categories to a specified text file.
     * @param filename The name of the file to save to.
     */
    void saveToFile(const std::string &filename) const;

    /**
     * @brief Loads the categories from a specified text file.
     * @param filename The name of the file to load from.
     */
    void loadFromFile(const std::string &filename);

    /**
     * @brief Output stream operator overload for WordCatVec.
     * @param out The output stream.
     * @param wcv The WordCatVec object to output.
     * @return The output stream.
     */
    friend std::ostream &operator<<(std::ostream &out, const WordCatVec &wcv);
};

#endif // WORDCATVEC_H

/*
    The purpose of this task is to implement a program that calculates the approximate grade level needed to comprehend some text. 
    The program should print as output “Grade X” where “X” is the grade level computed, rounded to the nearest integer. 
    If the grade level is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the program should output “Grade 16+” instead of giving the exact index number. 
    If the grade level is less than 1, it should output “Before Grade 1”.
*/

#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <cmath>

// Prototype the functions
int CountWords(const std::string&);
int CountLetters(const std::string&);
int CountSentences(const std::string&);
int ComputeIndex(const std::string&);

int main()
{
    // Test Cases
    std::array<std::string, 11> sentences {
        "One fish. Two fish. Red fish. Blue fish.",
        "Would you like them here or there? I would not like them here or there. I would not like them anywhere.",
        "Congratulations! Today is your day. You're off to Great Places! You're off and away!",
        "Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.",
        "In my younger and more vulnerable years my father gave me some advice that I've been turning over in my mind ever since.",
        "Alice was beginning to get very tired of sitting by her sister on the bank, and of having nothing to do: once or twice she had peeped into the book her sister was reading, but it had no pictures or conversations in it, \"and what is the use of a book,\" thought Alice \"without pictures or conversation?\"",
        "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.",
        "There are more things in Heaven and Earth, Horatio, than are dreamt of in your philosophy.",
        "It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.",
        "A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.",
        "Marsh is not swamp. Marsh is a space of light, where grass grows in water, and water flows into the sky. Slow-moving creeks legged birds lift with unexpected grace-as though not built to fly against the roar of a thousand snow geese."
    };

    // Pass each test case to the function
    for (size_t i{0}; i < sentences.size(); ++i)
    {
        std::cout << sentences.at(i) << std::endl;
    
        int index{ComputeIndex(sentences.at(i))};

        if (index < 1)
        std::cout << "Before Grade 1.\n\n";

        else if (index >= 16)
        std::cout << "Grade 16+\n\n";

        else
        std::cout << "Grade " << index << "\n\n";
    }
}

int CountWords(const std::string& sentence)
{
    // This function gets a sentence as input and returns the number of word it contains.
    int NumWords{0};
    std::string word;

    std::stringstream ss (sentence);

    while (ss >> word)
    ++ NumWords;

    return NumWords;
}

int CountLetters(const std::string& sentence)
{
    // This function gets a sentence and returns the number of letters it contains.
    int NumLetters{0};
    
    for (size_t i{0}; i < sentence.length(); ++i)
    {
        if (
            (sentence.at(i) >= 'a' && sentence.at(i) <= 'z') || 
            (sentence.at(i) >= 'A' && sentence.at(i) <= 'Z'))
            
            ++ NumLetters;
    }

    return NumLetters;
}

int CountSentences(const std::string& sentence)
{
    // This function gets a sentence and returns the number of sub-sentences.
    int NumSentences{0};

    for (size_t i{0}; i < sentence.length(); ++i)
    {
        if (
            sentence.at(i) == '.' || 
            sentence.at(i) == '?' || 
            sentence.at(i) == '!'
        )
        
        ++ NumSentences;
    }

    return NumSentences;
}

int ComputeIndex(const std::string& text)
{
    // This function gets the number of words, letters, and sub-sentences in a sentence, and returns the written level (index) of the sentence.
    int words{CountWords(text)};
    int letters{CountLetters(text)};
    int sentences{CountSentences(text)};

    double avgLetters{static_cast <double> (letters) / words * 100}; 
    double avgSentence{static_cast <double> (sentences) / words * 100}; 

    double index{round(0.0588 * avgLetters - 0.296 * avgSentence - 15.8)};

    return index;
}

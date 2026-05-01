/*
    In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.
    For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. 
    Summing these, we get that “CODE” is worth 7 points.
    This script determines the winner of a short Scrabble-like game.
    The program prompts for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. 
    Then, depending on which player scores the most points, the program either prints “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
*/

#include <iostream>
#include <array>
#include <string>
#include <cmath>

const size_t COUNT{26};

// Prototype the function
int ComputeScore(
    std::array<int, COUNT>&, 
    const std::array<char, COUNT>&, 
    const std::string&
);

int main()
{
    // Structures
    const size_t count{26};

    std::array<char, count> letters{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    std::array<int, count> values{1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Input
    std::string wordOne, wordTwo;

    std::cout << "Player 1: ";
    std::cin >> wordOne;

    std::cout << "Player 2: ";
    std::cin >> wordTwo;

    int scoreOne = ComputeScore(values, letters, wordOne);
    int scoreTwo = ComputeScore(values, letters, wordOne);

    if (scoreOne > scoreTwo)
    std::cout << "Player 1 wins! ";

    else if (scoreTwo > scoreOne)
    std::cout << "Player 2 wins! ";

    else
    std::cout << "Tie! ";
}

int ComputeScore(
    std::array<int, COUNT>& values, 
    const std::array<char, COUNT>& letters, 
    const std::string& word)

{
    // This function gets a string and calculates the sum of its characters according to the values array.
    unsigned int sum{0};
       
    for (size_t i{0}; i < word.length(); ++i)
    {
        for (size_t j{0}; j < letters.size(); ++j)
        {
            if (toupper(word.at(i)) == letters.at(j))
            sum += values.at(j);
        }
    }

    return sum;
}

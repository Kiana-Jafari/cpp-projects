/*
    In the game of Scrabble, players create words to score points, and the number of points is the sum of the point values of each letter in the word.
    For example, if we wanted to score the word “CODE”, we would note that the ‘C’ is worth 3 points, the ‘O’ is worth 1 point, the ‘D’ is worth 2 points, and the ‘E’ is worth 1 point. 
    Summing these, we get that “CODE” is worth 7 points.
    This script determines the winner of a short Scrabble-like game.
    The program prompts for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. 
    Then, depending on which player scores the most points, the program either prints “Player 1 wins!”, “Player 2 wins!”, or “Tie!” (in the event the two players score equal points).
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Prototype the function
int ComputeScore(string letter);

int main()
{
    string wordOne, wordTwo;

    cout << "Player 1: ";
    cin >> wordOne;

    cout << "Player 2: ";
    cin >> wordTwo;

    int scoreOne = ComputeScore(wordOne);
    int scoreTwo = ComputeScore(wordTwo);

    if (scoreOne > scoreTwo)
    cout << "Player 1 wins! ";

    else if (scoreTwo > scoreOne)
    cout << "Player 2 wins! ";

    else
    cout << "Tie! ";
}

int ComputeScore(string word)
{
    // This function gets a string and calculates the sum of its characters according to the values array.
    int sum = 0;
    char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    
    for (int i = 0; i < word.length(); i++)
    {
        for (int j = 0; j < (sizeof(letters) / sizeof(letters[0])); j++)
        {
            if (toupper(word[i]) == letters[j])
            {
                sum += values[j];
            }
        }
    }

    return sum;
}

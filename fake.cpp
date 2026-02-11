/*
    Through a statistical analysis, we concluded that for an account to be considered fake, 
    the username should have an odd number of non-repeated characters; 
    otherwise, if it contains an even number of non-repeated characters, it's considered not fake.
    Write a program that recognizes whether a given username is fake or not, 
    and prints "Chat with this user" vs. "Block this user", accordingly.
*/

#include <iostream>
#include <string>

using namespace std;

// Prototype the function
int isFake(string username);

int main()
{
    // Test Cases
    string usernames[] = {
        "NoobMaster69LOL", "aaBB11__xxYYzz", "SirSpamsALot123", "xX_DarkLord_Xx", "404BrainNotFound!!!",
        "anna", "coffee_addict", "qwerty", "coolguy", "mississippi"
    };

    for (int i = 0; i < (sizeof(usernames) / sizeof(usernames[0])); i++)
    {
        // Pass each string as an argument

        int result = isFake(usernames[i]);

        if (result % 2 == 0)
        cout << usernames[i] << " | " << result << " | Chat with this user. " << endl;

        else
        cout << usernames[i] << " | " << result << " | Block this user. " << endl;
    }
}

int isFake(string username)
{
    // This function gets the username of a user and counts the number of non-repeated characters among it.
    int count = 0;
    int frequencies[128] = {0};

    for (int i = 0; i < username.length(); i++)
    {
        frequencies[username[i]] ++;
    }

    // Calculate the number of non-repeated characters
    for (int i = 0; i < username.length(); i++)
    {
        if (frequencies[username[i]] == 1)
        {
            count ++;
        }
    }

    return count;
}

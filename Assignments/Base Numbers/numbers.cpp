#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Prototype the functions
string DecimalToBase(int number, int radix);
int BaseToDecimal(string number, int radix);
void BitwiseOperation(int a, int b, string operation);
string OnesComplement(int number);
string TwosComplement(int number);
void CipherText(string plaintext, int radix, int key);

// Helper Functions
int pow(int base, int power);
char ValueToHex(int remainder);
int HexToValue(char letter);

int main()
{
    string option;

    cout << R"(
    === Base Numbers ===

    Below, you can see what this program is able to do:

    1. Convert from Decimal to a Base
    2. Convert from a Base to Decimal
    3. Bitwise Operations (AND, OR, XOR)
    4. Calculate the 1's Complement of a decimal number
    5. Calculate the 2's Complement of a decimal number
    6. Generate a Ciphertext from a given Plaintext

    Enter the number of the option you want.
    Feel free to explore the program!
    )";
    cout << "\n";

    while (true)
    {
        cout << "Enter an option: ";
        cin >> option;

        if (option == "exit")
        break;

        else if (option == "1")
        {
            unsigned int n, base;

            cout << "Enter a number and the base: ";
            cin >> n >> base;

            string result = DecimalToBase(n, base);

            cout << result << endl;
        }

        else if (option == "2")
        {
            string n;
            int base;

            cout << "Enter a number and the base: ";
            cin >> n >> base;

            int result = BaseToDecimal(n, base);

            cout << result << endl;
        }

        else if (option == "3")
        {
            unsigned int num1, num2;
            string opr;

            cout << "Enter two numbers: ";
            cin >> num1 >> num2;

            cout << "What operation do you want to apply on them? (AND, OR, XOR): ";
            cin >> opr;

            BitwiseOperation(num1, num2, opr);
        }

        else if (option == "4")
        {
            unsigned int n;

            cout << "Enter a positive decimal number: ";
            cin >> n;

            string result = OnesComplement(n);

            cout << "1's complement: " << result << endl;
        }

        else if (option == "5")
        {
            unsigned int n;

            cout << "Enter a positive decimal number: ";
            cin >> n;

            string result = TwosComplement(n);

            cout << "2's complement: " << result << endl;
        }

        else if (option == "6")
        {
            string text;
            int base, key;

            cout << "Enter the plaintext: ";
            cin >> text;

            cout << "Enter the base of the ciphertext: ";
            cin >> base;
            
            cout << "Enter the key for shifting the digits: ";
            cin >> key;

            cout << "Plaintext: " << text << endl;
            CipherText(text, base, key);
            cout << endl;
        }

        else
        cout << "Invalid option\n";
    }
}

string DecimalToBase(int number, int radix)
{
    // This function gets a number in decimal and converts it to any given base.
    int digit;
    char hexaDigit;
    string num;

    if (number == 0)
    return "0";

    while (number > 0)
    {
        digit = number % radix;

        if (digit >= 0 && digit < 10)
        num = to_string(digit) + num;

        else
        {
            hexaDigit = ValueToHex(digit); // Get the hexa equivalent
            num = hexaDigit + num;
        }

        number /= radix;
    }

    return num;
}

int BaseToDecimal(string number, int radix)
{
    // This function gets a number in any base and converts it to decimal.
    int remainder, digit, hexDigit, decimal = 0;

    for (int i = 0; i < number.length(); i++)
    {
        int digit = number[i] - '0';
        if (digit >= radix || digit < 0) // Check if any of the digits exceed the base
        {
            cout << "ERROR (" << digit << " invalid in base " << radix << ")" << endl;
            return -1;
        }
    }

    for (int i = 0; i < number.length(); i++)
    {
        digit = number[(number.length() - 1 - i)];

        if (digit >= '0' && digit <= '9')
        {
            remainder = digit - '0'; // Get the integer value
            decimal += pow(radix, i) * remainder;
        }

        else
        {
            hexDigit = HexToValue(digit);
            decimal += pow(radix, i) * hexDigit;
        }
    }

    return decimal;
}

void BitwiseOperation(int a, int b, string operation)
{
    // This function gets two numbers and does bitwise operations on them.
    if (operation == "AND")
    cout << (a & b) << endl;

    else if (operation == "OR")
    cout << (a | b) << endl;

    else if (operation == "XOR")
    cout << (a ^ b) << endl;

    else
    cout << "Please choose a valid option. " << endl;
}

string OnesComplement(int number)
{
    // This function gets a number in decimal, converts it to binary, and returns its one's complement equivalent (NOT operation).
    string num = DecimalToBase(number, 2);

    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '0')
        num[i] = '1';

        else
        num[i] = '0';
    }

    int diff = (8 - num.length()); // 8 bit padding

    if (num[0] == '0')
    {
        for (int i = 0; i < diff; i++)
        num = '1' + num;
    }

    return num;
}

string TwosComplement(int number)
{
    // This function gets the one's complement and returns the two's complement.
    
    string num = OnesComplement(number);
    int length = num.length();

    for (int i = (length - 1); i >= 0; i--)
    {
        if (num[i] == '0') // Add 1 to the Least Significant Bit (LSB)
        {
            num[i] = '1';
            break;
        }

        else
        num[i] = '0';
    }

    int diff = (8 - num.length());

    if (num[0] == '0') // Add an extra 1 if all digits were flipped
    {
        for (int i = 0; i < diff; i++)
        num = '1' + num;
    }

    return num;
}

void CipherText(string plaintext, int radix, int key)
{
    // This function gets a plaintext and returns the ciphertext in base 7.
    vector<int> ascii;
    vector<string> binary, septenary;
    
    for (char c : plaintext)
    ascii.push_back(static_cast<int>(c)); // Add the ASCII values to the vector
    
    for (int number : ascii)
    {
        string num = DecimalToBase(number, 2);
        binary.push_back(num);
    }

    for (string num : binary)
    {
        int diff = (8 - num.length()); // Pad to 8 bits

        for (int j = 0; j < diff; j++)
        num = '0' + num;
    }

    for (string num : binary)
    {
        int decimal = BaseToDecimal(num, 2);
        string septimal = DecimalToBase(decimal, radix);

        septenary.push_back(septimal);
    }

    int digit, new_digit;

    cout << "Encrypted text (ciphertext): ";
    for (string num : septenary)
    {
        for (int i = 0; i < num.length(); i++)
        {
            digit = (num[i] - '0');
            new_digit = (digit + key) % radix;

            cout << new_digit;
        }

        cout << " ";
    }
}

char ValueToHex(int remainder)
{
    // This helper function gets the remainder of the division in decimal and returns its equivalent in hex.
    map<int, char> Hexa {
        {10, 'A'}, 
        {11, 'B'}, 
        {12, 'C'}, 
        {13, 'D'}, 
        {14, 'E'}, 
        {15, 'F'}
    };

    char hexa = Hexa[remainder];

    return hexa;
}

int HexToValue(char letter)
{
    // This helper function gets the hexadecimal character and returns its decimal equivalent.
    map<char, int> Hexa {
        {'A', 10},
        {'B', 11},
        {'C', 12},
        {'D', 13},
        {'E', 14},
        {'F', 15},
    };

    int value = Hexa[letter];

    return value;
}

int pow(int base, int power)
{
    // This helper function gets a base and a power and returns base to the power.
    int mult = 1, exp = 0;

    while (exp < power)
    {
        mult *= base;
        exp ++;
    }

    return mult;
}

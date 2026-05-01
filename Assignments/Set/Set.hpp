#include <array>
#include <iostream>
#include <fstream>

#ifndef SET_H
#define SET_H

template <class T> // for class int, double (or float), char

class Set {

public:

    const static size_t capacity{100};

    Set() : n{0} // constructor (initializes set to 0)
    {}

    ~Set() = default; // destructor

    bool isPresent(const T x) const
    {
        for (size_t i{0}; i < n; ++i)
        {
            if (numbers.at(i) == x) // check if the element is included in the set using linear search
            return true;
        }

        return false;
    }

    void insert(const T x)
    {
        if (n == capacity) // terminate the program if array reached its capacity (by user call)
        {
            std::cout << "Reached the maximum size of the set.";
            return ;
        }

        if (!isPresent(x)) // add the element if it's not already in the set
        {
            numbers.at(n) = x;
            ++ n;
        }
    }

    void remove(const T x)
    {
        if (isPresent(x)) // remove the element by calling the utility function
        removeElement(x);
    }

    void save()
    {
        std::ofstream file("numbers.txt");

        for (size_t i{0}; i < n; ++i)
        file << numbers.at(i) << " ";

        file.close(); // close the file
    }

    void getInput()
    {
        int input;
        
        std::cout << "Enter the size of the array: (size should be <= " << capacity << "): ";
        std::cin >> input;

        if (isValid(input))
        {
            for (size_t i{0}; i < input; ++i)
            {
                // get n input from the user
                T number;

                std::cout << "Enter the " << i << "-th element: ";
                std::cin >> number;

                // add the element to the array
                insert(number);
            }
        }
    }

    Set operator+(const Set& set) const
    {
        Set unionSet;

        // insert the left set and right set
        for (size_t i{0}; i < n; ++i)
        unionSet.insert(numbers.at(i));
        
        for(size_t i{0}; i < set.n; ++i)
        unionSet.insert(set.numbers.at(i));

        return unionSet;
    }

    Set operator-(const Set& set) const
    {
        Set diffSet;

        for (size_t i{0}; i < n; ++i)
        diffSet.insert(numbers.at(i)); // insert the left set

        for (size_t i{0}; i < set.n; ++i)
        diffSet.remove(set.numbers.at(i)); // remove the intersection of sets from the copy of the left set

        return diffSet;
    }
    
    Set operator*(const Set& set) const
    {
        Set intersection;

        for (size_t i{0}; i < n; ++i) // left set
        {
            if (set.isPresent(numbers.at(i))) // check if it's included in the right set
            intersection.insert(numbers.at(i));
        }

        return intersection;
    }

    void displaySet()
    {
        std::cout << "Set elements:\n";

        for (size_t i{0}; i < n; ++i)
        std::cout << numbers.at(i) << " ";

        std::cout << '\n';
    }

private:

    int n;
    std::array<T, capacity> numbers;

    // utility functions
    void removeElement(const T x)
    {
        for (size_t i{0}; i < n; ++i)
        {
            if (numbers.at(i) == x) // find the element
            {
                -- n;

                for (size_t j{i}; j < n; ++j) // remove element
                numbers.at(j) = numbers.at(j + 1);

                break;
            }
        }
    }

    bool isValid(const int input) const
    {
        if (input < 0 || input > capacity) // check whether user entered a valid value for n
        return false;

        else
        return true;
    }
};

#endif

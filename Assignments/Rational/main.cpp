#include <iostream>
#include "Rational.hpp"

int main()
{
    // Rational (sign, a, b)
    Rational r1{+1, 1, 2};
    Rational r2{-1, 3, 8};

    std::cout 
        << "Rational number 1:\n"
        << r1.toString()
        << "\n\nRational number 2:\n"
        << r2.toString();

    Rational sum{r1 + r2}, diff{r1 - r2}, mult{r1 * r2}, div{r1 / r2};

    std::cout
        << "\n\nSum:"
        << sum.toString()
        << "\n\nDiff:"
        << diff.toString()
        << "\n\nMult:"
        << mult.toString()
        << "\n\nDiv:"
        << div.toString();
}

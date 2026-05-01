#include <iostream>
#include <array>
#include <string>
#include <sstream>
#include <cmath>
#include "Polynomial.hpp"

Polynomial::Polynomial() : n{0}, factor{0} // list-initialization
{}

Polynomial::~Polynomial()
{}

void Polynomial::getPolynomial()
{
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> n;

    for (int i{n}; i >= 0; --i) // highest degree to lowest
    {
        int coeff;

        std::cout << "Enter the " << i << "-th coefficient: ";
        std::cin >> coeff;

        factor.at(i) = coeff; // set the value of the i-th index
    }
}

Polynomial Polynomial::operator+(const Polynomial& poly) const
{
    // add two polynomial
    Polynomial sum;

    int size{std::max(n, poly.n)};

    sum.n = size; // set the result degree to the greatest one

    for (int i{0}; i <= size; ++i)
    sum.factor.at(i) = factor.at(i) + poly.factor.at(i);

    return sum;
}

Polynomial Polynomial::operator*(const Polynomial& poly) const
{
    // multiply two poly
    Polynomial product;

    int size{n + poly.n + 1};

    product.n = size; // update the product array's size

    for (int i{0}; i <= n; ++i)
    {
        for (int j{0}; j <= poly.n; ++j)
        product.factor.at(i+j) += factor.at(i) * poly.factor.at(j);
    }

    return product;
}

std::string Polynomial::printPolynomial()
{
    // display the polynomial
    std::ostringstream output;

    for (int i{n}; i >= 0; --i)
    {
        if (i == 0) // for the constant term
        {
            output << factor.at(i);
            break;
        }

        if (factor.at(i) != 0)
        output << factor.at(i) << "x^" << i << " + ";
    }

    return output.str();
}

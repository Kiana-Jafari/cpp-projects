#include <iostream>
#include "Polynomial.hpp"

int main()
{
    // Test case:
    Polynomial poly1;
    Polynomial poly2;

    std::cout << "First polynomial:\n";
    poly1.getPolynomial();

    std::cout << "\nSecond polynomial:\n";
    poly2.getPolynomial();

    std::cout 
        << "\n\nFirst polynomial equals:\n"
        << poly1.printPolynomial();

    std::cout 
        << "\n\nSecond polynomial equals:\n"
        << poly2.printPolynomial();

    // sum of two polys
    Polynomial sum{poly1 + poly2};

    std::cout 
        << "\n\nSum:\n"
        << sum.printPolynomial();

    // product
    Polynomial product{poly1 * poly2};

    std::cout 
        << "\n\nProduct:\n"
        << product.printPolynomial();

    /*
        First polynomial equals:
        12x^5 + -7x^3 + 4x^2 + -9

        Second polynomial equals:
        4x^3 + 17x^1 + -6

        Sum:
        12x^5 + -3x^3 + 4x^2 + 17x^1 + -15

        Product:
        48x^8 + 176x^6 + -56x^5 + -119x^4 + 74x^3 + -24x^2 + -153x^1 + 54
    */
    
}

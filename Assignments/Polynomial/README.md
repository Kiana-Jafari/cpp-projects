# Polynomial Class with Array Representation

## Overview

This C++ class implements a polynomial using a fixed‑size array of coefficients (maximum degree 99, since `std::array<int, 100> factor` allows indices 0..99). The polynomial is stored in descending order of exponents, from degree `n` down to 0. The class provides input/output methods and overloads the `+` and `*` operators for polynomial addition.

## Class Members

- **`int n`** – the degree of the polynomial (highest exponent with a non‑zero coefficient).
- **`std::array<int, 100> factor`** – array where `factor.at(i)` holds the coefficient for \(x^i\).  
  For example, the polynomial  
  \(12x^5 - 7x^3 + 4x^2 - 9\) is stored as:
  
  | index | 5 | 4 | 3 | 2 | 1 | 0 |
  |-------|---|---|---|---|---|---|
  | value |12 | 0 |-7 | 4 | 0 |-9 |

- **Default constructor** – initialises the polynomial to zero (all coefficients zero, `n = 0`).

## Member Functions

### `void getPolynomial()`
Reads a polynomial from the keyboard.  
*Assumption:* The user enters coefficients in a specific format (e.g., degree, then coefficients from highest to lowest). No input validation is performed.

### `void printPolynomial() const`
Prints the polynomial to the console in a human‑readable format.  
*Example output:* `12x^5 - 7x^3 + 4x^2 - 9`

### `Polynomial operator+(const Polynomial& poly) const`
Adds two polynomials and returns a new `Polynomial` object.  
*Addition rules:*  
- Coefficients of equal exponents are added.  
- The degree of the result is the highest exponent where the sum coefficient is non‑zero.  
- If all coefficients cancel, the zero polynomial is returned.

### `Polynomial operator*(const Polynomial& poly) const`
Multiplies two polynomials and returns a new `Polynomial` object.
*Multiplication rules:*
- Each coefficient of the first polynomial would be multiplied by each term in the second polynomial.
- The degree of the result is the sum of the degrees of the first polynomial and the second one, plus a 1.
- Coefficients of equal exponents are added.

## Usage Example

```cpp
Polynomial p1, p2;
p1.getPolynomial();   // user inputs first polynomial
p2.getPolynomial();   // user inputs second polynomial

std::cout << "First polynomial: ";
p1.printPolynomial();

std::cout << "Second polynomial: ";
p2.printPolynomial();

Polynomial sum{p1 + p2};
std::cout << "Sum: ";
sum.printPolynomial();

Polynomial product{p1 * p2};
std::cout << "Product: ";
product.printPolynomial();

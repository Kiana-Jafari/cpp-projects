#include <array>
#include <string>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial {

public:

    static const size_t maxDegree{100};

    Polynomial();
    ~Polynomial();

    void getPolynomial();
    std::string printPolynomial() const;
    Polynomial operator+(const Polynomial&) const;
    Polynomial operator*(const Polynomial&) const;

private:

    int n; // polynomial's degree
    std::array<int, maxDegree> factor; // coefficients of the polynomial
};

#endif

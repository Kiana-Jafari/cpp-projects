#include <string>
#include <sstream>
#include <stdexcept>
#include <numeric>
#include <tuple>
#include "Rational.hpp"

Rational::Rational(
    const int numSign,
    const unsigned int numerator, 
    const unsigned int denominator
) 
    : a{numerator}, sign{numSign}
{
    setDenominator(denominator);
    reducedForm(a, b); // the class should store the fraction in reduced form
}

Rational::~Rational()
{}

// setters
void Rational::setNumerator(const unsigned int a) { this->a = a; }

void Rational::setSign(const int sign) { this->sign = sign; }

void Rational::setDenominator(const unsigned int b) 
{ 
    if (b > 0) // validity checking
    this->b = b;

    else
    throw std::invalid_argument("denominator must not be 0");
}

// getters
unsigned int Rational::getNumerator() const { return a; }

unsigned int Rational::getDenominator() const { return b; }

int Rational::getSign() const { return sign; }

Rational Rational::operator+(const Rational& rational) const
{
    Rational sum;
    
    auto [factor1, factor2, lcf] = getFactors(b, rational.b); // call the function

    int numerator = sign * a * factor1 + rational.sign * rational.a * factor2;
    sum.sign = (numerator >= 0 ? 1 : -1);
    sum.a = std::abs(numerator); // The numerator should be positive
    sum.b = lcf;

    reducedForm(sum.a, sum.b);

    return sum;
}

Rational Rational::operator-(const Rational& rational) const
{
    Rational diff;

    auto [factor1, factor2, lcf] = getFactors(b, rational.b);

    int numerator = sign * a * factor1 - rational.sign * rational.a * factor2;
    diff.sign = (numerator < 0 ? -1 : 1);
    diff.a = std::abs(numerator);
    diff.b = lcf;
    
    reducedForm(diff.a, diff.b);

    return diff;
}

Rational Rational::operator*(const Rational& rational) const
{
    Rational product;

    product.a = a * rational.a;
    product.b = b * rational.b;
    product.sign = sign * rational.sign;

    reducedForm(product.a, product.b);

    return product;
}

Rational Rational::operator/(const Rational& rational) const
{
    Rational division;

    division.a = a * rational.b;
    division.b = b * rational.a;
    division.sign = sign * rational.sign;

    reducedForm(division.a, division.b);

    return division;
}

std::string Rational::toString() const
{
    std::ostringstream output;

    output
    << "a/b:\n" << getNumerator() << '/' << getDenominator()
    << "\nsign: " << getSign();

    return output.str();
}

void Rational::reducedForm(unsigned int& numerator, unsigned int& denominator) const
{
    int gcf = std::gcd(numerator, denominator);

    // simplify the terms by dividing them by their greatest common factor
    numerator /= gcf;
    denominator /= gcf;
}

std::tuple<unsigned int, unsigned int, unsigned int> Rational::getFactors(unsigned int denom1, unsigned int denom2) const
{
    // this function returns the LCM and factors 
    // needed for adding and subtracting two rational numbers
    unsigned int lcf{std::lcm(denom1, denom2)};

    unsigned int factor1{lcf / denom1};
    unsigned int factor2{lcf / denom2};

    return {factor1, factor2, lcf};
}

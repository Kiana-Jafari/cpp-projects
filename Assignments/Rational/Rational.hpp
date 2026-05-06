#include <tuple>
#include <string>

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

class Rational
{

public:

    Rational() = default; // default constructor (for operator overloders)
    Rational(const int, const unsigned int, const unsigned int);
    ~Rational();

    void setNumerator(const unsigned int);
    void setDenominator(const unsigned int);
    void setSign(const int);
    int getSign() const;
    unsigned int getNumerator() const;
    unsigned int getDenominator() const;
    std::string toString() const;

    Rational operator+(const Rational&) const;
    Rational operator-(const Rational&) const;
    Rational operator*(const Rational&) const;
    Rational operator/(const Rational&) const;

private:

    unsigned int a;
    unsigned int b;
    int sign; // could be -1 or +1 (negative & positive, respectively)

    // utilities
    void reducedForm(unsigned int&, unsigned int&) const;
    std::tuple<unsigned int, unsigned int, unsigned int> getFactors(unsigned int, unsigned int) const;
};

#endif

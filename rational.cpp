#include "rational.h"

/**
 * @brief Construct a new Rational:: Rational object
 * 
 */
Rational::Rational() {
    mNum = 1;
    mDenom = 1;
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param n 
 * @param b 
 */
Rational::Rational(int n, int b) {
    int c = GCD(n,b);
    this->mNum = n/c;
    this->mDenom = b/c;
}

/**
 * @brief Construct a new Rational:: Rational object
 * 
 * @param str 
 */
Rational::Rational(const char* str) {
    std::string s(str);
    std::istringstream string(str);
    int num, denom;
    char slash;
    string >> num >> slash >> denom;
    int c = GCD(num, denom);
    mNum = num / c;
    mDenom = denom / c;
}

/**
 * @brief reduces fraction to smallest numbers
 * 
 */
void Rational::reduce() {
    int c = GCD(mNum, mDenom);
    mNum /= c;
    mDenom /= c;
}

/**
 * @brief overloads the double operator to return fraction as decemial
 * 
 * @return double 
 */
Rational::operator double() const {
    return (1.0*mNum) / mDenom;
}
/**
 * @brief finds the greats common denominator for the provided numerator and denominator
 * 
 * @param n 
 * @param d 
 * @return int 
 */
int Rational::GCD(int n, int d) {
    if (d == 0) {
        return n;
    }
    return GCD(d, n%d);
}
/**
 * @brief overloads the << operator to display fraction
 * 
 * @param out 
 * @param num 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream & out, const Rational &num)
{
    out <<num.mNum<<"/"<<num.mDenom;
    return out;
}

/**
 * @brief overloads the + operator for addition of Fractions
 * 
 * @param a 
 * @return Rational 
 */
Rational Rational::operator+(const Rational& a) const {
    return Rational(mNum * a.mDenom + a.mNum * mDenom, mDenom * a.mDenom);
}

/**
 * @brief overloads the - operator for subtraction of fractions
 * 
 * @param a 
 * @return Rational 
 */
Rational Rational::operator-(const Rational& a) const {
    return Rational(mNum * a.mDenom - a.mNum * mDenom, mDenom * a.mDenom);
}
/**
 * @brief overloads the * operator for multiplying fractions
 * 
 * @param a 
 * @return Rational 
 */
Rational Rational::operator*(const Rational& a) const {
    return Rational(mNum * a.mNum, mDenom * a.mDenom);
}
/**
 * @brief overloads the / function for division of fractions
 * 
 * @param a 
 * @return Rational 
 */
Rational Rational::operator/(const Rational& a) const {
    return Rational(mNum * a.mDenom, mDenom * a.mNum);
}

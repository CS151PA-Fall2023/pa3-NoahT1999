/**
 * @file rational.h
 * @author Noah Turner
 * @brief 
 * @version 0.1
 * @date 2023-10-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <cstdlib>
#include <sstream>

using std::cout;
using std::endl;


class Rational{
    public:
        Rational();
        Rational(int n, int b);
        Rational(const char* str);

        operator double() const;

        void reduce();

        Rational operator+(const Rational& a) const;
        Rational operator-(const Rational& a) const;
        Rational operator*(const Rational& a) const;
        Rational operator/(const Rational& a) const;

        friend std::ostream &operator<<(std::ostream & out, const Rational &C);

    private:
        int mNum;
        int mDenom;
        int GCD(int n, int d);
};




#endif
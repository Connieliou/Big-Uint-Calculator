#ifndef BIGUINT_H
#define BIGUINT_H
#include <iostream>
#include <QString>


class biguint
{
public:
    // TYPES and CONSTANTS
    typedef std::size_t size_type;
    static const size_type CAPACITY = 10000;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with given unsigned int value
    //       (default value = 0)
    biguint(unsigned int = 0);

    // pre: s.size() <= CAPACITY && s consists of decimal digits only
    // post: creates a biguint whose digits are given in a string s
    //       rightmost digit of s corresponds to the least significant
    //       digit
    biguint (const char s[]);
    biguint (const std::string & s);

    // CONSTANT FUNCTIONS
    // pre: pos < CAPACITY
    // post: returns the (pos+1)^st digit from the right of this biguint
    size_type operator [](size_type pos) const;

    // pre: none
    // post: return 0 if n == this biguint
    //             -1 if n > this biguint
    //              1 if n < this biguint
    int compare(const biguint & n) const;

    // pre: none
    // post: b has been added to this biguint
    //       overflow digit will be thrown away, if any
    void operator +=(const biguint &b);

    // pre: none
    // post: if b > this biguint, then this biguint is reset to 0
    //       else b is subtracted from this biguint
    void operator -=(const biguint & b);

    // pre: d <= 9;
    // post: this biguint has been multiplied by d
    void operator *= (size_type d);

    // pre: none
    // post: digits of this biguint has been left shifted by 1 positio
    //       the former most significant digit is discarded
    //       the new least significiant digit is 0
    void ls();

    // pre: none
    //post: returns a Qstring containing this biguint without leading 0's
    QString toQString() const;
    //pre none
    //post multiply this biguint with another biguint
    void operator *=(const biguint & b);

private:
    size_type data[CAPACITY];

    // data[i] corresponds to the (i+1)^st rightmost digit of this
    // biguint (0 if it is not used)
    // data[0] = least significant (units) digit
    // data[CAPACITY-1] = most significant digit
};

std::ostream & operator <<(std::ostream & os, const biguint &);
std::istream & operator >>(std::istream & is, biguint &);

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);
biguint operator * (const biguint &, biguint::size_type);
bool operator < (const biguint &a, const biguint &b);
bool operator <= (const biguint &a, const biguint &b);
bool operator == (const biguint &a, const biguint &b);
bool operator >= (const biguint &a, const biguint &b);
bool operator > (const biguint &a, const biguint &b);
biguint operator *(const biguint &, const biguint &);

#endif // BIGUINT_H

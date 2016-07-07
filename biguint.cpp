#include "biguint.h"
#include <cassert>
#include <algorithm>
#include <cctype>
#include <QString>
#include <string>

biguint::biguint(unsigned int n)
{

    std::fill(data, data+CAPACITY, 0);

    size_type i(0);
    while (n > 0)
    {
        data[i] = n % 10;
        ++i;
        n /= 10;
    }
}

biguint::size_type biguint::operator[](size_type pos) const
{
    assert(pos < CAPACITY);
    return data[pos];
}


biguint::biguint(const std::string &s)
{
    std::fill(data, data+CAPACITY, 0);
    size_type n = s.size();

    assert(n <= CAPACITY);

    for (size_type i = 0; i < n; ++i)
    {
        assert(isdigit(s[i]));
        data[n-1-i] = s[i] - '0';
    }
}

biguint::biguint(const char s[]): biguint(std::string(s))
{
}

std::ostream & operator << (std::ostream &os, const biguint & b)
{
    int i(biguint::CAPACITY-1);

    while (i > 0 && b[i] == 0)
        --i;

    while (i >= 0)
    {
        os << b[i--];
    }

   return os;
}

std::istream & operator >>(std::istream & is, biguint & b)
{
    std::string s;
    is >> s;
    b = biguint(s);
    return is;

}

void biguint::operator +=(const biguint & b)
{
    size_type carry(0);

    for (size_type i = 0; i < CAPACITY; ++i)
    {
        size_type sum = carry + data[i] + b.data[i];
        data[i] = sum % 10;
        carry = sum / 10;
    }
}

biguint operator + (const biguint &a, const biguint &b)
{
    biguint ans(a);
    ans += b;
    return ans;
}

int biguint::compare(const biguint &n) const
{
    for (int i = CAPACITY -1; i >= 0; --i)
    {
        if (data[i] < n.data[i])
            return -1;
        if (data[i] > n.data[i])
            return 1;


    }

    return 0;

}

void biguint::operator -=(const biguint & b)
{
    if (compare(b) == -1)
    {
        std::fill(data, data+CAPACITY, 0);
        return;
    }

    size_type borrow(0);

    for (size_type i = 0; i < CAPACITY; ++i)
    {
        size_type t = b.data[i] + borrow;
        if (data[i] >= t)
        {
            data[i] -= t;
            borrow = 0;
        }
        else
        {
            data[i] += 10;
            data[i] -= t;
            borrow = 1;
        }
    }


}

QString biguint::toQString() const
{
    QString dataString = "";
    int i=CAPACITY-1;
    while(i>0 && data[i] == 0)
    {
        i--;
    }
    while(i >= 0)
    {
        dataString += data[i--] + '0';
    }
    return dataString;
}

biguint operator - (const biguint & a, const biguint & b)
{
    biguint ans(a);
    ans -= b;
    return ans;

}

void biguint::operator *=(size_type d)
{

    size_type carry(0);

    for (size_type i = 0; i < CAPACITY; ++i)
    {
        size_type sum = carry + data[i] * d;
        data[i] = sum % 10;
        carry = sum/10;

    }
}

void biguint::operator *=(const biguint & b)
{
    int i=CAPACITY-1;
    while(i>0 && data[i]==0)
    {
        i--;
    }
    biguint ans(0u);
    while(i>=0)
    {
     ans.ls();
     ans=ans+b*data[i];
     i--;
    }
    std::copy(ans.data, ans.data +ans.CAPACITY, data);
}

biguint operator *(const biguint & b, biguint::size_type d)
{
    biguint ans(b);
    ans *= d;
    return ans;
}

void biguint::ls()
{
    for (int i = CAPACITY -1; i >= 0; --i)
        data[i] = data[i-1];

    data[0] = 0;
}

bool operator < (const biguint &a, const biguint &b)
{
    return a.compare(b)==-1;
}

bool operator <= (const biguint &a, const biguint &b)
{
    return a.compare(b)<=0;
}

bool operator == (const biguint &a, const biguint &b)
{
    return a.compare(b)==0;
}

bool operator >= (const biguint &a, const biguint &b)
{
    return a.compare(b)>=0;
}

bool operator > (const biguint &a, const biguint &b)
{
    return a.compare(b)==1;
}
biguint operator *(const biguint &a, const biguint &b)
{
    biguint ans(a);
    ans*=b;
    return ans;
}

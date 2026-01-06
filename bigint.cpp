#include "bigint.hpp"
#include <algorithm>

// static unsigned long int strToULI(const std::string rev)
// {
//     unsigned long int n = 0;
//     for (size_t i = rev.length(); i > 0; --i)
//     {
//         n = n * 10 + (rev.at(i - 1) - '0');
//     }
//     return n;
// }

static unsigned long int strToULI(const std::string rev)
{
    unsigned long int result = 0;
    unsigned long int power = 1;
    for (size_t i = 0; i < rev.length(); ++i)
    {
        result += (rev.at(i) - '0') * power;
        power *= 10;
    }
    return result;
}

static bool isNum(std::string str)
{
    if (str.empty())
    {
        return false;
    }
    bool isNum = false;

    for (size_t i = 0; i<str.length(); ++i)
    {
        if (str.at(i) >= '0' && str.at(i) <= '9')
            isNum = true;
        else
            return false;
    }
    
    return isNum;
}

bigint::bigint(unsigned long int n)
{
    if (n == 0)
    {
        digit = "0";
        return ;
    }

    while (n > 0)
    {
        digit += (n%10) + '0';
        n /= 10;
    }
}

bigint::bigint(const std::string str)
{
    if (isNum(str))
    {
        digit = str;
        std::reverse(digit.begin(), digit.end());
        removeZero();
    }
    else
    {
        digit = "0";
    }
}

bigint & bigint::operator=(const bigint & rhs)
{
    if (this != &rhs)
    {
        this->digit = rhs.digit;
    }
    return *this;
}

bigint bigint::operator+(const bigint & rhs) const
{
    bigint result;
    result.digit = "";
    size_t max_len = std::max(this->digit.length(), rhs.digit.length());

    int a, b, sum, carry = 0;
    for (size_t i = 0; i < max_len || carry; ++i)
    {
        a = (i < this->digit.length()) ? this->digit.at(i) - '0' : 0;
        b = (i < rhs.digit.length()) ? rhs.digit.at(i) - '0' : 0;
        sum = a + b + carry;
        result.digit += (sum % 10) + '0';
        carry = sum / 10;
    }
    result.removeZero();
    return result;
}

bigint & bigint::operator+=(const bigint & rhs)
{
    *this = *this + rhs;
    return *this;
}

bigint & bigint::operator+=(unsigned long int n)
{
    *this = *this + bigint(n);
    return *this;
}

bigint & bigint::operator++()
{
    *this = *this + bigint(1);
    return *this;
}

const bigint bigint::operator++(int)
{
    bigint temp(*this);
    ++(*this);
    return temp;    
} 

void bigint::removeZero()
{
    while (digit.length() > 1 && digit.at(digit.length() - 1) == '0')
    {
        digit.erase(digit.length() -1, 1);
    }
}

bigint bigint::operator<<(const unsigned long int n) const
{
    if (n == 0 || digit == "0")
    {
        return *this;
    }
    bigint result(*this);
    result.digit.insert(0, n, '0'); // or result.digit = std::string(n, '0') + result.digit;
    return result;
}

bigint bigint::operator>>(const unsigned long int n) const
{
    if (n == 0 || digit == "0")
    {
        return *this;
    }
    if (n >= digit.length())
    {
        return bigint(0);
    }
    bigint result (*this);
    result.digit.erase(0, n); // or result.digit = result.digit.substr(n);
    return result;
}

bigint bigint::operator<<(const bigint & rhs) const
{
    if (digit == "0")
        return *this;
    
    return *this << strToULI(rhs.digit);
}

bigint bigint::operator>>(const bigint & rhs) const
{
    if (digit == "0")
        return *this;
    
    return *this >> strToULI(rhs.digit);
}

bigint & bigint::operator<<=(const unsigned long int n)
{
    *this = *this << n;
    return *this;
}

bigint & bigint::operator>>=(const unsigned long int n)
{
    *this = *this >> n;
    return *this;
}

bigint & bigint::operator>>=(const bigint & rhs)
{

    *this = *this >> strToULI(rhs.digit);
    return *this;
}

bool bigint::operator<(const bigint & rhs) const
{
    //compare length
    if (this->digit.length() != rhs.digit.length())
    {
        return this->digit.length() < rhs.digit.length();
    }
    //same length, compare digit by digit from most significant
    for (size_t i = this->digit.length(); i > 0; --i)
    {
        if (this->digit.at(i - 1) != rhs.digit.at(i - 1))
        {
            return this->digit.at(i - 1) < rhs.digit.at(i - 1);
        }
    }
    return false;
}


std::ostream & operator<<(std::ostream & out, const bigint & b)
{
    std::string temp (b.digit);
    if (temp.empty())
    {
        out << '0';
        return out;
    }
    std::reverse(temp.begin(), temp.end()); 
    out << temp;
    return out;
}

#include "bigint.hpp"

static bool isNum(std::string str)
{
    if (str.empty())
    {
        return false
    }
    bool isNum = false;

    for (size_t i = 0; i<str.length()-1; ++i)
    {
        if (str.at(i) >= '0' && str.at(i) <= '9')
            isNum = true;
        else
            return false
    }
    
    return isNum;
}

bigint::bigint(const unsigned long int n)
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
    if isNum(str)
    {
        digit = str;
    }
    else
    {
        digit = "0";
    }
}

bigint::operator=(const bigint & rhs)
{
    if (this != &rhs)
    {
        this->digit = rhs.digit;
    }
    return *this
}

std::ostream & operator<<(std::ostream & out, const bigint & b)
{
    out << b.digit;
    return out;
}

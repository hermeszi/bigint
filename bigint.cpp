#include "bigint.hpp"

/*
bigint::bigint() : digits("0") {}

bigint::bigint(unsigned long n)
{
    while (n > 0)
    {
        digits += (n % 10) + '0';
        n /= 10;
    }
}

bigint::bigint(std::string s) : digits(std::move(s))
{
    removeLeadingZeros();
}

bigint::bigint(const bigint &other) : digits(other.getDigits()) {}

bigint &bigint::operator=(const bigint &rhs)
{
    if (this != &rhs)
    {
        digits = rhs.digits;
    }
    return *this;
}

bigint::~bigint() {}

bigint bigint::operator+(const bigint &rhs) const
{
    bigint result;
    int carry = 0;
    size_t maxLength = std::max(digits.length(), rhs.digits.length());

    for (size_t i = 0; i < maxLength || carry; ++i)
    {
        int sum = carry;
        if (i < digits.length())
            sum += digits[i] - '0';
        if (i < rhs.digits.length())
            sum += rhs.digits[i] - '0';

        result.digits += (sum % 10) + '0';
        carry = sum / 10;
    }

    return result;
}

bool bigint::operator==(const bigint &rhs) const
{
    return digits == rhs.digits;
}

bool bigint::operator!=(const bigint &rhs) const
{
    return !(*this == rhs);
}

bool bigint::operator<(const bigint &rhs) const
{
    if (digits.length() != rhs.digits.length())
        return digits.length() < rhs.digits.length();

    for (size_t i = digits.length(); i-- > 0;)
    {
        if (digits[i] != rhs.digits[i])
            return digits[i] < rhs.digits[i];
    }
    return false;
}

bool bigint::operator>(const bigint &rhs) const
{
    return rhs < *this;
}

bool bigint::operator<=(const bigint &rhs) const
{
    return !(*this > rhs);
}

bool bigint::operator>=(const bigint &rhs) const
{
    return !(*this < rhs);
}

bigint bigint::operator<<(int n) const
{
    bigint result = *this;
    result.digits.insert(0, n, '0'); // shift left by adding zeros at the beginning
    return result;
}

bigint bigint::operator>>(int n) const
{
    bigint result = *this;
    if (n < result.digits.length())
        result.digits.erase(result.digits.length() - n); // shift right by removing digits from the end
    else
        result.digits = "0";
    return result;
}

std::ostream &operator<<(std::ostream &out, const bigint &b)
{
    for (size_t i = b.digits.length(); i-- > 0;)
    {
        out << b.digits[i];
    }
    return out;
}

void bigint::removeLeadingZeros()
{
    while (digits.length() > 1 && digits.back() == '0')
    {
        digits.pop_back();
    }
}

*/

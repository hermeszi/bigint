#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
private:
    std::string digits;  // REVERSED: 123 stored as "321"
    
    void removeLeadingZeros();  // helper: clean up internal representation

public:
    bigint();                     // default = 0
    bigint(unsigned long n);      // from number
    bigint(std::string s);        // from string
    bigint(const bigint &other);  // copy constructor
    bigint &operator=(const bigint &rhs);
    ~bigint();
    
    std::string getDigits() const { return digits; }  // for testing only

    // required operations
    bigint operator+(const bigint &rhs) const;
    
    bool operator==(const bigint &rhs) const;
    bool operator!=(const bigint &rhs) const;

    bool operator<(const bigint &rhs) const;
    bool operator>(const bigint &rhs) const;
    bool operator<=(const bigint &rhs) const;
    bool operator>=(const bigint &rhs) const;
    
    bigint operator<<(int n) const;  // digit shift left
    bigint operator>>(int n) const;  // digit shift right
};

std::ostream &operator<<(std::ostream &out, const bigint &b);
#endif // BIGINT_HPP

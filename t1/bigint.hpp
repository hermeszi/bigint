#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
    std::string digit;

    void removeZero();
public:
    std::string getDigit() {return digit;}

    explicit bigint(const unsigned long int n = 0);
    bigint (const bigint & other) {operator=(other)};
    bigint (const std::string str);
    ~bigint() {};

    bigint operator=(const bigint & rhs);

    bigint operator+(const bigint & rhs) const;
    bigint operator+(unsigned long int n) const;

    bigint & operator+=(const bigint & rhs); // return & 
    bigint & operator+=(unsigned long int n);

    bigint & operator++();
    const bigint operator++(int);

    bigint operator<<(unsigned long int n) const;
    bigint operator>>(unsigned long int n) const;
    bigint operator<<=(unsigned long int n);
    bigint operator>>=(unsigned long int n);
    bigint operator>>=(const bigint & rhs);

    bool operator==(const bigint & rhs) const;
    bool operator==(unsigned long int n) const;

    bool operator!=(const bigint & rhs) const;
    bool operator!=(unsigned long int n) const;

    bool operator>(const bigint & rhs) const;
    bool operator>(unsigned long int n) const;

    bool operator<(const bigint & rhs) const;
    bool operator<(unsigned long int n) const;

    bool operator>=(const bigint & rhs) const;
    bool operator>=(unsigned long int n) const;

    bool operator<=(const bigint & rhs) const;
    bool operator<=(unsigned long int n) const;


    friend std::ostream & operator<<(std::ostream & out, const bigint & b);

};

#endif

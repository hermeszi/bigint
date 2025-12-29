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


// #ifndef BIGINT_HPP
// #define BIGINT_HPP

// #include <string>
// #include <iostream>

// class bigint
// {
//     std::string digit;

//     void removeZero();
// public:
//     explicit bigint(unsigned long int n = 0);
//     bigint (const bigint & other);

//     ~bigint() {};

//     bigint operator=(const bigint & rhs);

//     bigint & operator+=(const bigint & rhs); // return & 
//     bigint & operator+=(unsigned long int n);

//     bigint operator+(const bigint & rhs) const;
//     bigint operator+(unsigned long int n) const;

//     bool operator==(const bigint & rhs) const;
//     bool operator==(unsigned long int n) const;

//     bool operator!=(const bigint & rhs) const;
//     bool operator!=(unsigned long int n) const;

//     bool operator>(const bigint & rhs) const;
//     bool operator>(unsigned long int n) const;

//     bool operator<(const bigint & rhs) const;
//     bool operator<(unsigned long int n) const;

//     bool operator>=(const bigint & rhs) const;
//     bool operator>=(unsigned long int n) const;

//     bool operator<=(const bigint & rhs) const;
//     bool operator<=(unsigned long int n) const;

//     bigint & operator++();
//     const bigint operator++(int);

//     bigint operator<<(unsigned long int n);
//     bigint operator>>(unsigned long int n);

//     friend std::ostream & operator<<(std::ostream out, const bigint & v);

// };

// #endif

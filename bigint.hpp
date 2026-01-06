#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint
{
    std::string digit;

    void removeZero();
public:
    std::string getDigit() const {return digit;}        //ok

    explicit bigint(unsigned long int n = 0);           //ok
    bigint (const bigint & other) {operator=(other);};   //ok
    bigint (const std::string str);                     //ok
    ~bigint() {};                                       //ok        

    bigint & operator=(const bigint & rhs);           //ok

    bigint operator+(const bigint & rhs) const;      //ok
    bigint operator+(unsigned long int n) const {return *this + bigint(n);};       

    bigint & operator+=(const bigint & rhs); // return & 
    bigint & operator+=(unsigned long int n);//ok

    bigint & operator++(); //ok
    const bigint operator++(int); //ok

    bigint operator<<(unsigned long int n) const;
    bigint operator<<(const bigint & rhs) const; //convert to unsigned long int
    bigint operator>>(unsigned long int n) const;
    bigint operator>>(const bigint & rhs) const; //convert back to unsigned long int
    bigint & operator<<=(unsigned long int n);
    bigint & operator>>=(unsigned long int n);
    bigint & operator>>=(const bigint & rhs); //convert back to unsigned long int

    bool operator==(const bigint & rhs) const {return this->digit == rhs.digit;};
    bool operator==(unsigned long int n) const {return *this == bigint(n);};

    bool operator!=(const bigint & rhs) const {return !(*this == rhs);};
    bool operator!=(unsigned long int n) const {return !(*this == bigint(n));};

    bool operator<(const bigint & rhs) const;
    bool operator<(unsigned long int n) const {return *this < bigint(n);};

    bool operator>(const bigint & rhs) const {return rhs < *this;};
    bool operator>(unsigned long int n) const {return *this > bigint(n);};

    bool operator<=(const bigint & rhs) const {return !(*this > rhs);};
    bool operator<=(unsigned long int n) const {return !(*this > bigint(n));};

    bool operator>=(const bigint & rhs) const {return !(*this < rhs);};
    bool operator>=(unsigned long int n) const {return !(*this < bigint(n));};


    friend std::ostream & operator<<(std::ostream & out, const bigint & b);

};

#endif

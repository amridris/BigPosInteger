//
// Created by amer0 on 9/9/2017.
//

#include "bigPosInteger.h"

bigPosInteger::bigPosInteger(std::string value)
/*This constructor should take in a string containing a set of chars between '0' and '9' of arbitrary length and constructs it into bigPosInteger type*/
{
}

bigPosInteger::bigPosInteger(int value)
/*this instructor takes in an integer and constructs it into a bigPosInteger type*/
{
}

bigPosInteger::bigPosInteger(const bigPosInteger& value)
/*This is a copy constructor, be EXTREMELY careful for memory leaks here*/
{
}

bigPosInteger::~bigPosInteger()
/*This is the destructor, be extremely careful for memory leaks here*/
{
}

bigPosInteger bigPosInteger::operator+ (const bigPosInteger& rhs)
/*this operator should be able to add two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{
    return bigPosInteger(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>());
}

bigPosInteger bigPosInteger::operator- (const bigPosInteger& rhs)
/*this operator should be able to subtract the Right Hand Side bigPosInteger from the base bigPosInteger and return the result. The default return should be replaced with the appropriate variable*/
{
    return bigPosInteger(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>());
}

bigPosInteger bigPosInteger::operator*(const bigPosInteger& rhs)
/*this operator should be able to multiply two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{
    return bigPosInteger(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>());
}

bigPosInteger &bigPosInteger::operator=(const bigPosInteger& rhs)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    return <#initializer#>;
}

std::ostream &operator<<(std::ostream & stream, const bigPosInteger& rhs)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    return <#initializer#>;
}

std::istream &operator>>(std::istream &, bigPosInteger &)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    return <#initializer#>;
}
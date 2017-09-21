//
// Created by amer0 on 9/9/2017.
//

#ifndef BIGPOSINTEGER_BIGPOSINTEGER_H
#define BIGPOSINTEGER_BIGPOSINTEGER_H

#include <iostream>
#include <string>
#include <stdlib.h>



class bigPosInteger {
    int * valueArray;
    long long length;

public:
    explicit bigPosInteger();
    explicit bigPosInteger(std::string value);
    explicit bigPosInteger(int valArr);
    bigPosInteger(const bigPosInteger& );//copy constructor
    virtual ~bigPosInteger();

    bigPosInteger operator+(const bigPosInteger&);
    bigPosInteger operator-(const bigPosInteger&);
    bigPosInteger operator*(const bigPosInteger&);
    bigPosInteger& operator=(const bigPosInteger&);
    friend std::ostream& operator<< (std::ostream&, const bigPosInteger&);
    friend std::istream& operator>> (std::istream&, bigPosInteger&);
};



#endif //BIGPOSINTEGER_BIGPOSINTEGER_H

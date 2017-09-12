//
// Created by amer0 on 9/9/2017.
//
using namespace std;
#include "bigPosInteger.h"


bigPosInteger::bigPosInteger(std::string value)
/*This constructor should take in a string containing a set of chars between '0' and '9' of arbitrary length and constructs it into bigPosInteger type*/
{
    int x;
    //created a dynamic array of memory to fit all the digits in array without '0'
    length = value.length()-1;
    valueArray = new (nothrow) int(length);

    // Initialize array
    for(x=0; x<=length;x++)
    {
        valueArray[x] = 0;
    }

    //loop through the string and insert the value into the dynamic array // used '0' to get the actual value
    for (x=0;x<=length;x++)

        valueArray[x] = (value[x] - '0');

    }


bigPosInteger::bigPosInteger(int value)
/*this instructor takes in an integer and constructs it into a bigPosInteger type*/
{
    string value1;
    value1 = to_string(value);

    int x;
    //created a dynamic array of memory to fit all the digits in array without '0'
    length = value1.length()-1;
    valueArray = new (nothrow) int(length);

    // Initialize array
    for(x=0; x<=length;x++)
    {
        valueArray[x] = 0;
    }

    //loop through the string and insert the value into the dynamic array // used '0' to get the actual value
    for (x=0;x<=length;x++)

        valueArray[x] = (value1[x] - '0');

}



bigPosInteger::bigPosInteger(const bigPosInteger& value)
/*This is a copy constructor, be EXTREMELY careful for memory leaks here*/
{
    //Since Length is not a pointer, we shallow copy the content to length.
    length = value.length;

    //IF statement to check and see if the object value has data"numbers"
    if(value.valueArray)
    {
        //If there are numbers in value object, we create a new block memory to save it
        valueArray = new int[length];

        //for loop to copy the content of value object to the new object "Deep Copy"
        for(int i=0; i<length;++i)
        {
            valueArray[i]= value.valueArray[i];
        }

    }
    //If value is empty, the valueArray object will be donated as zero
    else{

        valueArray = 0;
    }


}

bigPosInteger::~bigPosInteger()
/*This is the destructor, be extremely careful for memory leaks here*/
{
    delete []valueArray;

}

bigPosInteger bigPosInteger::operator+ (const bigPosInteger& rhs)
/*this operator should be able to add two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{
    //create a new object to save the result
    bigPosInteger result;
    long long temp;
    long long size;
    int carry;

    //Compare the sizes of the two operand using if statement
    if(this->length>rhs.length)
    {
        //if "this" is greater than rhs, it becomes the primary operand and the new object size will be set size of this object +1 for the carry
        result.length = this->length+1;
        //loop through the values and add
        for(size = result.length; size>=0; size--)
        {
            //create a temp memory to hold the value
            temp = this->valueArray[size]+rhs.valueArray[size]+carry;

            //check to see if the addition produce a carry
            if(temp>=10)
            {
                temp = temp %10;
                carry = 1;
                result.valueArray[size] = temp;
            }
            else{
                result.valueArray[size] = temp;
                carry = 0;
            }
        }

    }
    else {
        //Repeat the above process but we are setting the length to rhs.length
        result.length = rhs.length;
        for(size = result.length; size>=0; size--)
        {
            temp = rhs.valueArray[size]+rhs.valueArray[size]+carry;
        }
        if(temp>=10)
        {
            temp = temp %10;
            carry = 1;
            result.valueArray[size] = temp;
        }

        else{
            result.valueArray[size]=temp;
            carry = 0;
        }

    }
    return result;
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
    //checking to see if the rhs object is not the same as the "this" object
    if(this == &rhs)
    {
        return *this;
    }

    //delete any memory that this object is holding so we can copy the data from rhs
    delete[]valueArray;


    //shallow copy the length
    length = rhs.length;

    //deep copying the values to "this" object
    if(rhs.valueArray) {
        //create a new block memory to copy the data (integers)
        valueArray = new int[length];

        //Deep copy the values
        for (int i = 0; i < length; ++i) {
            valueArray[i] = rhs.valueArray[i];
        }


    }

    //if there are no values assign this value array to zero
    else {
        valueArray = 0;
    }
    //Since it is referenced object we return it using pointer "*this"
    return *this;

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
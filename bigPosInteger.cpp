//
// Created by amer0 on 9/9/2017.
//
using namespace std;
#include "bigPosInteger.h"


bigPosInteger::bigPosInteger() {
    length = 0;
    valueArray = NULL;
}
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
/*this Constructor takes in an integer and constructs it into a bigPosInteger type*/
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
    this ->length = value.length;

    //IF statement to check and see if the object value has data"numbers"
    if(value.valueArray)
    {
        //If there are numbers in value object, we create a new block memory to save it
        this ->valueArray = new int[length];

        //for loop to copy the content of value object to the new object "Deep Copy"
        for(int i=0; i<length;++i)
        {
            this->valueArray[i]= value.valueArray[i];
        }

    }
    //If value is empty, the valueArray object will be donated as zero
    else{

        this->valueArray = 0;
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
    int carry=0;

    //Carry is always 0 at the beginning of the addition
    //if this-> length is greater than rhs.length, then result.valueArray size will equal to this->length + for any carry over.
    if(this->length > rhs.length)
    {
        result.length = this->length+1;
        result.valueArray = new int[result.length];

    }
    // else we just assign the size of result.valueArray to the size of rhs.valueArray+1 for the carry.
    else {
        result.length = rhs.length+1;
        result.valueArray = new int [result.length];
    }
    //Loop through the array to start the addition
    for(int i= result.length;i>=result.length;i--)
    {
        //Add the values from the two arrays and save it in temp
        temp = this->valueArray[i]+rhs.valueArray[i]+carry;
        //if temp is greater than 10, we have a carry
        if(temp>=10)
        {
            // result will be temp value - 10
            result.valueArray[i] = temp%10;
            //Carry will be set to one
            carry = 1;
        }
        else{
            //just add the two values
            result.valueArray[i] = temp;
            //since the values are not bigger than 10, carry will remain 0
            carry = 0;
        }
    }

//return the object result
    return result;
}

bigPosInteger bigPosInteger::operator- (const bigPosInteger& rhs)
/*this operator should be able to subtract the Right Hand Side bigPosInteger from the base bigPosInteger and return the result. The default return should be replaced with the appropriate variable*/
{
    bigPosInteger result;
    long long temp;
    int borrow;

    //if this->length is greater than rhs.length, result.valueArray size will be equal to this->length.
    if(this->length> rhs.length)
    {
        result.length = this->length;
        result.valueArray = new int [result.length];
        //Initialize the result.valueArray to zero
        for(int i=0; i<=result.length; i++){
            result.valueArray[i] = 0;
        }
    }
    //Else the size of result.valueArray will be set to rhs.length
    else {
        result.length = rhs.length;
        result.valueArray = new int[result.length];
        //Initialize the result.valueArray to zero
        for(int i=0; i<=result.length; i++){
            result.valueArray[i] = 0;
        }
    }

    borrow = 0;
    //borrow at the beginning of subtraction is always 0 zero
    for(int i = result.length; i>=0; i--)
    {
        //If there was no borrow, compare the numbers
        if(borrow == 0)
        {
            //if the first operand is greater the second operand then simply subtract
            if(this->valueArray[i]>=rhs.valueArray[i])
            {
                result.valueArray[i] = this->valueArray[i] - rhs.valueArray[i];
            }
            //If the second operand is greater then 2nd operand, borrow from the next digit and add 10: A-B+10
            else {
                result.valueArray[i] = this->valueArray[i]+10-rhs.valueArray[i];
                borrow = 1;

            }
        }
        //Here borrow = 1, therefore we deduct the "1" value from the next subtraction
        else {
            //Compare the number and if the first operand is greater than second simply subtract and also deduct the borrow value.
            if(this->valueArray[i]-1>=rhs.valueArray[i])
            {
                result.valueArray[i] = this->valueArray[i]-rhs.valueArray[i]-1;
                borrow = 0;
            }
            // if the 2nd digit is greater than the first, then add 10 and deduct from the borrow: A+B-1+10 or A+B+9
            else{
                result.valueArray[i]= this->valueArray[i]-rhs.valueArray[i]+9;
                borrow = 1;
            }
        }
    }
    return result;
}

bigPosInteger bigPosInteger::operator*(const bigPosInteger& rhs)
/*this operator should be able to multiply two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{
    bigPosInteger result;

    long long temp, carry, large, small, i, j;

    //create a space for the result.
    result.length =  this->length + rhs.length -1;
    result.valueArray = new int[result.length];

    //Initialize new object result values to zero
    for(i=0;i<result.length;i++)
    {
        result.valueArray[i]=0;
    }

    if(this->length > rhs.length)
    {
        large = this->length;
        small = rhs.length;
    }
    else
    {
        large = rhs.length;
        small = this->length;
    }

    for(i=small;i<=small;i--)
    {
        for(j=large;i>=large;j--)
        {
            temp = rhs.valueArray[i]*this->valueArray[j];
            if(temp > 10)
            {
                temp %= 10;
                carry =  temp/10;
                result.valueArray[i+j] += temp+carry;
                carry=0;
            }
            else{
                result.valueArray[i+j]+= temp;
            }
        }
    }

    return result;

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



    //shallow copy the length value
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
    //Initialize variables
    long long i = rhs.length;
    int x;


    //Loop through to skip the leading zeroes
    for(int x =0; x<=i;x++)
    {
        //exit the loop if the first number was found
        if(valueArray[i]>0)
        {
            break;
        }

    }

    //continue printing the numbers without skipping any zeroes.
    for(x; x<=i;x++)
    {
        stream << valueArray[i];
    }

    //return stream
    return stream;

}

std::istream &operator>>(std::istream &input, bigPosInteger &rhs)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    //Initializing variables
    int i;
    string userIn;

    //save user's input
    input>>userIn;

    //Check the user's input before extracting for further use (looping till the '\0' character is encountered.
    for(i=0;i<=userIn.length()-1;i++)
    {
        //use the isdigit function to check if input is a decimal;
        if(!isdigit(userIn[i]))
        {
            cerr<<"Inacceptable charater was inputted, exiting program"<<endl;
            exit(1);
        }
    }


    //create a new temp object and save the result if all inputs are decimals.
    bigPosInteger temp(userIn);

    //let rhs be equal to temp
    rhs=temp;



    return input;

}
using namespace std;
#include "bigPosInteger.h"

//create extra space to avoid program crashes and aligns mathematical operations
#define size 10000

bigPosInteger::bigPosInteger() {
    this->length = 0;
    this->valueArray = nullptr;
    }

bigPosInteger::bigPosInteger(string value)
/*This constructor should take in a string containing a set of chars between '0' and '9' of arbitrary length and constructs it into bigPosInteger type*/
{
    //Copy length to this object
    this->length = value.length()-1;

    //create the size of the array to accommodate the digits array
    this->valueArray = new int[size];

    //Initialize the new block memory to avoid and garbage values and crashes
    for(int x=0; x<=size;x++)
    {
        this->valueArray[x]=0;
    }


    //loop through the string and insert the value into the dynamic array // used '0' to get the actual value
    for (int x=0;x<=this->length;x++) {

        valueArray[size - x] = (value[length - x] - '0');
    }
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
        this ->valueArray = new int[length+size];

        //for loop to copy the content of value object to the new object "Deep Copy"
        for(int i=0; i<=length;++i)
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
    if(valueArray) {
        delete[]valueArray;
        valueArray = nullptr;
    }
}

bigPosInteger bigPosInteger::operator+ (const bigPosInteger& rhs)
/*this operator should be able to add two bigPosInteger together and return the result. The default return should be replaced with the appropriate variable*/
{
    //create a new object to save the result
    bigPosInteger result;
    //Carry is always 0 at the beginning of the addition
    int carry = 0;
    int s;

    result.valueArray = new int[size];

    //Initialize the result object
    for (int y = 0; y <= size; y++) {
        result.valueArray[y] = 0;
    }

    //Compare the length values and assign it to s
    if (this->length > rhs.length) {
        s = this->length;
    } else {
        s = rhs.length;
    }


    for (long long i = size; i >= (size - s); i--) {

        //Sum the values and save it in result
        result.valueArray[i] = this->valueArray[i] + rhs.valueArray[i] + carry;

        //Check to see if the value is greater than 9
        if (result.valueArray[i] > 9) {

            //take the reminder value and set carry to 1
            result.valueArray[i] %= 10;


            carry = 1;

        } else {
            //carry will remain 0 for the next addition
            carry = 0;
        }

        //If the loop is complete and carry is still 1, add a extra space of memory to add a 1 and set the length to s+1
        if (carry == 1) {
            result.length = s + 1;
            result.valueArray[size - s + 1] = 1;


        } else {
            //result length is s
            result.length = s;
        }

    }

    return result;
}


bigPosInteger bigPosInteger::operator- (const bigPosInteger& rhs)
/*this operator should be able to subtract the Right Hand Side bigPosInteger from the base bigPosInteger and return the result. The default return should be replaced with the appropriate variable*/
{
    bigPosInteger result;
    long long temp;
    int borrow;

    //create a new memory block for result
    result.valueArray= new int[size];

    for(int i=0; i<=size;i++){
        //Initialize the result.valueArray to zero
        result.valueArray[i]=0;
    }


    //if this->length is greater than rhs.length, result.valueArray size will be equal to this->length.
    if(this->length> rhs.length)
    {
        result.length = this->length;
    }
        //Else the size of result.valueArray will be set to rhs.length
    else {
        result.length = rhs.length;
    }

    //borrow at the beginning of subtraction is always 0 zero
    borrow = 0;

    for(int i=0; i<=result.length;i++)
    {
        //If there was no borrow, compare the numbers
        if(borrow == 0)
        {
            //if the first operand is greater the second operand then simply subtract
            if(this->valueArray[size-i]>=rhs.valueArray[size-i])
            {
                result.valueArray[size-i] = this->valueArray[size-i] - rhs.valueArray[size-i];
            }
                //If the second operand is greater then 2nd operand, borrow from the next digit and add 10: A-B+10
            else {
                result.valueArray[size-i] = this->valueArray[size-i]+10-rhs.valueArray[size-i];
                borrow = 1;

            }
        }
            //Here borrow = 1, therefore we deduct the "1" value from the next subtraction
        else {
            //Compare the number and if the first operand is greater than second simply subtract and also deduct the borrow value.
            if(this->valueArray[size-i]-1>=rhs.valueArray[size-i])
            {
                result.valueArray[size-i] = this->valueArray[size-i]-rhs.valueArray[size-i]-1;
                borrow = 0;
            }
                // if the 2nd digit is greater than the first, then add 10 and deduct from the borrow: A+B-1+10 or A+B+9
            else{
                result.valueArray[size-i]= this->valueArray[size-i]-rhs.valueArray[size-i]+9;
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
    int multi, carry=0, i, carry_add=0;
    long long temp=0, temp_add=0;
    result.valueArray = new int[size];

    //Initialize result
    for(i=0; i<=size;i++)
    {
        result.valueArray[i] = 0;
    }

    //check objects length and set result.length to the larger value.
    if(this->length>=rhs.length) {
        multi = rhs.length;
        result.length = this->length;

        for (int y = 0, shift = 0; y <= multi; y++, shift++) {

            for (int i = 0; i <= result.length; i++) {

                //save the result in temp
                temp = (this->valueArray[size - i] * rhs.valueArray[size - y]) + carry;


                //if temp greater than 9, take the mod value and carry will be set to temp/10.
                if (temp > 9 && i < result.length) {
                    //result is shifted with each loop for addition alignment
                    result.valueArray[size - i - shift] += (temp % 10);
                    carry = temp / 10;

                }

                    //testing the last multiplication value and creating a new space for the leading carry
                else if (temp > 9 && i == result.length) {
                    result.valueArray[size - i - shift] += (temp % 10);
                    carry = temp / 10;
                    result.valueArray[size - i - shift - 1] = carry;
                    carry = 0;

                }
                    //simply add the value
                else {
                    //similar to the above code but there is no carry
                    carry = 0;
                    result.valueArray[size - i - shift] += temp;
                }

            }
        }

        for (int z = 1; z <= size; z++) {
            result.valueArray[size - z] = result.valueArray[size - z] + carry_add;

            if (result.valueArray[size - z] > 9) {
                carry_add = result.valueArray[size - z] / 10;
                result.valueArray[size - z] = result.valueArray[size - z] % 10;

            } else {
                carry_add = 0;
            }
        }
    }







    else {
        multi = this->length;
        result.length = rhs.length;

        for (int y = 0, shift = 0; y <= multi; y++, shift++) {

            for (int i = 0; i <=result.length; i++) {

                //save the result in temp
                temp = (this->valueArray[size -y] * rhs.valueArray[size - i]) + carry;


                //if temp greater than 9, take the mod value and carry will be set to temp/10.
                if (temp > 9 && i < result.length) {
                    //result is shifted with each loop for addition alignment
                    result.valueArray[size - i - shift] += (temp % 10);
                    carry = temp / 10;


                }

                    //testing the last multiplication value and creating a new space for the leading carry
                else if (temp > 9 && i == result.length) {
                    result.valueArray[size - i - shift] += (temp % 10);
                    carry = temp / 10;
                    result.valueArray[size - i - shift - 1] = carry;
                    carry=0;

                }
                    //simply add the value
                else {
                    //similar to the above code but there is no carry
                    carry = 0;
                    result.valueArray[size - i - shift] += temp;
                }

            }
        }


        for (int z = 1; z <= (result.length+1); z++) {

            result.valueArray[size - z] = result.valueArray[size - z] + carry_add;

            if (result.valueArray[size - z] > 9) {
                carry_add = result.valueArray[size - z] / 10;
                result.valueArray[size - z] = result.valueArray[size - z] % 10;

            } else {
                carry_add = 0;
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

    else {

        //delete any memory that this object is holding so we can copy the data from rhs
        delete[]this->valueArray;

        //shallow copy the length value
        length = rhs.length;

            //create a new block memory to copy the data (integers)

            valueArray = new int[size];

            for (int i = 0; i <= size; i++) {
                this->valueArray[i] = 0;
            }



            //Deep copy the values
            for (int i = 0; i <= size; i++) {
                this->valueArray[i] = rhs.valueArray[i];
            }



        //Since it is referenced object we return it using pointer "*this"
        return *this;
    }

}

std::ostream &operator<<(std::ostream & stream, const bigPosInteger& rhs)
/* this is the copy assignment operator, be EXTREMELY careful for memory leaks here. The default return should be replaced with the appropriate variable*/
{
    //Initialize variables
    int index=0;


    //Loop through and skip the leading zeroes
    while(rhs.valueArray[index]==0)
    {
        index++;
    }

    //continue printing the numbers without skipping any zeroes.
    for(index; index<=size;index++)
    {
        stream<<rhs.valueArray[index];
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
    input >> userIn;

    //Check the user's input before extracting for further use (looping till the '\0' character is encountered.
    for (i = 0; i <= userIn.length() - 1; i++) {
        //use the isdigit function to check if input is a decimal;
        if (!isdigit(userIn[i])) {
            cerr << "Inacceptable charater was inputted, exiting program" << endl;
            exit(1);
        }
    }


    //create a new temp object and save the result if all inputs are decimals.
    bigPosInteger temp(userIn);

    //let rhs be equal to temp
    rhs = temp;


    return input;

}

bigPosInteger bigPosInteger::operator%(const bigPosInteger &rhs) {

    bigPosInteger partialRes;
    bigPosInteger result;
    long long temp_val[200], temp_val2[200];
    long long length2;

    partialRes.valueArray = new int [size];
    for(int i=0; i<=50;i++)
    {
        temp_val[i] = 0;
    }

    for(int i=0; i<=size;i++)
    {
        partialRes.valueArray[i] = 0;
    }


    if(this->length>rhs.length)
    {
        partialRes.length = this->length;
        length2 = rhs.length;

    }

    else{
        partialRes.length = rhs.length;
        length2 = rhs.length;
    }

    for(int i=0; i<=length2;i++)
    for(int i=0;i<=partialRes.length;i++)
    {
        partialRes.valueArray[size-i]= this->valueArray[size-i];
        temp_val[size-i] = partialRes.valueArray[size-i]*10^i;
    }


    for(int i=0; i<=length2;i++)
    {
        temp_val2[size-i] = rhs.valueArray[size-i]*10^i;

    }

    for(int i=0; i<=partialRes.length; i++)
    {
        result.valueArray[size-i] = temp_val[size-i]/temp_val2[size-i];
    }

    return result;

}
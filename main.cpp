#include <iostream>
#include "bigPosInteger.h"
#include <string>
using namespace std;


int main() {

    bigPosInteger num1 ("9");
    bigPosInteger num2("9");
    bigPosInteger num3;
    num3 = num1*num2;

    cout<<"\nnum3: " <<num3;




    return 0;
}


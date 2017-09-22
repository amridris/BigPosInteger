#include <iostream>
#include "bigPosInteger.h"
#include <string>
using namespace std;


int main() {

    bigPosInteger num1("123156465456132132");
    bigPosInteger num2("46541561213213131");
    bigPosInteger num3;
    bigPosInteger num4;
    bigPosInteger num5;
    bigPosInteger num6;

    num3 = num1+ num2;

    num4 = num1-num2;

    num5 = num1*num2;



    cout<<"num3: "<<num3<<endl;
    cout<<"num4: "<<num4<<endl;
    cout<<"num5: "<<num5<<endl;

    return 0;
}


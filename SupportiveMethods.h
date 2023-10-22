#ifndef SUPPORTIVEMETHODS_h
#define SUPPORTIVEMETHODS_h
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class SupportiveMethods {

    public:
    static string readLine();
    static string convertFromIntToString(int number);
    static int convertFromStringToInt(string number);
    static string swapFirstLetterForLargeOtherForSmall(string text);
    static string getNumber(string text, int positionSign);
    static char readSign();
    static int readNumber();

};

#endif

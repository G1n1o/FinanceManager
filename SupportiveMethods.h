#ifndef SUPPORTIVEMETHODS_h
#define SUPPORTIVEMETHODS_h
#include <iostream>
#include <sstream>
#include <algorithm>
#include "date.h"

using namespace std;
using namespace date;

class SupportiveMethods {

    public:
    static string readLine();
    static string convertFromIntToString(int number);
    static int convertFromStringToInt(string number);
    static string convertFromFloatToString(float amount);
    static string swapFirstLetterForLargeOtherForSmall(string text);
    static char readSign();
    static int readNumber();
    static string getCurrentDate();
    static bool isValidDate(string inputDate);
    static string swapCommaToDot(string input);
};

#endif

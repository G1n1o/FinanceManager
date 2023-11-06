#ifndef SUPPORTIVEMETHODS_h
#define SUPPORTIVEMETHODS_h
#include <iostream>
#include <sstream>
#include <algorithm>
#include "date.h"
#include "Transaction.h"

using namespace std;
using namespace date;

class SupportiveMethods {

    public:
    static string readLine();
    static string convertFromFloatToString(float amount);
    static string swapFirstLetterForLargeOtherForSmall(string text);
    static char readSign();
    static string getCurrentDate();
    static bool isValidDate(string inputDate);
    static string swapCommaToDot(string input);
    static bool compareByDate(Transaction a, Transaction b);
    static year_month_day convertFromStringToDate (string input);
};

#endif

#ifndef SUPPORTIVEMETHODS_h
#define SUPPORTIVEMETHODS_h
#include <iostream>
#include <sstream>
#include <algorithm>
#include "date.h"
#include "Transaction.h"

class SupportiveMethods {

    public:
    static std::string readLine();
    static std::string convertFromFloatToString(float amount);
    static std::string swapFirstLetterForLargeOtherForSmall(std::string text);
    static char readSign();
    static std::string getCurrentDate();
    static bool isValidDate(std::string inputDate);
    static std::string swapCommaToDot(std::string input);
    static bool compareByDate(Transaction a, Transaction b);
    static date::year_month_day convertFromStringToDate (std::string input);
};

#endif

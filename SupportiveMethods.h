#ifndef SUPPORTIVEMETHODS_h
#define SUPPORTIVEMETHODS_h
#include <iostream>
#include <sstream>
#include <algorithm>
#include "date.h"
#include "Incomes.h"
#include "Expenses.h"

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
    static bool compareIncomeByDate(Income a, Income b);
    static bool compareExpenseByDate(Expense a, Expense b);
};

#endif

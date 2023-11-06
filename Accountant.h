#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H


#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "date.h"
#include "Transaction.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"


using namespace std;
using namespace date;

class Accountant {

FileWithIncomes fileWithIncomes;
FileWithExpenses fileWithExpenses;
vector <Transaction> incomes;
vector <Transaction> expenses;

const int ID_LOGGED_USER;

Transaction enterDataNewIncome();
Transaction enterDataNewExpense();
void printTransaction(Transaction trans);
void displayBalance(year_month_day targetDate);
void showResult (float sumIncomes, float sumExpenses);
string dateCheck(string &date);

public:
     Accountant(string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser)
        : fileWithIncomes(fileNameWithIncomes),fileWithExpenses(fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser) {
       incomes = fileWithIncomes.loadIncomesLoggedUserFile(ID_LOGGED_USER);
       expenses = fileWithExpenses.loadExpensesLoggedUserFile(ID_LOGGED_USER);
    };
    void addNewIncome();
    void addNewExpense();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceInDateRange();

};

#endif


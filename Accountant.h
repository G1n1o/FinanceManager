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


class Accountant {

FileWithIncomes fileWithIncomes;
FileWithExpenses fileWithExpenses;
std::vector <Transaction> incomes;
std::vector <Transaction> expenses;

const int ID_LOGGED_USER;

Transaction enterDataNewIncome();
Transaction enterDataNewExpense();
void printTransaction(Transaction trans);
void displayBalance(date::year_month_day targetDate);
void showResult (float sumIncomes, float sumExpenses);
std::string dateCheck(std::string &date);

public:
     Accountant(std::string fileNameWithIncomes, std::string fileNameWithExpenses, int idLoggedUser)
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


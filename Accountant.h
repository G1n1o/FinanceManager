#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H


#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>
#include "date.h"
#include "Incomes.h"
#include "Expenses.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"


using namespace std;
using namespace date;

class Accountant {

FileWithIncomes fileWithIncomes;
FileWithExpenses fileWithExpenses;
vector <Income> incomes;
vector <Expense> expenses;

const int ID_LOGGED_USER;

Income enterDataNewIncome();
Expense enterDataNewExpense();
void printData(Income income);

public:
     Accountant(string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser)
        : fileWithIncomes(fileNameWithIncomes),fileWithExpenses(fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser) {
       incomes = fileWithIncomes.loadIncomesLoggedUserFile(ID_LOGGED_USER);
       expenses = fileWithExpenses.loadExpensesLoggedUserFile(ID_LOGGED_USER);
    };
    void addNewIncome();
    void addNewExpense();
    void showUserIncomes();
    void displayBalanceForCurrentMonth();

};

#endif


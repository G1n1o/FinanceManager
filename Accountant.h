#ifndef ACCOUNTANT_H
#define ACCOUNTANT_H


#include <iostream>
#include <vector>
#include <sstream>
#include "Incomes.h"
#include "Expenses.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"


using namespace std;

class Accountant {

FileWithIncomes fileWithIncomes;
FileWithExpenses fileWithExpenses;
vector <Income> incomes;
vector <Expense> expenses;

const int ID_LOGGED_USER;

public:
     Accountant(string fileNameWithIncomes, string fileNameWithExpenses, int idLoggedUser)
        : fileWithIncomes(fileNameWithIncomes),fileWithExpenses(fileNameWithExpenses), ID_LOGGED_USER(idLoggedUser) {
       // incomes = fileWithIncomes.loadIncomesLoggedUserFile(ID_LOGGED_USER);
       // expenses = fileWithExpenses.loadExpensesLoggedUserFile(ID_LOGGED_USER);
    };
    void addIncome();

};

#endif


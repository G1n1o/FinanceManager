#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H


#include <iostream>
#include <vector>
#include <filesystem>
#include <sstream>
#include "Markup.h"
#include "Transaction.h"
#include "SupportiveMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithExpenses : public TextFile {
    int idLastExpense;

public:
    FileWithExpenses(string fileNameWithExpenses) : TextFile(fileNameWithExpenses) {
        idLastExpense = 0;
    };
    vector <Transaction> loadExpensesLoggedUserFile(int IdLoggedUser);
    bool addExpenseToFile(Transaction expense);
    int getIdLastExpense();

};

#endif

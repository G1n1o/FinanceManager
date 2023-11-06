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


class FileWithExpenses : public TextFile {
    int idLastExpense;

public:
    FileWithExpenses(std::string fileNameWithExpenses) : TextFile(fileNameWithExpenses) {
        idLastExpense = 0;
    };
    std::vector <Transaction> loadExpensesLoggedUserFile(int IdLoggedUser);
    bool addExpenseToFile(Transaction expense);
    int getIdLastExpense();

};

#endif

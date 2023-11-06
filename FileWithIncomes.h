#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H


#include <iostream>
#include <vector>
#include <filesystem>
#include <sstream>
#include "Markup.h"
#include "Transaction.h"
#include "SupportiveMethods.h"
#include "TextFile.h"


class FileWithIncomes : public TextFile {
    int idLastIncome;

public:
     FileWithIncomes(std:: string fileNameWithIncomes) : TextFile(fileNameWithIncomes) {
          idLastIncome = 0;
    };
    std::vector <Transaction> loadIncomesLoggedUserFile(int IdLoggedUser);
    bool addIncomeToFile(Transaction income);
    int getIdLastIncome();

};

#endif

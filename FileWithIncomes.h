#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H


#include <iostream>
#include <vector>
#include <filesystem>
#include <sstream>
#include "Markup.h"
#include "Incomes.h"
#include "SupportiveMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithIncomes : public TextFile {
    int idLastIncome;

public:
     FileWithIncomes(string fileNameWithIncomes) : TextFile(fileNameWithIncomes) {
          idLastIncome = 0;
    };
    vector <Income> loadIncomesLoggedUserFile(int IdLoggedUser);
    bool addIncomeToFile(Income income);
    int getIdLastIncome();

};

#endif

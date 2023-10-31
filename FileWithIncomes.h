#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H


#include <iostream>
#include <vector>
#include <filesystem>
#include "Markup.h"
#include "Incomes.h"
#include "SupportiveMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithIncomes : public TextFile {

public:
     FileWithIncomes(string fileNameWithIncomes) : TextFile(fileNameWithIncomes) {
    };

    void addIncome(Income income);

};

#endif

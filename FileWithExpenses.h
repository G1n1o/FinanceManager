#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H


#include <iostream>
#include <vector>
#include <filesystem>
#include "Markup.h"
#include "Expenses.h"
#include "SupportiveMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithExpenses : public TextFile {

public:
     FileWithExpenses(string fileNameWithExpenses) : TextFile(fileNameWithExpenses) {};


};

#endif

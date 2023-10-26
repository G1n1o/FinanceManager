#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>
#include <ctime>

using namespace std;

class Income {
    int incomeId, idUser;
    tm date;
    string item;
    float amount;


public:
    void setIncomeId (int newIncomeId);
    void setIdUser (int newIdUser);
    void setDate (tm newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getIncomeId();
    int getIdUser();
    tm getDate();
    string getItem();
    float getAmount();
};

#endif

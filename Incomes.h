#ifndef INCOMES_H
#define INCOMES_H

#include <iostream>


using namespace std;

class Income {
    int incomeId, idUser;
    string date;
    string item;
    float amount;


public:
    void setIncomeId (int newIncomeId);
    void setIdUser (int newIdUser);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getIncomeId();
    int getIdUser();
    string getDate();
    string getItem();
    float getAmount();
};

#endif

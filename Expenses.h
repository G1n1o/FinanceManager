#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>

using namespace std;

class Expense {
    int expenseId, idUser;
    string date;
    string item;
    float amount;


public:
    void setExpenseId (int newExpenseId);
    void setIdUser (int newIdUser);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getExpenseId();
    int getIdUser();
    string getDate();
    string getItem();
    float getAmount();
};

#endif

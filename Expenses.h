#ifndef EXPENSES_H
#define EXPENSES_H

#include <iostream>
#include <ctime>

using namespace std;

class Expense {
    int expenseId, idUser;
    tm date;
    string item;
    float amount;


public:
    void setExpenseId (int newExpenseId);
    void setIdUser (int newIdUser);
    void setDate (tm newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getExpenseId();
    int getIdUser();
    tm getDate();
    string getItem();
    float getAmount();
};

#endif

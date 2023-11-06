#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>


using namespace std;

class Transaction {
    int transId, idUser;
    string date;
    string item;
    float amount;


public:
    void setTransId (int newTransId);
    void setIdUser (int newIdUser);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);

    int getTransId();
    int getIdUser();
    string getDate();
    string getItem();
    float getAmount();
};

#endif

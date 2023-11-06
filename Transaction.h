#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>


class Transaction {
    int transId, idUser;
    std::string date;
    std::string item;
    float amount;


public:
    void setTransId (int newTransId);
    void setIdUser (int newIdUser);
    void setDate (std::string newDate);
    void setItem (std::string newItem);
    void setAmount (float newAmount);

    int getTransId();
    int getIdUser();
    std::string getDate();
    std::string getItem();
    float getAmount();
};

#endif

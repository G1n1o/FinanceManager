#include "Transaction.h"

void Transaction::setTransId (int newTransId) {
    if (newTransId >= 0) {
        transId = newTransId;
    }
}
void Transaction::setIdUser (int newIdUser) {
    if (newIdUser >= 0) {
        idUser = newIdUser;
    }
}
void Transaction::setDate (std::string newDate) {
    date = newDate;
}
void Transaction::setItem (std::string newItem) {
   item = newItem;
}
void Transaction::setAmount (float newAmount) {
    amount = newAmount;
}

int Transaction::getTransId() {
    return transId;
}
int Transaction::getIdUser() {
    return idUser;
}
std::string Transaction::getDate() {
    return date;
}
std::string Transaction::getItem() {
    return item;
}
float Transaction::getAmount() {
    return amount;
}


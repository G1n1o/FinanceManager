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
void Transaction::setDate (string newDate) {
    date = newDate;
}
void Transaction::setItem (string newItem) {
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
string Transaction::getDate() {
    return date;
}
string Transaction::getItem() {
    return item;
}
float Transaction::getAmount() {
    return amount;
}


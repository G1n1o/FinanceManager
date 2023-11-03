#include "Incomes.h"

void Income::setIncomeId (int newIncomeId) {
    if (newIncomeId >= 0) {
        incomeId = newIncomeId;
    }
}
void Income::setIdUser (int newIdUser) {
    if (newIdUser >= 0) {
        idUser = newIdUser;
    }
}
void Income::setDate (string newDate) {
    date = newDate;
}
void Income::setItem (string newItem) {
   item = newItem;
}
void Income::setAmount (float newAmount) {
    amount = newAmount;
}

int Income::getIncomeId() {
    return incomeId;
}
int Income::getIdUser() {
    return idUser;
}
string Income::getDate() {
    return date;
}
string Income::getItem() {
    return item;
}
float Income::getAmount() {
    return amount;
}


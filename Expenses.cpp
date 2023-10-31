#include "Expenses.h"

void Expense::setExpenseId (int newExpenseId) {
    if (newExpenseId >= 0) {
        expenseId = newExpenseId;
    }
}
void Expense::setIdUser (int newIdUser) {
    if (newIdUser >= 0) {
        idUser = newIdUser;
    }
}
void Expense::setDate (string newDate) {
    date = newDate;
}
void Expense::setItem (string newItem) {
   item = newItem;
}
void Expense::setAmount (float newAmount) {
    amount = newAmount;
}

int Expense::getExpenseId() {
    return expenseId;
}
int Expense::getIdUser() {
    return idUser;
}
string Expense::getDate() {
    return date;
}
string Expense::getItem() {
    return item;
}
float Expense::getAmount() {
    return amount;
}




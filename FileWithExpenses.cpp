#include "FileWithExpenses.h"

bool FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "expense" );
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("idUser", expense.getIdUser());
    xml.AddElem("date", expense.getDate() );
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", SupportiveMethods::convertFromFloatToString(expense.getAmount()));
    xml.Save(getFileName());

    idLastExpense++;
    return true;
}

int FileWithExpenses::getIdLastExpense() {
    return idLastExpense;
}

vector <Expense> FileWithExpenses::loadExpensesLoggedUserFile(int idLoggedUser) {
    vector <Expense> expenses;
    Expense expense;

    CMarkup xml;
    if (xml.Load(getFileName())) {
        xml.FindElem("expenses");
        xml.IntoElem();
        while (xml.FindElem("expense")) {
            xml.IntoElem();
            xml.FindElem("expenseId");
            expense.setExpenseId(stoi(xml.GetData()));
            idLastExpense = expense.getExpenseId();
            xml.FindElem("idUser");
            string idUserStr = xml.GetData();
            if (idLoggedUser == stoi(idUserStr)) {
                expense.setIdUser(stoi(idUserStr));
                xml.FindElem("date");
                expense.setDate(xml.GetData());
                xml.FindElem("item");
                expense.setItem(xml.GetData());
                xml.FindElem("amount");
                expense.setAmount(stof(xml.GetData()));
                xml.OutOfElem();
                expenses.push_back(expense);
            } else {
                xml.OutOfElem();
            }
        }
        xml.OutOfElem();

    } else {
        cout << "Nie udalo sie zaladowac pliku" << endl;
    }
    return expenses;
}

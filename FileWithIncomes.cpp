#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income) {
    string amount = "";
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());
    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "income" );
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("idUser", income.getIdUser());
    xml.AddElem("date", income.getDate() );
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", SupportiveMethods::convertFromFloatToString(income.getAmount()));
    xml.Save(getFileName());

    idLastIncome++;
    return true;
}

int FileWithIncomes::getIdLastIncome() {
    return idLastIncome;
}

vector <Income> FileWithIncomes::loadIncomesLoggedUserFile(int idLoggedUser) {
    vector <Income> incomes;
    Income income;

    CMarkup xml;
    if (xml.Load(getFileName())) {
        xml.FindElem("incomes");
        xml.IntoElem();
        while (xml.FindElem("income")) {
            xml.IntoElem();
            xml.FindElem("incomeId");
            income.setIncomeId(stoi(xml.GetData()));
            idLastIncome = income.getIncomeId();
            xml.FindElem("idUser");
            string idUserStr = xml.GetData();
            if (idLoggedUser == stoi(idUserStr)) {
                income.setIdUser(stoi(idUserStr));
                xml.FindElem("date");
                income.setDate(xml.GetData());
                xml.FindElem("item");
                income.setItem(xml.GetData());
                xml.FindElem("amount");
                income.setAmount(stof(xml.GetData()));
                xml.OutOfElem();
                incomes.push_back(income);
            } else {
                xml.OutOfElem();
            }
        }
        xml.OutOfElem();

    } else {
        cout << "Nie udalo sie zaladowac pliku" << endl;
    }
    return incomes;
}

#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Transaction income) {
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
    xml.AddElem("incomeId", income.getTransId());
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

std::vector <Transaction> FileWithIncomes::loadIncomesLoggedUserFile(int idLoggedUser) {
    std::vector <Transaction> incomes;
    Transaction income;

    CMarkup xml;
    if (xml.Load(getFileName())) {
        xml.FindElem("incomes");
        xml.IntoElem();
        while (xml.FindElem("income")) {
            xml.IntoElem();
            xml.FindElem("incomeId");
            income.setTransId(stoi(xml.GetData()));
            idLastIncome = income.getTransId();
            xml.FindElem("idUser");
            std::string idUserStr = xml.GetData();
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
        std::cout << "Nie udalo sie zaladowac pliku" << std::endl;
    }
    return incomes;
}

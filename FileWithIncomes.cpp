#include "FileWithIncomes.h"

void FileWithIncomes::addIncome(Income income) {
    CMarkup xml;

    bool fileExists = xml.Load("incomes.xml");
    if (!fileExists)
    {
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
    xml.AddElem("amount", income.getAmount());
    xml.Save("incomes.xml");
}


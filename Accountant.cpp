#include "Accountant.h"

void Accountant::addNewIncome() {
    Income income;

    system("cls");
    cout << " >>> DODAWANIE PPRZYCHODU <<<" << endl << endl;
    income = enterDataNewIncome();

    incomes.push_back(income);
    cout << (fileWithIncomes.addIncomeToFile(income) ? "Przychod zostal dodany" : "Blad. Nie udalo sie dodac przychodu do pliku" )<< endl;
    system("pause");
}

Income Accountant::enterDataNewIncome() {
    Income income;
    string date = "", amount= "";
    bool valid = false;


    income.setIncomeId(fileWithIncomes.getIdLastIncome() + 1);
    income.setIdUser(ID_LOGGED_USER);

    cout << "Podaj date w formacie RRRR-MM-DD, jesli chcesz wprowadzic aktualna date wpisz 't': ";
    date = SupportiveMethods::readLine();
    if (date == "t") {
        income.setDate(SupportiveMethods::getCurrentDate());
    }  else {
        do {
            if (SupportiveMethods::isValidDate(date)) {
                income.setDate(date);
                valid = true;
            } else {
                cout << "Wprowdzono bledna date, podaj date w formacie RRRR-MM-DD: ";
                date = SupportiveMethods::readLine();
            }
        } while (!valid);
    }

    cout << "Podaj kategorie przychodu: ";
    income.setItem(SupportiveMethods::readLine());

    cout << "Podaj kwote: ";
    income.setAmount(stof(SupportiveMethods::swapCommaToDot(SupportiveMethods::readLine())));

    return income;
}

void Accountant:: printData(Income income) {
    cout << left;
    cout << setw (20) <<  "ID- przychodu: "  << setw (20) <<  income.getIncomeId() << endl;
    cout << setw (20) << "Id - uzytkownika: "  << setw (20) <<  income.getIdUser() << endl;
    cout << "Data "  << setw (15) <<  income.getDate();
    cout << "Kategoria "  << setw (15) <<  income.getItem();
    cout << "Kwota "  <<  setw (15) << income.getAmount() << endl;
}

void Accountant::showUserIncomes() {
    system("cls");
    cout << " >>> BILANS <<<" << endl << endl;

    if (incomes.empty()) {
        cout << endl<< "Brak zapisanych danych" << endl << endl;
        system("pause");
        return;
    }
    for (const Income &income : incomes) {
        printData(income);
    }
    system("pause");
}

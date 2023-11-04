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
void Accountant::addNewExpense() {
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE WYDATKU <<<" << endl << endl;
    expense = enterDataNewExpense();

    expenses.push_back(expense);
    cout << (fileWithExpenses.addExpenseToFile(expense) ? "Wydatek zostal dodany" : "Blad. Nie udalo sie dodac przychodu do pliku") << endl;
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
Expense Accountant::enterDataNewExpense() {
    Expense expense;
    string date = "", amount= "";
    bool valid = false;


    expense.setExpenseId(fileWithExpenses.getIdLastExpense() + 1);
    expense.setIdUser(ID_LOGGED_USER);

    cout << "Podaj date w formacie RRRR-MM-DD, jesli chcesz wprowadzic aktualna date wpisz 't': ";
    date = SupportiveMethods::readLine();
    if (date == "t") {
        expense.setDate(SupportiveMethods::getCurrentDate());
    }  else {
        do {
            if (SupportiveMethods::isValidDate(date)) {
                expense.setDate(date);
                valid = true;
            } else {
                cout << "Wprowdzono bledna date, podaj date w formacie RRRR-MM-DD: ";
                date = SupportiveMethods::readLine();
            }
        } while (!valid);
    }

    cout << "Podaj kategorie wydatku: ";
    expense.setItem(SupportiveMethods::readLine());

    cout << "Podaj kwote: ";
    expense.setAmount(stof(SupportiveMethods::swapCommaToDot(SupportiveMethods::readLine())));

    return expense;
}

void Accountant:: printIncomes(Income income) {
    cout << left;
    cout << "Data: "  << setw (15) <<  income.getDate();
    cout << "Kategoria: "  << setw (15) <<  income.getItem();
    cout << "Kwota: "  <<  setw (15) << income.getAmount() << endl;
}

void Accountant:: printExpenses(Expense expense) {
    cout << left;
    cout << "Data: "  << setw (15) <<  expense.getDate();
    cout << "Kategoria: "  << setw (15) <<  expense.getItem();
    cout << "Kwota: "  <<  setw (15) << expense.getAmount() << endl;
}

void Accountant::showUserIncomes() {
    system("cls");
    cout << " >>> BILANS <<<" << endl << endl;

    if (incomes.empty()) {
        cout << endl<< "Brak zapisanych danych" << endl << endl;
        system("pause");
        return;
    }
    sort(incomes.begin(), incomes.end(), SupportiveMethods::compareIncomeByDate);
    for (const Income &income : incomes) {
        printIncomes(income);
    }
    cout << endl;
    system("pause");
}

void Accountant::displayBalanceForCurrentMonth() {
    year_month_day currentDate =  floor<days>(chrono::system_clock::now());
    displayBalance(currentDate);
}

void Accountant::displayBalanceForPreviousMonth() {
    year_month_day currentDate =  floor<days>(chrono::system_clock::now());
    year_month_day previousMonthDate;

    if (currentDate.month() == date::January) {
        previousMonthDate = year_month_day{currentDate.year() - years{1}, December, currentDate.day()};
    } else {
        previousMonthDate = year_month_day{currentDate.year(), currentDate.month() - months{1}, currentDate.day()};
    }

    displayBalance(previousMonthDate);
}


void Accountant::displayBalance(year_month_day targetDate) {

    float sumIncomes = 0;
    float sumExpenses = 0;


    sort(incomes.begin(), incomes.end(), SupportiveMethods::compareIncomeByDate);
    sort(expenses.begin(), expenses.end(), SupportiveMethods::compareExpenseByDate);


    cout << endl << "---PRZYCHODY---" << endl << endl;
    for (Income item : incomes) {
        istringstream dateStream(item.getDate());
        year_month_day itemDate;
        dateStream >> parse("%Y-%m-%d", itemDate);

        if (itemDate.year() == targetDate.year() && itemDate.month() == targetDate.month()) {
            printIncomes(item);
            sumIncomes+=item.getAmount();
        }
    }
    cout << endl << "---WYDATKI---" << endl << endl;
    for (Expense item : expenses) {
        istringstream dateStream(item.getDate());
        year_month_day itemDate;
        dateStream >> parse("%Y-%m-%d", itemDate);

        if (itemDate.year() == targetDate.year() && itemDate.month() == targetDate.month()) {
            printExpenses(item);
            sumExpenses+=item.getAmount();
        }
    }
    cout << endl << "Suma przychodow: "<< sumIncomes << endl;
    cout << "Suma wydatkow: "<< sumExpenses << endl;
    cout << "Bilans miesiaca: "<< (sumIncomes - sumExpenses) << endl << endl;
    system ("pause");
}


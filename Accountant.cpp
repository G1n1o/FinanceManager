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

    income.setIncomeId(fileWithIncomes.getIdLastIncome() + 1);
    income.setIdUser(ID_LOGGED_USER);

    cout << "Podaj date w formacie RRRR-MM-DD, jesli chcesz wprowadzic aktualna date wpisz 't': ";
    date = SupportiveMethods::readLine();
    if (date == "t") {
        income.setDate(SupportiveMethods::getCurrentDate());
    }  else {
        dateCheck(date);
        income.setDate(date);
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

    expense.setExpenseId(fileWithExpenses.getIdLastExpense() + 1);
    expense.setIdUser(ID_LOGGED_USER);

    cout << "Podaj date w formacie RRRR-MM-DD, jesli chcesz wprowadzic aktualna date wpisz 't': ";
    date = SupportiveMethods::readLine();
    if (date == "t") {
        expense.setDate(SupportiveMethods::getCurrentDate());
    }  else {
        dateCheck(date);
        expense.setDate(date);
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

    system("cls");
    cout << " >>> BILANS <<<" << endl << endl;

    sort(incomes.begin(), incomes.end(), SupportiveMethods::compareIncomeByDate);
    sort(expenses.begin(), expenses.end(), SupportiveMethods::compareExpenseByDate);


    cout << endl << "---PRZYCHODY---" << endl << endl;
    for (Income item : incomes) {
        year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate.year() == targetDate.year() && itemDate.month() == targetDate.month()) {
            printIncomes(item);
            sumIncomes+=item.getAmount();
        }
    }

    cout << endl << "---WYDATKI---" << endl << endl;

    for (Expense item : expenses) {
         year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate.year() == targetDate.year() && itemDate.month() == targetDate.month()) {
            printExpenses(item);
            sumExpenses+=item.getAmount();
        }
    }
       showResult(sumIncomes, sumExpenses);
}

void Accountant::displayBalanceInDateRange () {

    float sumIncomes = 0;
    float sumExpenses = 0;
    string startDateStr, endDateStr;
    year_month_day startDate;
    year_month_day endDate;

    system("cls");
    cout << " >>> BILANS <<<" << endl << endl;

    sort(incomes.begin(), incomes.end(), SupportiveMethods::compareIncomeByDate);
    sort(expenses.begin(), expenses.end(), SupportiveMethods::compareExpenseByDate);

    cout << "Podaj date poczatkowa w formacie RRRR-MM-DD: ";
    startDateStr = SupportiveMethods::readLine();
    dateCheck(startDateStr);
    startDate = SupportiveMethods::convertFromStringToDate(startDateStr);

    cout << "Podaj date koncowa w formacie RRRR-MM-DD: ";

    endDateStr = SupportiveMethods::readLine();
    dateCheck(endDateStr);
    endDate = SupportiveMethods::convertFromStringToDate(endDateStr);

    cout << endl << "---PRZYCHODY---" << endl << endl;

    for (Income item : incomes) {
         year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate >= startDate && itemDate <= endDate) {
            printIncomes(item);
            sumIncomes+=item.getAmount();
        }
    }
     cout << endl << "---WYDATKI---" << endl << endl;

    for (Expense item : expenses) {
        year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate >= startDate && itemDate <= endDate) {
            printExpenses(item);
            sumExpenses+=item.getAmount();
        }
    }

    showResult(sumIncomes, sumExpenses);
}

void Accountant::showResult (float sumIncomes, float sumExpenses) {
    cout << endl << "Suma przychodow: "<< sumIncomes << endl;
    cout << "Suma wydatkow: "<< sumExpenses << endl;
    cout << "Bilans miesiaca: "<< (sumIncomes - sumExpenses) << endl << endl;
    system ("pause");
}

string Accountant::dateCheck(string &date) {
bool valid = false;

do {
        if (SupportiveMethods::isValidDate(date)) {
            valid = true;
        } else {
            cout << "Wprowdzono bledna date, podaj date w formacie RRRR-MM-DD: ";
            date = SupportiveMethods::readLine();
        }
    } while (!valid);

return date;
}


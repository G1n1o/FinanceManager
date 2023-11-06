#include "Accountant.h"

void Accountant::addNewIncome() {
    Transaction income;

    system("cls");
    std::cout << " >>> DODAWANIE PPRZYCHODU <<<" << std::endl << std::endl;
    income = enterDataNewIncome();

    incomes.push_back(income);
    std::cout << (fileWithIncomes.addIncomeToFile(income) ? "Przychod zostal dodany" : "Blad. Nie udalo sie dodac przychodu do pliku" )<< std::endl;
    system("pause");
}
void Accountant::addNewExpense() {
    Transaction expense;

    system("cls");
    std::cout << " >>> DODAWANIE WYDATKU <<<" << std::endl << std::endl;
    expense = enterDataNewExpense();

    expenses.push_back(expense);
    std::cout << (fileWithExpenses.addExpenseToFile(expense) ? "Wydatek zostal dodany" : "Blad. Nie udalo sie dodac przychodu do pliku") << std::endl;
    system("pause");
}

Transaction Accountant::enterDataNewIncome() {
    Transaction income;
    std::string date = "", amount= "";

    income.setTransId(fileWithIncomes.getIdLastIncome() + 1);
    income.setIdUser(ID_LOGGED_USER);

    std::cout << "Podaj date w formacie RRRR-MM-DD, jesli chcesz wprowadzic aktualna date wpisz 't': ";
    date = SupportiveMethods::readLine();
    if (date == "t") {
        income.setDate(SupportiveMethods::getCurrentDate());
    }  else {
        dateCheck(date);
        income.setDate(date);
    }

    std::cout << "Podaj kategorie przychodu: ";
    income.setItem(SupportiveMethods::readLine());

    std::cout << "Podaj kwote: ";
    income.setAmount(stof(SupportiveMethods::swapCommaToDot(SupportiveMethods::readLine())));

    return income;
}
Transaction Accountant::enterDataNewExpense() {
    Transaction expense;
    std::string date = "", amount= "";

    expense.setTransId(fileWithExpenses.getIdLastExpense() + 1);
    expense.setIdUser(ID_LOGGED_USER);

    std::cout << "Podaj date w formacie RRRR-MM-DD, jesli chcesz wprowadzic aktualna date wpisz 't': ";
    date = SupportiveMethods::readLine();
    if (date == "t") {
        expense.setDate(SupportiveMethods::getCurrentDate());
    }  else {
        dateCheck(date);
        expense.setDate(date);
    }

    std::cout << "Podaj kategorie wydatku: ";
    expense.setItem(SupportiveMethods::readLine());

    std::cout << "Podaj kwote: ";
    expense.setAmount(stof(SupportiveMethods::swapCommaToDot(SupportiveMethods::readLine())));

    return expense;
}

void Accountant:: printTransaction(Transaction trans) {
    std::cout << std::left;
    std::cout << "Data: "  << std::setw (15) <<  trans.getDate();
    std::cout << "Kategoria: "  << std::setw (15) <<  trans.getItem();
    std::cout << "Kwota: "  <<  std::setw (15) << trans.getAmount() << std::endl;
}

void Accountant::displayBalanceForCurrentMonth() {
    date::year_month_day currentDate =  date::floor<date::days>(std::chrono::system_clock::now());
    displayBalance(currentDate);
}

void Accountant::displayBalanceForPreviousMonth() {
    date::year_month_day currentDate =  date::floor<date::days>(std::chrono::system_clock::now());
    date::year_month_day previousMonthDate;

    if (currentDate.month() == date::January) {
        previousMonthDate = date::year_month_day{currentDate.year() - date::years{1}, date::December, currentDate.day()};
    } else {
        previousMonthDate = date::year_month_day{currentDate.year(), currentDate.month() - date::months{1}, currentDate.day()};
    }

    displayBalance(previousMonthDate);
}


void Accountant::displayBalance(date::year_month_day targetDate) {

    float sumIncomes = 0;
    float sumExpenses = 0;

    system("cls");
    std::cout << " >>> BILANS <<<" << std::endl << std::endl;

    sort(incomes.begin(), incomes.end(), SupportiveMethods::compareByDate);
    sort(expenses.begin(), expenses.end(), SupportiveMethods::compareByDate);


    std::cout << std::endl << "---PRZYCHODY---" << std::endl << std::endl;
    for (Transaction item : incomes) {
        date::year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate.year() == targetDate.year() && itemDate.month() == targetDate.month()) {
            printTransaction(item);
            sumIncomes+=item.getAmount();
        }
    }

    std::cout << std::endl << "---WYDATKI---" << std::endl << std::endl;

    for (Transaction item : expenses) {
         date::year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate.year() == targetDate.year() && itemDate.month() == targetDate.month()) {
            printTransaction(item);
            sumExpenses+=item.getAmount();
        }
    }
       showResult(sumIncomes, sumExpenses);
}

void Accountant::displayBalanceInDateRange () {

    float sumIncomes = 0;
    float sumExpenses = 0;
    std::string startDateStr, endDateStr;
    date::year_month_day startDate;
    date::year_month_day endDate;

    system("cls");
    std::cout << " >>> BILANS <<<" << std::endl << std::endl;

    sort(incomes.begin(), incomes.end(), SupportiveMethods::compareByDate);
    sort(expenses.begin(), expenses.end(), SupportiveMethods::compareByDate);

    std::cout << "Podaj date poczatkowa w formacie RRRR-MM-DD: ";
    startDateStr = SupportiveMethods::readLine();
    dateCheck(startDateStr);
    startDate = SupportiveMethods::convertFromStringToDate(startDateStr);

    std::cout << "Podaj date koncowa w formacie RRRR-MM-DD: ";

    endDateStr = SupportiveMethods::readLine();
    dateCheck(endDateStr);
    endDate = SupportiveMethods::convertFromStringToDate(endDateStr);

    std::cout << std::endl << "---PRZYCHODY---" << std::endl << std::endl;

    for (Transaction item : incomes) {
         date::year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate >= startDate && itemDate <= endDate) {
            printTransaction(item);
            sumIncomes+=item.getAmount();
        }
    }
     std::cout << std::endl << "---WYDATKI---" << std::endl << std::endl;

    for (Transaction item : expenses) {
        date::year_month_day itemDate = SupportiveMethods::convertFromStringToDate(item.getDate());

        if (itemDate >= startDate && itemDate <= endDate) {
            printTransaction(item);
            sumExpenses+=item.getAmount();
        }
    }

    showResult(sumIncomes, sumExpenses);
}

void Accountant::showResult (float sumIncomes, float sumExpenses) {
    std::cout << std::endl << "Suma przychodow: "<< sumIncomes << std::endl;
    std::cout << "Suma wydatkow: "<< sumExpenses << std::endl;
    std::cout << "Bilans miesiaca: "<< (sumIncomes - sumExpenses) << std::endl << std::endl;
    system ("pause");
}

std::string Accountant::dateCheck(std::string &date) {
bool valid = false;

do {
        if (SupportiveMethods::isValidDate(date)) {
            valid = true;
        } else {
            std::cout << "Wprowdzono bledna date, podaj date w formacie RRRR-MM-DD: ";
            date = SupportiveMethods::readLine();
        }
    } while (!valid);

return date;
}


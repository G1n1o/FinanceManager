#include "SupportiveMethods.h"

string SupportiveMethods::readLine() {
    string input;
    getline(cin, input);
    return input;
}

string SupportiveMethods::convertFromFloatToString(float amount) {
    ostringstream ss;
    ss << amount;
    string str = ss.str();
    return str;
}

string SupportiveMethods::swapFirstLetterForLargeOtherForSmall(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char SupportiveMethods::readSign() {
    string input;
    char sign = {0};

    while (true) {
        input = readLine();
        if (input.length() == 1 ) {
            sign = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie: " << endl;
    }
    return sign;
}

string SupportiveMethods::getCurrentDate() {
    auto currentDate = floor<days>(chrono::system_clock::now());
    return format("%F", currentDate);
}

bool SupportiveMethods::isValidDate(string inputDate) {
    date::year_month_day parsedDate;
    istringstream dateStream(inputDate);

    if (dateStream >> date::parse("%F", parsedDate)) {
        return true;
    } else {
        return false;
    }
}
string SupportiveMethods::swapCommaToDot(string input) {
    for (char& c : input) {
        if (c == ',') {
            c = '.';
        }
    }
    return input;
}


bool SupportiveMethods::compareIncomeByDate(Income a, Income b) {

    istringstream dateStreamA(a.getDate());
    istringstream dateStreamB(b.getDate());
    year_month_day dateA, dateB;
    dateStreamA >> parse("%F", dateA);
    dateStreamB >> parse("%F", dateB);

    return dateA < dateB;
}

bool SupportiveMethods::compareExpenseByDate(Expense a, Expense b) {

    istringstream dateStreamA(a.getDate());
    istringstream dateStreamB(b.getDate());
    year_month_day dateA, dateB;
    dateStreamA >> parse("%F", dateA);
    dateStreamB >> parse("%F", dateB);

    return dateA < dateB;
}

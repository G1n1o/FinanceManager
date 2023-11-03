#include "SupportiveMethods.h"

string SupportiveMethods::readLine() {
    string input;
    getline(cin, input);
    return input;
}


string SupportiveMethods::convertFromIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
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

int SupportiveMethods::convertFromStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
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

int SupportiveMethods::readNumber() {
    string input;
    int number;

    while (true) {
        getline(cin,input);

        stringstream myStream(input);
        if (myStream >> number) {
            break;
        }
        cout << "To nie jest liczba. Wpisz ponownie: " << endl;
    }

    return number;
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


bool SupportiveMethods::compareByDate (Income a, Income b) {

    istringstream dateStreamA(a.getDate());
    istringstream dateStreamB(b.getDate());
    year_month_day dateA, dateB;
    dateStreamA >> parse("%F", dateA);
    dateStreamB >> parse("%F", dateB);

    return dateA < dateB;
}


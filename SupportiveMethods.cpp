#include "SupportiveMethods.h"

std::string SupportiveMethods::readLine() {
    std::string input;
    getline(std::cin, input);
    return input;
}

std::string SupportiveMethods::convertFromFloatToString(float amount) {
    std::stringstream ss;
    ss << amount;
    std::string str = ss.str();
    return str;
}

std::string SupportiveMethods::swapFirstLetterForLargeOtherForSmall(std::string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

char SupportiveMethods::readSign() {
    std::string input;
    char sign = {0};

    while (true) {
        input = readLine();
        if (input.length() == 1 ) {
            sign = input[0];
            break;
        }
        std::cout << "To nie jest pojedynczy znak. Wpisz ponownie: " << std::endl;
    }
    return sign;
}

std::string SupportiveMethods::getCurrentDate() {
    auto currentDate = date::floor<date::days>(std::chrono::system_clock::now());
    return date::format("%F", currentDate);
}

bool SupportiveMethods::isValidDate(std::string inputDate) {
    if (inputDate.length() == 10) {
        date::year_month_day parsedDate;
        std::istringstream dateStream(inputDate);

        if (dateStream >> date::parse("%F", parsedDate)) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

std::string SupportiveMethods::swapCommaToDot(std::string input) {
    for (char& c : input) {
        if (c == ',') {
            c = '.';
        }
    }
    return input;
}


bool SupportiveMethods::compareByDate(Transaction a, Transaction b) {

    std::istringstream dateStreamA(a.getDate());
    std::istringstream dateStreamB(b.getDate());
    date::year_month_day dateA, dateB;
    dateStreamA >> parse("%F", dateA);
    dateStreamB >> parse("%F", dateB);

    return dateA < dateB;
}

date::year_month_day SupportiveMethods::convertFromStringToDate(std::string input) {
    std::istringstream dateStream(input);
    date::year_month_day date;
    dateStream >> parse("%Y-%m-%d", date);
    return date;
}


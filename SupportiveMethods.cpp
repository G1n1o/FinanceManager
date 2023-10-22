#include "SupportiveMethods.h"

string SupportiveMethods::readLine() {
    string input;
    getline(cin, input);
    return input;
}


string SupportiveMethods::convertFromIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string SupportiveMethods::swapFirstLetterForLargeOtherForSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string SupportiveMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}
int SupportiveMethods::convertFromStringToInt(string number)
{
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


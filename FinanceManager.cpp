#include "FinanceManager.h"

void FinanceManager::userRegistration() {
    userManager.userRegistration();
}

void FinanceManager::showAllUsers(){
    userManager.showAllUsers();
}

void FinanceManager::userLogging() {
    userManager.userLogging();
}

void FinanceManager::changePasswordLoggedUser() {
    userManager.changePasswordLoggedUser();
}

bool FinanceManager::isUserLoggedin() {
    return userManager.isUserLoggedIn();
}

char FinanceManager::selectOptionFromGeneralMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();
    return choice;
}

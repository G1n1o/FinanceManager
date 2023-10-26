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
void FinanceManager::userLogout() {
    userManager.userLogout();
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

char FinanceManager::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmieñ has³o" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();
    return choice;
}

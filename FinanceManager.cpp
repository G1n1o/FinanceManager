#include "FinanceManager.h"

void FinanceManager::userRegistration() {
    userManager.userRegistration();
}

void FinanceManager::showAllUsers() {
    userManager.showAllUsers();
}

void FinanceManager::userLogging() {
    userManager.userLogging();
    if (userManager.isUserLoggedIn()) {
        accountant = new Accountant(FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES,userManager.getidLoggedUser());
    }
}

void FinanceManager::changePasswordLoggedUser() {
    if (userManager.isUserLoggedIn()) {
        userManager.changePasswordLoggedUser();
    } else {
        cout << "Aby zmienic haslo, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

bool FinanceManager::isUserLoggedin() {
    return userManager.isUserLoggedIn();
}
void FinanceManager::userLogout() {
    userManager.userLogout();
    delete accountant;
    accountant = NULL;
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
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();
    return choice;
}

void FinanceManager::addNewIncome() {
    if (userManager.isUserLoggedIn()) {
        accountant->addNewIncome();
    } else {
        cout << "Aby dodac przychod, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}
void FinanceManager::addNewExpense() {
    if (userManager.isUserLoggedIn()) {
        accountant->addNewExpense();
    } else {
        cout << "Aby dodac wydatek, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}
void FinanceManager::displayBalanceForCurrentMonth() {
    if (userManager.isUserLoggedIn()) {
        accountant->displayBalanceForCurrentMonth();
    } else {
        cout << "Aby wyswietlic bilans, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void FinanceManager::displayBalanceForPreviousMonth() {
    if (userManager.isUserLoggedIn()) {
        accountant->displayBalanceForPreviousMonth();
    } else {
        cout << "Aby wyswietlic bilans, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void FinanceManager::displayBalanceInDateRange() {
    if (userManager.isUserLoggedIn()) {
        accountant->displayBalanceInDateRange();
    } else {
        cout << "Aby wyswietlic bilans, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}



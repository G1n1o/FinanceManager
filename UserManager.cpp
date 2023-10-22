#include "UserManager.h"

void UserManager::userRegistration() {

    User user = addDataNewUser();

    users.push_back(user);
    fileWithUsersData.saveUserDataInFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}

User UserManager::addDataNewUser() {
    User user;
    user.setIdUser(getNewUserId());

    do {
        cout << "Podaj login: ";
        user.setLogin(SupportiveMethods::readLine());
    } while (loginCheck(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(SupportiveMethods::readLine());
    cout << "Podaj Imie: ";
    user.setName(SupportiveMethods::readLine());
    user.setName(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(user.getName()));
    cout << "Podaj Nazwisko: ";
    user.setSurname(SupportiveMethods::readLine());
    user.setSurname(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(user.getSurname()));

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty())
        return 1;
    else
        return users.back().getIdUser() + 1;
}

bool UserManager::loginCheck(string login) {
    for (size_t i = 0 ; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers() {
    for (size_t i = 0 ; i < users.size(); i++) {
        cout << users[i].getIdUser()<<endl;
        cout << users[i].getLogin()<<endl;
        cout << users[i].getPassword()<<endl;
        cout << users[i].getName()<<endl;
        cout << users[i].getSurname()<<endl;
    }
    system("pause");
}

void UserManager::userLogging() {
    string login = "", password = "";
    cout << endl << "Podaj login: ";
    login = SupportiveMethods::readLine();
    size_t i=0;

    while (i < users.size()) {
        if (users[i].getLogin() == login) {
            for (int quantityTrials = 3; quantityTrials > 0; quantityTrials--) {
                cout << "Podaj haslo. Pozostalo prob: " << quantityTrials << ": ";
                password = SupportiveMethods::readLine();
                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idLoggedUser = users[i].getIdUser();
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return ;
        }
        i++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::changePasswordLoggedUser() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SupportiveMethods::readLine();
    if (isUserLoggedIn()) {
            for (size_t i = 0; i < users.size(); i++ )
              if (users[i].getIdUser() == idLoggedUser) {
                users[i].setPassword(newPassword);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
                fileWithUsersData.saveNewPasswordInFile(newPassword, idLoggedUser);
            }
        } else {
        cout << "Aby zmienic haslo, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

bool UserManager::isUserLoggedIn() {
    return (idLoggedUser > 0) ? true : false;
}

int UserManager::getidLoggedUser() {
    return idLoggedUser;
}

void UserManager::userLogout() {
    idLoggedUser = 0;
}



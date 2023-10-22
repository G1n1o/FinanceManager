#include "FileWithusersData.h"

void FileWithUsersData::saveUserDataInFile(User user) {
    CMarkup xml;

    xml.Load(FILE_WITH_USER_DATA);
    if (xml.FindElem("users")) {
        xml.IntoElem();
    } else {
        xml.AddElem( "users" );
        xml.IntoElem();
    }

    xml.AddElem( "user" );
    xml.IntoElem();
    xml.AddElem("idUser", user.getIdUser());
    xml.AddElem("login", user.getLogin() );
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.OutOfElem();
    xml.OutOfElem();
    xml.Save(FILE_WITH_USER_DATA);
}

vector <User> FileWithUsersData::readUsersFromFile() {
    User user;
    vector <User> users;
    CMarkup xml;

    if (xml.Load(FILE_WITH_USER_DATA)) {
        xml.FindElem("users");
        xml.IntoElem();
        while (xml.FindElem("user")) {
            xml.IntoElem();
            xml.FindElem("idUser");
            string idUserStr = xml.GetData();
            user.setIdUser(stoi(idUserStr));
            xml.FindElem("login");
            user.setLogin(xml.GetData());
            xml.FindElem("password");
            user.setPassword(xml.GetData());
            xml.FindElem("name");
            user.setName(xml.GetData());
            xml.FindElem("surname");
            user.setSurname(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
        xml.OutOfElem();
    } else {
        cout << "Nie udalo sie zaladowac pliku" << endl;
    }
    return users;
}

void FileWithUsersData::saveNewPasswordInFile(string password, int idLoggedUser) {

    CMarkup xml;
    if (xml.Load(FILE_WITH_USER_DATA)) {
        if (xml.FindElem("users")) {
            xml.IntoElem();
            while (xml.FindElem("user")) {
                xml.IntoElem();
                xml.FindElem("idUser");
                string idUserStr = xml.GetData();
                int idUser = stoi(idUserStr);
                if (idUser == idLoggedUser) {
                    xml.FindElem("password");
                    xml.SetData(password);
                }
                xml.OutOfElem();
            }
            xml.Save(FILE_WITH_USER_DATA);

        } else {
            cout << "Nie znaleziono elementu <users> w pliku XML." << endl;
        }
    } else {
        cout << "Nie udalo sie zaladowac pliku XML." << endl;
    }
}

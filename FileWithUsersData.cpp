#include "FileWithusersData.h"

void FileWithUsersData::saveUserDataInFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load(getFileName());
    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem( "user" );
    xml.IntoElem();
    xml.AddElem("idUser", user.getIdUser());
    xml.AddElem("login", user.getLogin() );
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.Save(getFileName());
}

std::vector <User> FileWithUsersData::readUsersFromFile() {
    User user;
    std::vector <User> users;
    CMarkup xml;

    if (xml.Load(getFileName())) {
        xml.FindElem("users");
        xml.IntoElem();
        while (xml.FindElem("user")) {
            xml.IntoElem();
            xml.FindElem("idUser");
            std::string idUserStr = xml.GetData();
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
        std::cout << "Nie udalo sie zaladowac pliku" << std::endl;
    }
    return users;
}

void FileWithUsersData::saveNewPasswordInFile(std::string password, int idLoggedUser) {

    CMarkup xml;
    if (xml.Load(getFileName())) {
        if (xml.FindElem("users")) {
            xml.IntoElem();
            while (xml.FindElem("user")) {
                xml.IntoElem();
                xml.FindElem("idUser");
                std::string idUserStr = xml.GetData();
                int idUser = stoi(idUserStr);
                if (idUser == idLoggedUser) {
                    xml.FindElem("password");
                    xml.SetData(password);
                }
                xml.OutOfElem();
            }
            xml.Save(getFileName());

        } else {
            std::cout << "Nie znaleziono elementu <users> w pliku XML." << std::endl;
        }
    } else {
        std::cout << "Nie udalo sie zaladowac pliku XML." << std::endl;
    }
}

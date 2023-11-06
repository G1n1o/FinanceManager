#ifndef USER_H
#define USER_H

#include <iostream>

class User {
int idUser;
std::string login;
std::string password;
std::string name;
std::string surname;

public:
    void setIdUser (int newIdUser);
    void setLogin (std::string newLogin);
    void setPassword (std::string newPassword);
    void setName (std::string newName);
    void setSurname (std::string newSurname);

    int getIdUser();
    std::string getLogin();
    std::string getPassword();
    std::string getName();
    std::string getSurname();
};

#endif

#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
int idUser;
string login;
string password;
string name;
string surname;

public:
    void setIdUser (int newIdUser);
    void setLogin (string newLogin);
    void setPassword (string newPassword);
    void setName (string newName);
    void setSurname (string newSurname);

    int getIdUser();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif

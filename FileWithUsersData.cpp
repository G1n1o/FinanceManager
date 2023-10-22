#include "FileWithusersData.h"

void FileWithUsersData::saveUserDataInFile(User user) {
    CMarkup Users;

    Users.Load("users.xml");
    if (Users.FindElem("users")){
    Users.IntoElem();
    } else {
    Users.AddElem( "users" );
    Users.IntoElem();
    }

    Users.AddElem( "user" );
    Users.IntoElem();
    Users.AddElem("idUser", user.getIdUser());
    Users.AddElem("login", user.getLogin() );
    Users.AddElem("password", user.getPassword());
    Users.AddElem("name", user.getName());
    Users.AddElem("surname", user.getSurname());
    Users.OutOfElem();
    Users.OutOfElem();
    Users.Save("users.xml");
    }

string FileWithUsersData::replaceUserDataOnDataLineSeparatedVerticalDashes(User user) {
    string lineWithUserData = "";
    lineWithUserData += SupportiveMethods::convertFromIntToString(user.getIdUser())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';
    return lineWithUserData;
}

vector <User> FileWithUsersData::readUsersFromFile() {
    User user;
    vector <User> users;
    fstream textFile;
    string singleUserDataSeparatedbyVerticalDashes = "";

    textFile.open(FILE_WITH_USER_DATA.c_str(), ios::in);

    if (textFile.good()) {
        while (getline(textFile, singleUserDataSeparatedbyVerticalDashes)) {
            user = readUserData(singleUserDataSeparatedbyVerticalDashes);
            users.push_back(user);
        }
    }
    textFile.close();
    return users;
}

User FileWithUsersData::readUserData(string singleUserDataSeparatedbyVerticalDashes) {
    User user;
    string singleUserData = "";
    int numberSingleDataUser = 1;

    for (size_t itemSign = 0; itemSign < singleUserDataSeparatedbyVerticalDashes.length(); itemSign++) {
        if (singleUserDataSeparatedbyVerticalDashes[itemSign] != '|') {
            singleUserData += singleUserDataSeparatedbyVerticalDashes[itemSign];
        } else {
            switch(numberSingleDataUser) {
            case 1: user.setIdUser(atoi(singleUserData.c_str())); break;
            case 2: user.setLogin(singleUserData); break;
            case 3: user.setPassword(singleUserData); break;
            }
            singleUserData = "";
            numberSingleDataUser++;
        }
    }
    return user;
}

void FileWithUsersData::saveAllUsersDataInFile(vector <User> &users) {
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(FILE_WITH_USER_DATA.c_str(), ios::out);

    if (textFile.good()) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            lineWithUserData = replaceUserDataOnDataLineSeparatedVerticalDashes(*itr);

            if (itr == itrEnd) {
                textFile << lineWithUserData;
            } else {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << FILE_WITH_USER_DATA << endl;
    }
    textFile.close();
}

bool FileWithUsersData::isFileEmpty(fstream &textFile) {
    textFile.seekg(0, ios::end);
    return  (textFile.tellg() == 0) ? true : false;
}


#include "User.h"

User::User()
{
    login = "user";
    password = "user";
    age = 18;
    sex = 'M';
    phone = "1234567";
    email = "example@mail.com";
}

User::User(string login, string password, int age, char sex, string phone, string email)
{
    this->login = login;
    this->password = password;
    this->age = age;
    this->sex = sex;
    this->phone = phone;
    this->email = email;
}

string User::getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}

int User::getAge()
{
    return age;
}

char User::getSex()
{
    return sex;
}

string User::getPhone()
{
    return phone;
}

string User::getEmail()
{
    return email;
}

ostream& operator<<(ostream& out, User& obj)
{
   return out << setw(12) << obj.login << setw(12) << obj.password << setw(10) << obj.age << setw(5) << obj.sex << setw(18) << obj.phone << setw(22) << obj.email << "\n";
}

istream& operator>>(istream& in, User& obj)
{
    return in >> obj.login >> obj.password >> obj.age >> obj.sex >> obj.phone >> obj.email;
}
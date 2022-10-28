#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Account
{
    string _strUser;
    string _strPin;
public:
    friend ifstream& operator >> (ifstream& is, Account& a);


    bool operator == (const Account& a);

    void setUser();
    string getUser();

    string getPin();
    void setPin(string pin);
};


#include "Account.h"

 ifstream& operator >> (ifstream& is, Account& a) {
    is >> a._strUser >> a._strPin;
    return is;
}
 bool Account::operator == ( const Account& a) {
     return this->_strUser == a._strUser && this->_strPin == a._strPin;
 }

 void Account::setUser()
 {
     cin >> _strUser;
 }
 string Account::getUser()
 {
     return _strUser;
 }

 string Account::getPin()
 {
     return _strPin;
 }
 void Account::setPin(string pin)
 {
     _strPin = pin;
 }
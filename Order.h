#pragma once

#include "Item.h"

class Order

{
    static int  _SERI ;
    int _iSeri = 1 ;
    int _iPrice = 0;
    string _strCustomerName;
    string _strCustomerAdress;
    string _strCustomerPhone;
    string _strDay;
public:
    vector<string> szCodeItems;
    vector<int> szProducts;

    int getCode();
    int getPrice();
    string getCustomer();
    string getCustomerAdress();
    string getPhone();
    string getDay();



    friend istream& operator >> (istream& is, Order& o);

};



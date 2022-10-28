#pragma once

#include "Item.h"

class Order

{
    static int  _SERI;
    int _iMa = 1;
    int _iGiaTien = 0;
    string _strTen;
    string _strDiaChi;
    string _strSDT;
    string _strNgay;
public:
    vector<string> SizeMaCode;
    vector<int> SizeSanPham;

    int getMa();
    int getGiaTien();
    string getTen();
    string getDiaChi();
    string getSDT();
    string getNgay();



    friend istream& operator >> (istream& is, Order& order);

};



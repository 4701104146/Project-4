#pragma once
#include"Source.cpp"
class Item
{
    string maCode = "";
    string tenSanPham = "";
    string _xuatSu = "";
    string _mauSP = "";
    int giaCaSP = 0;
    string dateInSP = "";
    int soLuongSP = 0;


public:
    friend ifstream& operator >> (ifstream& in, Item& n);
    friend ofstream& operator << (ofstream& out, Item& n);
    friend ostream& operator << (ostream& out, const Item& n);
    friend istream& operator >> (istream& in, Item& i);


    string GetMa();
    int laySoLuong();
    string getName();
    void update(int products);
    void setCode(const string& code);
    string nhapNoiXS();
    string mauSP();
    string getDay();
    int giaSP();
    int soLuong();
};

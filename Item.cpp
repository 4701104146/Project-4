#include "Item.h"

ifstream& operator >> (ifstream& is, Item& h)

{
    //is.seekg(0, ios::beg);
    string strLine = "";
    getline(is, strLine);

    size_t i = 0;
    for (; strLine[i] != '~'; i++)
        h._strCode += strLine[i];
    i++;
    
    for (; strLine[i] != '~'; ++i)
        h._strName += strLine[i];
    ++i;

    for (; strLine[i] != '~'; i++)
        h._strProductionPlace += strLine[i];
    ++i;

    for (; strLine[i] != '~'; i++)
        h._strColor += strLine[i];    
    ++i;

    string strPrice = "";
    for (; strLine[i] != '~'; i++)
        strPrice += strLine[i];
    ++i;

    h._iPrice = stoi(strPrice);

    for (; strLine[i] != '~'; i++)
        h._strDayIn += strLine[i];
    ++i;

    string strNumber = "";
    for (; i < strLine.size(); i++)
        strNumber += strLine[i];
    h._iProducts = stoi(strNumber);
    return is;
}
ofstream& operator << (ofstream& os,  Item& h)
{
    os  << h.getCode() << '~' << h.getName() << '~' << h.getProductionPlace() << '~' << h.getColor()
        << '~' << h.getPrice() << '~' << h.getDay() << '~' << h.getProduct() ;
    return os;
}

ostream& operator << (ostream& os, const Item& h)
{
    SPACE(NUB - WIDTH); VER(WIDTH);
    os << setw(SP1) << h._strCode; VER(WIDTH);
    os<< setw(SP3) << h._strName; VER(WIDTH);
    os<< setw(SP2) << h._strProductionPlace; VER(WIDTH);
    os<<setw(SP1) << h._strColor; VER(WIDTH);
    os<< setw(SP1) << h._iPrice; VER(WIDTH);
    os<< setw(SP2) << h._strDayIn; VER(WIDTH);
    os << setw(SP1) << h._iProducts; VER(WIDTH);
   

    NEWLINE(1);
    SPACE(NUB - WIDTH);
    VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP3); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH);
    NEWLINE(1);
    return os;
}
istream& operator >> (istream& is, Item& i)
{
    SPACE(NUB2); cout << "Ten mat hang: ";
    getline(is, i._strName);
    SPACE(NUB2); cout << "Noi san xuat: ";
    getline(is , i._strProductionPlace);
    SPACE(NUB2); cout << "Mau sac: ";
    getline(is , i._strColor);
    SPACE(NUB2); cout << "Gia ca: ";
    is >> i._iPrice;
    SPACE(NUB2); cout << "Ngay nhap hang: ";
    is >> i._strDayIn;
    SPACE(NUB2); cout << "So luong: ";
    is >> i._iProducts;
    return is;
}


string Item::getCode()
{
    return _strCode;
}
int Item::getNumber()
{
    return _iProducts;
}
string Item::getName()
{
    return _strName;
}
void Item::update(int products)
{
    _iProducts += products;
}
void Item::setCode(const string& code)
{
    _strCode = code;
}
string Item::getProductionPlace()
{
    return _strProductionPlace;
}
string Item::getColor()
{
    return _strColor;
}
string Item::getDay()
{
    return _strDayIn;
}
int Item::getPrice()
{
    return _iPrice;
}
int Item::getProduct()
{
    return _iProducts;
}


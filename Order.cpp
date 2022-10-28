#include "Order.h"
using namespace std;
int Order::_SERI = 0;

istream& operator >> (istream& is, Order& order)
{
    //NEWLINE(TOP);
    SPACE(NUB2);
    cout << "Ten khach hang:             "; getline(is, order._strCustomerName);
    SPACE(NUB2);
    cout << "Dia chi khach hang:         "; getline(is, order._strCustomerAdress);
    SPACE(NUB2);
    cout << "So dien thoai:              "; is >> order._strCustomerPhone;
    SPACE(NUB2);
    cout << "Ngay dat hang:              "; is >> order._strDay;
    SPACE(NUB2);
    cout << "Nhap so loai san pham mua:  ";
    int iNumbers;
    cin >> iNumbers;
    //i = iNub;
    NEWLINE(2);
    SPACE(NUB); cout << "***Nhap ma tung san pham***\n\n";

    string strCode;
    {
        int i = 0;
        int iProducts;
        while (i < iNumbers)
        {
            std::cin.ignore(256, '\n');

            SPACE(NUB + NUB); cout << "Ma san pham thu " << i + 1 << ": ";
            is >> strCode;
            order.sizeCodeItems.push_back(strCode);
            SPACE(NUB * 2); cout << "So luong san pham dat mua: ";
            is >> iProducts;
            order.sizeProducts.push_back(iProducts);
            i++;
        }
    }
    order._iSeri = Order::_SERI;
    std::cin.ignore(256, '\n');

    return is;

}

int Order::getCode()
{
    return _iSeri;
}
int Order::getPrice()
{
    return _iPrice;
}
string Order::getCustomer()
{
    return _strCustomerName;
}
string Order::getCustomerAdress()
{
    return _strCustomerAdress;
}
string Order::getPhone()
{
    return _strCustomerPhone;
}
string Order::getDay()
{
    return _strDay;
}
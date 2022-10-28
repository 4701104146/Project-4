#include "Order.h"
using namespace std;
int Order::_SERI = 0;

istream& operator >> (istream& is, Order& order)
{
    //NEWLINE(TOP);
    SPACE(NUB2);
    cout << "Ten khach hang:             "; getline(is, order._strTen);
    SPACE(NUB2);
    cout << "Dia chi khach hang:         "; getline(is, order._strDiaChi);
    SPACE(NUB2);
    cout << "So dien thoai:              "; is >> order._strSDT;
    SPACE(NUB2);
    cout << "Ngay dat hang:              "; is >> order._strNgay;
    SPACE(NUB2);
    cout << "Nhap so loai san pham mua:  ";
    int SLSanPham;
    cin >> SLSanPham;
    //i = iNub;
    NEWLINE(2);
    SPACE(NUB); cout << "***Nhap ma tung san pham***\n\n";

    string strCode;
    {
        int i = 0;
        int SanPham;
        while (i < SLSanPham)
        {
            std::cin.ignore(256, '\n');

            SPACE(NUB + NUB); cout << "Ma san pham thu " << i + 1 << ": ";
            is >> strCode;
            order.SizeMaCode.push_back(strCode);
            SPACE(NUB * 2); cout << "So luong san pham dat mua: ";
            is >> SanPham;
            order.SizeSanPham.push_back(SanPham);
            i++;
        }
    }
    order._iMa = Order::_SERI;
    std::cin.ignore(256, '\n');

    return is;

}

int Order::getMa()
{
    return _iMa;
}
int Order::getGiaTien()
{
    return _iGiaTien;
}
string Order::getTen()
{
    return _strTen;
}
string Order::getDiaChi()
{
    return _strDiaChi;
}
string Order::getSDT()
{
    return _strSDT;
}
string Order::getNgay()
{
    return _strNgay;
}

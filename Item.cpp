#include "Item.h"
ifstream& operator >> (ifstream& in, Item& n)
{
    string  thanhPhan = "";
    getline(in, thanhPhan);
    size_t i = 0;
    for (; thanhPhan[i] != '~'; i++)
        n.maCode += thanhPhan[i];
    i++;
    for (; thanhPhan[i] != '~'; ++i)
        n.tenSanPham += thanhPhan[i];
    ++i;
    for (; thanhPhan[i] != '~'; i++)
        n._xuatSu += thanhPhan[i];
    ++i;
    for (; thanhPhan[i] != '~'; i++)
        n._mauSP += thanhPhan[i];
    ++i;
    string thanhGia = "";
    for (; thanhPhan[i] != '~'; i++)
        thanhGia += thanhPhan[i];
    ++i;
    n.giaCaSP = stoi(thanhGia);
    for (; thanhPhan[i] != '~'; i++)
        n.dateInSP += thanhPhan[i];
    ++i;
    string sLTonKho = "";
    for (; i < thanhPhan.size(); i++)
        sLTonKho += thanhPhan[i];
    n.soLuongSP = stoi(sLTonKho);
    return in;
}
ofstream& operator << (ofstream& out, Item& n)
{
    out << n.GetMa() << '~' << n.getName() << '~' << n.nhapNoiXS() << '~' << n.mauSP()
        << '~' << n.giaSP() << '~' << n.getDay() << '~' << n.soLuong();
    return out;
}

ostream& operator << (ostream& out, const Item& n)
{
    SPACE(NUB - WIDTH); VER(WIDTH);
    out << setw(SP1) << n.maCode; VER(WIDTH);
    out << setw(SP3) << n.tenSanPham; VER(WIDTH);
    out << setw(SP2) << n._xuatSu; VER(WIDTH);
    out << setw(SP1) << n._mauSP; VER(WIDTH);
    out << setw(SP1) << n.giaCaSP; VER(WIDTH);
    out << setw(SP2) << n.dateInSP; VER(WIDTH);
    out << setw(SP1) << n.soLuongSP; VER(WIDTH);
    NEWLINE(1);
    SPACE(NUB - WIDTH);
    VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP3); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH);
    NEWLINE(1);
    return out;
}
istream& operator >> (istream& in, Item& i)
{
    SPACE(NUB2); cout << "Ten mat hang: ";
    getline(in, i.tenSanPham);
    SPACE(NUB2); cout << "Noi san xuat: ";
    getline(in, i._xuatSu);
    SPACE(NUB2); cout << "Mau sac: ";
    getline(in, i._mauSP);
    SPACE(NUB2); cout << "Gia ca: ";
    in >> i.giaCaSP;
    SPACE(NUB2); cout << "Ngay nhap hang: ";
    in >> i.dateInSP;
    SPACE(NUB2); cout << "So luong: ";
    in >> i.soLuongSP;
    return in;
}


string Item::GetMa()
{
    return maCode;
}
int Item::laySoLuong()
{
    return soLuongSP;
}
string Item::getName()
{
    return tenSanPham;
}
void Item::update(int products)
{
    soLuongSP += products;
}
void Item::setCode(const string& code)
{
    maCode = code;
}
string Item::nhapNoiXS()
{
    return _xuatSu;
}
string Item::mauSP()
{
    return _mauSP;
}
string Item::getDay()
{
    return dateInSP;
}
int Item::giaSP()
{
    return giaCaSP;
}
int Item::soLuong()
{
    return soLuongSP;
}

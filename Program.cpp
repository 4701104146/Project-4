#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>
#include <Windows.h>
#include <conio.h>

using namespace std;


class Account
{
    string TaiKhoan;
    string MatKhau;
public:
    friend ifstream& operator >> (ifstream& in, Account& t);


    bool operator == (const Account& t);

    void setTK();
    string getTK();

    string getMK();
    void setMK(string MK);
};
ifstream& operator >> (ifstream& in, Account& t) {
    in >> t.TaiKhoan >> t.MatKhau;
    return in;
}
bool Account::operator == (const Account& t) {
    return this->TaiKhoan == t.TaiKhoan && this->MatKhau == t.MatKhau;
}

void Account::setTK()
{
    cin >> TaiKhoan;
}
string Account::getTK()
{
    return TaiKhoan;
}

string Account::getMK()
{
    return MatKhau;
}
void Account::setMK(string MK)
{
    MatKhau = MK;
}

#define NUB 20
#define NUB2 NUB * 2
#define SPACE(i) for (int j = 0; j < i ; j++,(cout << ' '))
#define NEWLINE(i) for (int j = 0; j < i ; j++,(cout << '\n'))

#define WIDTH 1
#define TOP 5
#define BOTTOM 3
#define VER(i) for (int j = 0 ; j < i ; j++,(cout << '|'))
#define HOR(i) for (int j = 0; j < i ; j++,(cout << '_'))
#define SP1 13
#define SP2 23
#define SP3 33


class Item
{
    string _strCode = "";
    string _strName = "";
    string _strProductionPlace = "";
    string _strColor = "";
    int _iPrice = 0;
    string _strDayIn = "";
    int _iProducts = 0;


public:
    friend ifstream& operator >> (ifstream& is, Item& h);
    friend ofstream& operator << (ofstream& os, Item& h);
    friend ostream& operator << (ostream& os, const Item& h);
    friend istream& operator >> (istream& is, Item& i);


    string getCode();
    int getNumber();
    string getName();
    void update(int products);
    void setCode(const string& code);
    string getProductionPlace();
    string getColor();
    string getDay();
    int getPrice();
    int getProduct();
};
ifstream& operator >> (ifstream& is, Item& h)
{
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
ofstream& operator << (ofstream& os, Item& h)
{
    os << h.getCode() << '~' << h.getName() << '~' << h.getProductionPlace() << '~' << h.getColor()
        << '~' << h.getPrice() << '~' << h.getDay() << '~' << h.getProduct();
    return os;
}

ostream& operator << (ostream& os, const Item& h)
{
    SPACE(NUB - WIDTH); VER(WIDTH);
    os << setw(SP1) << h._strCode; VER(WIDTH);
    os << setw(SP3) << h._strName; VER(WIDTH);
    os << setw(SP2) << h._strProductionPlace; VER(WIDTH);
    os << setw(SP1) << h._strColor; VER(WIDTH);
    os << setw(SP1) << h._iPrice; VER(WIDTH);
    os << setw(SP2) << h._strDayIn; VER(WIDTH);
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
    getline(is, i._strProductionPlace);
    SPACE(NUB2); cout << "Mau sac: ";
    getline(is, i._strColor);
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
class Order

{
    static int  _SERI;
    int _iSeri = 1;
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
int Order::_SERI = 0;

istream& operator >> (istream& is, Order& o)
{
    SPACE(NUB2);
    cout << "Ten khach hang:             "; getline(is, o._strCustomerName);
    SPACE(NUB2);
    cout << "Dia chi khach hang:         "; getline(is, o._strCustomerAdress);
    SPACE(NUB2);
    cout << "So dien thoai:              "; is >> o._strCustomerPhone;
    SPACE(NUB2);
    cout << "Ngay dat hang:              "; is >> o._strDay;
    SPACE(NUB2);
    cout << "Nhap so loai san pham mua:  ";
    int iNumbers;
    cin >> iNumbers;
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
            o.szCodeItems.push_back(strCode);
            SPACE(NUB * 2); cout << "So luong san pham dat mua: ";
            is >> iProducts;
            o.szProducts.push_back(iProducts);
            i++;
        }
    }
    o._iSeri = Order::_SERI;
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
enum class eColor;
void GoTo(SHORT posX, SHORT posY);
void SetColor(eColor highlight_color, eColor text_color);

namespace filePath {
    // File admin phải tự tạo từ trước bởi cá nhân và điền thông tin vào.
    const string g_FileAdmin = "D:\\admin.txt";

    // File hàng hóa tương tự file admin.
    // Thông tin trong file phải điền theo thứ tự

    //        (Mã hàng)~(Tên Hàng)~(Nơi sản xuất)~(Mau sắc)~(Giá cả)~(NgayNhapKho)~(Số lượng)


    const string g_FileHangHoa = "D:\\HangHoa.txt";

    // File đơn hàng sẽ được tự tạo bởi chương trình.
    const string g_FileDonHang = "D:\\DonHang.txt";
}

class Program
{
    // key_press nhận nút điều khiển từ chương trình.
    char _cKeyPress = 0;
    int stt = 1;
    // mảng các tài khoản admin, đơn hàng, hàng hóa,
    vector<Account> szAdmin;
    vector<Item> szItems;
    queue<Order> szOrders;


public:
    // hàm lấy tài khoản và hàng hóa.
    void loadAdmins();
    void loadItems();
    //_____________________________

    void run();
    void menu();

    // menu
    void display();
    void search();
    void order();
    void manage();

    // quanLy//
    void menuManage();
    void loadingOrder();
    void manageItem();


    // quan ly hang hoa//
    void addItem();
    void removeItem();
    void updateItem();

    //______________________



    // ham bo tro
    bool orderSuccess(Order& o);
    int login();

    // update Item có mã (code)
    void updateItem(const string& code, int product);
    bool foundItem(const string& code);


    void writeToFile(Order& o, const string& path, bool state);
    void uploadFile(const string& path);

    // hàm kiểm tra xem số sản phẩm (products) truyền vô có lớn hơn số sản phẩm tối đa của sản phẩm có mã là (code) không
    bool greaterMaxProducts(const string& code, int products);
};
#define ESC 27
#define ENTER 13
#define BACKSPACE 8
using namespace filePath;

enum class eColor
{
    BLACK,
    BLUE,
    GREEN,
    AQUA,
    RED,
    PURPLE,
    YELLOW,
    WHITE,
    GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_AQUA,
    LIGHT_RED,
    LIGHT_PURPLE,
    LIGHT_YELLOW,
    BRIGHT_WHITE,
};

void Program::loadAdmins()
{
    Account t;
    ifstream f(g_FileAdmin);
    while (!f.eof())
    {
        f >> t;
        szAdmin.push_back(t);
    }
    f.close();
}
void Program::loadItems()
{
    ifstream f(g_FileHangHoa);
    while (!f.eof())
    {
        Item i;
        f >> i;
        szItems.push_back(i);
    }
    f.close();

}
void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;

    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

int main()
{
    SetWindowSize(50, 80);

    Program program;
    program.loadAdmins();
    program.loadItems();
    program.run();
}

// Di chuyển con trỏ văn bản trên console
void GoTo(SHORT posX, SHORT posY)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;

    SetConsoleCursorPosition(hStdout, Position);
}

void SetColor(eColor hglt_color, eColor txt_color)
{
    auto highlight_color = (int)hglt_color; // auto tu dong nhan kieu du lieu
    auto text_color = (int)txt_color;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    auto color_code = highlight_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}


void Program::run()
{
    menu();
}
void Program::menu()
{
    system("cls");

    SetColor(eColor::BLACK, eColor::LIGHT_AQUA);
    NEWLINE(TOP);
    SPACE(NUB2); cout << "*************************************************" << '\n';
    SPACE(NUB2); cout << "***";
    SetColor(eColor::BLACK, eColor::LIGHT_GREEN);
    cout << "                   Menu                    ";
    SetColor(eColor::BLACK, eColor::LIGHT_AQUA);
    cout << "***" << '\n';
    SPACE(NUB2); cout << "*************************************************" << '\n';
    SetColor(eColor::BLACK, eColor::BRIGHT_WHITE);
    SPACE(NUB2); cout << "1. Hien thi thong tin hang hoa." << '\n';
    SPACE(NUB2); cout << "2. Tim kiem thong tin hang hoa." << '\n';
    SPACE(NUB2); cout << "3. Dat hang." << '\n';
    SPACE(NUB2); cout << "4. Quan ly." << '\n';


    NEWLINE(BOTTOM);
    SPACE(NUB2); cout << "An \"ESC\" de thoat." << '\n';


    while (_cKeyPress = _getch())
    {
        switch (_cKeyPress)
        {
        case '1':
            display();
            exit(0);
        case '2':
            search();
            exit(0);
        case '3':
            order();
            exit(0);
        case '4':
            manage();
            exit(0);
        case ESC: exit(0);
        default:
            SPACE(NUB2); cout << "Du lieu khong hop le, tu dong thoat!";
            exit(0);
        }
        
    }

}

// menu
void Program::display()
{
    system("cls");

    cout << left;
    SPACE(NUB - WIDTH);
    HOR(WIDTH + SP1 + WIDTH + SP3 + WIDTH + SP2 + WIDTH + SP1 + WIDTH + SP1 + WIDTH + SP2 + WIDTH + SP1 + WIDTH);
    NEWLINE(1);
    SPACE(NUB - WIDTH);                     VER(WIDTH);
    cout << setw(SP1) << "Ma hang";         VER(WIDTH);
    cout << setw(SP3) << "Ten hang";        VER(WIDTH);
    cout << setw(SP2) << "Noi san xuat";    VER(WIDTH);
    cout << setw(SP1) << "Mau sac";         VER(WIDTH);
    cout << setw(SP1) << "Gia ban";         VER(WIDTH);
    cout << setw(SP2) << "Ngay nhap kho";   VER(WIDTH);
    cout << setw(SP1) << "So luong";        VER(WIDTH);
    NEWLINE(1);
    SPACE(NUB - WIDTH);
    VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP3); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH);
    NEWLINE(1);

    cout << left;
    for (size_t i = 0; i < szItems.size(); i++)
        cout << szItems[i];


    NEWLINE(3);
    SPACE(NUB2); cout << "An \"ESC\" de thoat \"p\" de quay lai.";
    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if (_cKeyPress == 'p')
            menu();
    }

}
void Program::search()
{
    system("cls");

    NEWLINE(TOP);
    string strName = "";
    SPACE(NUB); cout << "Nhap ten san pham muon tim: ";
    getline(cin, strName);
    NEWLINE(BOTTOM);

    cout << left;
    SPACE(NUB - WIDTH);
    int check = 0;
    for (size_t i = 0; i < szItems.size(); i++)
        if (szItems[i].getName() == strName)
        {
            check++;
        }
    if (check != 0) {
        HOR(WIDTH + SP1 + WIDTH + SP3 + WIDTH + SP2 + WIDTH + SP1 + WIDTH + SP1 + WIDTH + SP2 + WIDTH + SP1 + WIDTH);
        NEWLINE(1);
        SPACE(NUB - WIDTH);                     VER(WIDTH);
        cout << setw(SP1) << "Ma hang";         VER(WIDTH);
        cout << setw(SP3) << "Ten hang";        VER(WIDTH);
        cout << setw(SP2) << "Noi san xuat";    VER(WIDTH);
        cout << setw(SP1) << "Mau sac";         VER(WIDTH);
        cout << setw(SP1) << "Gia ban";         VER(WIDTH);
        cout << setw(SP2) << "Ngay nhap kho";   VER(WIDTH);
        cout << setw(SP1) << "So luong";        VER(WIDTH);
        NEWLINE(1);
        SPACE(NUB - WIDTH);
        VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP3); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH);
        NEWLINE(1);


        for (size_t i = 0; i < szItems.size(); i++)
            if (szItems[i].getName() == strName)
            {
                cout << szItems[i];
            }



        NEWLINE(3);
    }
    else {
        cout << "\t\t\t\t\t\t\tKhong tim thay hang      " << endl;
        NEWLINE(1);
    }
    SPACE(NUB); cout << "An \"ESC\" de thoat \"p\" de quay lai \"Enter\" de tiep tuc.";

    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if (_cKeyPress == 'p')
            menu();
        else if (_cKeyPress == ENTER)
            search();
    }
}
void Program::order()
{
    system("cls");

    NEWLINE(TOP);
    Order o;

    cin >> o;
    NEWLINE(3);

    if (orderSuccess(o))
    {
        NEWLINE(5);
        SPACE(NUB2); cout << "Don hang dang cho xu ly.";
        szOrders.push(o);
    }
    else
    {
        SPACE(NUB2); cout << "Don hang THAT BAI, mot so san pham khong co san vui long ghe lai sau!";
    }

    NEWLINE(3);
    SPACE(NUB2); cout << "An \"ESC\" de thoat \"p\" de quay lai ENTER de tiep tuc.";

    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if (_cKeyPress == 'p')
            menu();
        else if (_cKeyPress == ENTER)
            order();
    }
}
void Program::manage()
{
    system("cls");
    NEWLINE(TOP);
    SetColor(eColor::BLACK, eColor::LIGHT_AQUA);
    SPACE(NUB2); cout << "*************************************************" << '\n';
    SPACE(NUB2); cout << "***";
    SetColor(eColor::BLACK, eColor::LIGHT_GREEN);
    cout << "             DANG NHAP HE THONG            ";
    SetColor(eColor::BLACK, eColor::LIGHT_AQUA);
    cout << "***" << '\n';
    SPACE(NUB2); cout << "*************************************************" << '\n';
    NEWLINE(BOTTOM);
    SetColor(eColor::BLACK, eColor::GREEN);
    SPACE(NUB2); cout << "User      :                                    " << '\n';
    SPACE(NUB2); cout << "Password  :                                    ";

    SetColor(eColor::BLACK, eColor::WHITE);



    int loginSuccess = login();
    SPACE(NUB2); cout << "An \"ESC\" de thoat an \"p\" de quay lai hoac an \"Enter\" de tiep tuc.";
    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if (_cKeyPress == 'p')
            menu();
        else if (_cKeyPress == ENTER) {
            if (loginSuccess == 2)
                menuManage();
            else if (loginSuccess == 1) {
                manage();
            }
            else {
                exit(0);
            }
        }
    }

}


void Program::loadingOrder()
{
    system("cls");
    for (size_t i = 0; i < szOrders.size(); i++)
    {
        if (orderSuccess(szOrders.front()))
        {
            writeToFile(szOrders.front(), g_FileDonHang, true);
            for (size_t j = 1; j < szOrders.front().szCodeItems.size(); j++)
                updateItem(szOrders.front().szCodeItems[j], -szOrders.front().szProducts[j]);
        }
        else
            writeToFile(szOrders.front(), g_FileDonHang, false);
        stt++;
        szOrders.pop();
    }

    NEWLINE(TOP);
    SPACE(NUB2); cout << "Da xu ly. Con lai " << szOrders.size() << " don hang can xu li.\n";
    NEWLINE(BOTTOM);
    SPACE(NUB2); cout << "An \"ESC\" de thoat \"p\" de quay lai \"Enter\" de tiep tuc.";
    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if (_cKeyPress == 'p')
            menuManage();
        else if (_cKeyPress == ENTER)
            loadingOrder();
    }
}
void Program::writeToFile(Order& o, const string& path, bool state)
{
    ofstream f(g_FileDonHang, std::ios::app);
    if (f)
    {

        f << "======DON HANG " << (state ? "THANH CONG" : "THAT BAI") << " ======\n";
        f << "Ma don: " << stt << '\n';
        f << "Ten khach hang: " << o.getCustomer() << '\n';
        f << "Dia chi khach hang: " << o.getCustomerAdress() << '\n';
        f << "Dien thoai: " << o.getPhone() << '\n';
        f << "Ngay mua: " << o.getDay() << '\n';
        f << "\n***Cac san pham dat mua***" << '\n';
        for (size_t i = 0; i < o.szCodeItems.size(); i++)
            f << "   Ma hang hoa " << o.szCodeItems[i] << " voi " << o.szProducts[i] << " so luong.\n";
        f << "\n==========================================================================" << endl;


    }
    else
        cout << "Khong the mo file. Vui long thu lai.";
    f.close();
}
void Program::uploadFile(const string& path)
{
    ofstream f(path);
    if (f)
    {
        for (size_t i = 0; i < szItems.size(); i++)
        {
            f << szItems[i];
            if (i != szItems.size() - 1)
                f << '\n';
        }
    }
    f.close();
}
void Program::manageItem()
{
    system("cls");
    NEWLINE(TOP);
    SPACE(NUB2); cout << "*************************************************" << '\n';
    SPACE(NUB2); cout << "***              Quan Ly Hang Hoa            ****" << '\n';
    SPACE(NUB2); cout << "*************************************************" << '\n';

    NEWLINE(BOTTOM);
    SPACE(NUB2); cout << "1. Them hang hoa moi.\n";
    SPACE(NUB2); cout << "2. Xoa hang hoa.\n";
    SPACE(NUB2); cout << "3. Cap nhat so luong hang hoa.\n";

    NEWLINE(BOTTOM);
    SPACE(NUB2); cout << "An \"ESC\" de thoat \"P\" de quay lai.";

    while (_cKeyPress = _getch())
    {
        switch (_cKeyPress)
        {
        case '1':
            addItem();
            exit(0);
        case '2':
            removeItem();
            exit(0);
        case '3':
            updateItem();
            exit(0);
        case 'p':
            menuManage();
            exit(0);
        case ESC:
            exit(0);
        default:
            SPACE(NUB2); cout << "Du lieu khong hop le, tu dong thoat!";
            exit(0);
        }
    }
}


// quan ly hang hoa//
void Program::addItem()
{
    system("cls");
    NEWLINE(TOP);

    Item i;
    string strCode;
    SPACE(NUB2); cout << "Ma hang: ";
    cin >> strCode;
    cin.ignore(225, '\n');

    if (foundItem(strCode))
    {
        NEWLINE(BOTTOM);
        SPACE(NUB2); cout << "Ma hang da ton tai.\n";
    }
    else
    {
        cin >> i;
        i.setCode(strCode);
        szItems.push_back(i);
    }

    uploadFile(g_FileHangHoa);
    NEWLINE(BOTTOM);
    SPACE(NUB); cout << "An \"ESC\" de thoat \"p\" de quay lai \"Enter\" de tiep tuc.";
    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if (_cKeyPress == 'p')
            manageItem();
        else if (_cKeyPress == ENTER)
            addItem();
    }
}
void Program::removeItem()
{
    system("cls");
    NEWLINE(TOP);
    SPACE(NUB2); cout << "Ma hang: ";
    string strCode;
    cin >> strCode;

    bool success = false;
    for (size_t i = 0; i < szItems.size(); i++)
    {
        if (szItems[i].getCode() == strCode)
        {
            szItems.erase(szItems.begin() + i);
            success = true;
        }
    }

    NEWLINE(BOTTOM);
    if (success)
    {
        SPACE(NUB2); cout << "!!!DA XOA!!!";
        uploadFile(g_FileHangHoa);
        NEWLINE(BOTTOM);
    }

    SPACE(NUB2); cout << "An \"ESC\" de thoat \"P\" de quay lai \"Enter\" de tiep tuc.";
    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if (_cKeyPress == 'p')
            manageItem();
        else if (_cKeyPress == ENTER)
            removeItem();
    }
}
void Program::updateItem()
{
    system("cls");

    NEWLINE(TOP);
    SPACE(NUB2);
    cout << "Ma hang hoa muon cap nhat: ";
    string strCode;
    cin >> strCode;
    int iProducts = 0;
    SPACE(NUB2);
    cout << "1. Tang\n";
    SPACE(NUB2);
    cout << "2. Giam\n";

    bool bAsc = false;
    while (_cKeyPress = _getch())
    {

        if (_cKeyPress == '1' || _cKeyPress == '2')
        {
            SPACE(NUB2);
            bAsc = _cKeyPress == '1';
            cout << ((bAsc) ? "Tang them: " : "Giam xuong: ");
            break;
        }
    }

    cin >> iProducts;

    bool success = false;
    for (size_t i = 0; i < szItems.size(); i++)
        if (szItems[i].getCode() == strCode)
        {
            success = true;
            bAsc ? szItems[i].update(iProducts) : szItems[i].update(-iProducts);
        }
    uploadFile(g_FileHangHoa);
    NEWLINE(BOTTOM);
    if (success)
    {
        SPACE(NUB2);

        cout << "!!!!THANH CONG!!!!!";
    }
    NEWLINE(BOTTOM);
    SPACE(NUB); cout << "An \"ESC\" de thoat \"p\" de quay lai.";
    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        if (_cKeyPress == 'p')
            manageItem();
    }
}


//____________________________
bool Program::orderSuccess(Order& o)
{
    for (size_t i = 0; i < o.szCodeItems.size(); i++)
    {
        if (!foundItem(o.szCodeItems[i]))
            return false;
        else
            if (o.szProducts[i] <= 0 && greaterMaxProducts(o.szCodeItems[i], o.szProducts[i]))
                return false;
    }
    return true;
}
bool Program::foundItem(const string& code)
{
    for (size_t i = 0; i < szItems.size(); i++)
        if (code == szItems[i].getCode())
            return true;
    return false;
}
bool Program::greaterMaxProducts(const string& code, int n) {
    for (size_t i = 0; i < szItems.size(); i++)
        if (code == szItems[i].getCode())
            return szItems[i].getNumber() <= n;
    return false;
}
void Program::updateItem(const string& code, int product)
{
    for (size_t i = 0; i < szItems.size(); i++)
        if (code == szItems[i].getCode())
        {
            szItems[i].update(product);
            return;
        }
}
int Program::login()
{
    Account myAccount;

    GoTo(NUB2 + 15, TOP + BOTTOM + 3);
    myAccount.setTK();
    GoTo(NUB2 + 15, TOP + BOTTOM + 3 + 1);
    myAccount.setMK("");

    while (true)
    {
        _cKeyPress = _getch();

        if (_cKeyPress == BACKSPACE)
        {
            string newPassword = myAccount.getMK();
            if (newPassword != "")
            {
                newPassword.pop_back();
                cout << "\b \b";
            }
            myAccount.setMK(newPassword);
        }
        else if (isspace(_cKeyPress))
            break;
        else
        {
            myAccount.setMK(myAccount.getMK() + _cKeyPress);
            cout << '*';
        }

    }

    SetColor(eColor::BLACK, eColor::YELLOW);
    NEWLINE(3);

    static int soLanNhap = 3;
    bool success = false;
    for (size_t i = 0; i < szAdmin.size(); i++)
        if (szAdmin[i] == myAccount)
        {
            success = true;
            break;
        }
    if (success && soLanNhap)
    {
        SetColor(eColor::BLACK, eColor::GREEN);
        SPACE(NUB2); cout << "Dang nhap thanh cong. ";
        Sleep(1000);
        menuManage();
        NEWLINE(6);
        return 2;
    }
    else if (success && soLanNhap == 0) {
        SetColor(eColor::BLACK, eColor::GREEN);
        SPACE(NUB2); cout << "Dang nhap thanh cong. ";
        Sleep(1000);
        menuManage();
        NEWLINE(6);
        return 2;
    }
    else if (!success)
    {
        (soLanNhap > 0) ? soLanNhap-- : soLanNhap;
        SetColor(eColor::BLACK, eColor::RED);
        SPACE(NUB2); cout << "Dang nhap khong thanh cong.\n";
        SPACE(NUB2); cout << "So lan con lai: " << soLanNhap;
        NEWLINE(6);
        SetColor(eColor::BLACK, eColor::WHITE);
        if (!success && soLanNhap == 0) {
			SetColor(eColor::BLACK, eColor::RED);
            SPACE(NUB2); cout << "Ban da nhap sai qua so lan cho phep.\n";
            SPACE(NUB2); cout << "Tam biet!";
            Sleep(3000);
            exit(0);
        }
        return 1;
    }
	return 0;
}
// quanLy//
void Program::menuManage()
{
    system("cls");

    NEWLINE(TOP);
    SetColor(eColor::BLACK, eColor::WHITE);
    SPACE(NUB2); cout << "*************************************************" << '\n';
    SPACE(NUB2); cout << "***                Menu Quan Ly              ****" << '\n';
    SPACE(NUB2); cout << "*************************************************" << '\n';

    NEWLINE(BOTTOM);
    SPACE(NUB2); cout << "1. Xu ly don hang." << '\n';
    SPACE(NUB2); cout << "2. Quan ly hang hoa." << '\n';
    NEWLINE(BOTTOM);


    SPACE(NUB2); cout << "An \"ESC\" de thoat \"p\" de quay lai.";
	
    while (_cKeyPress = _getch())
    {
        switch (_cKeyPress)
        {
        case '1':
            loadingOrder();
            exit(0);
        case '2':
            manageItem();
            exit(0);

        case 'p':
            menu();
            exit(0);
        case ESC:
            exit(0);
        default:
            SPACE(NUB2); cout << "Du lieu khong hop le, tu dong thoat!";
            exit(0);
        }
    }
}
#include "Program.h"

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
    Account a;
    ifstream f(g_FileAdmin);
    while (!f.eof())
    {
        f >> a;
        szAdmin.push_back(a);
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


void Program::run()
{
    menu();
}
void Program::menu()
{
    system("cls");
    
    SetColor(eColor::BLACK, eColor::YELLOW);
    NEWLINE(TOP);
    SPACE(NUB2); cout << "*************************************************" << '\n';
    SPACE(NUB2); cout  << "***                   Menu                    ***" << '\n';
    SPACE(NUB2); cout  << "*************************************************" << '\n';
    SPACE(NUB2); cout  << "1. Hien thi thong tin hang hoa." << '\n';
    SPACE(NUB2); cout  << "2. Tim kiem thong tin hang hoa." << '\n';
    SPACE(NUB2); cout  << "3. Dat hang." << '\n';
    SPACE(NUB2); cout  << "4. Quan ly." << '\n';


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
        }
    }

}

// menu
void Program::display()
{
    system("cls");

    cout << left;
    SPACE(NUB - WIDTH);
    HOR(WIDTH+SP1+WIDTH+SP3+WIDTH+SP2+WIDTH+SP1+WIDTH+SP1+WIDTH+SP2+WIDTH+SP1+WIDTH);
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
        else if ( _cKeyPress == 'p')
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
    //cin.ignore(32676, '\n');

    cin >> o;
    NEWLINE(3);

    if (orderSuccess(o))
    {
        NEWLINE(5);
        SPACE(NUB2);cout << "Don hang dang cho xu ly.";
        szOrders.push(o);
    }
    else
    {
        SPACE(NUB2);cout << "Don hang THAT BAI, mot so san pham khong co san vui long ghe lai sau!";
    }

    NEWLINE(3);
    SPACE(NUB2); cout << "An \"ESC\" de thoat \"p\" de quay lai ENTER de tiep tuc.";

    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC)
            exit(0);
        else if ( _cKeyPress == 'p')
            menu();
        else if (_cKeyPress == ENTER)
            order();
    }
}
void Program::manage()
{
    system("cls");
    NEWLINE(TOP);

    SPACE(NUB2); cout << "*************************************************" << '\n';
    SPACE(NUB2); cout << "***";
    SetColor(eColor::BLACK, eColor::LIGHT_GREEN);
    cout << "               DANG NHAP HE THONG          ";
    SetColor(eColor::BLACK, eColor::YELLOW);
    cout << "***" << '\n';
    SPACE(NUB2); cout << "*************************************************" << '\n';
    NEWLINE(BOTTOM);
    SetColor(eColor::BLACK, eColor::GREEN);
    SPACE(NUB2); cout << "User      :                                    " << '\n';
    SPACE(NUB2); cout << "Password  :                                    ";

    SetColor(eColor::BLACK, eColor::WHITE);



    bool loginSuccess = login();

    SPACE(NUB2); cout << "An \"ESC\" de thoat an \"p\" de quay lai hoac an \"Enter\" de tiep tuc.";
    while (_cKeyPress = _getch())
    {
        if (_cKeyPress == ESC )
            exit(0);
        else if ( _cKeyPress == 'p')
            menu();
        else if (_cKeyPress == ENTER)
            if (loginSuccess)
                menuManage();
            else
                manage();
    }

}

// quanLy//
void Program::menuManage()
{
    system("cls");

    NEWLINE(TOP);
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
                updateItem(szOrders.front().szCodeItems[j],-szOrders.front().szProducts[j]);
        }
        else
            writeToFile(szOrders.front(), g_FileDonHang, false);
        stt++;
        szOrders.pop();
    }
        
    NEWLINE(TOP);
    SPACE(NUB2); cout << "Da xu ly. Con lai " << szOrders.size() << " don hang can xu li.\n";
    NEWLINE(BOTTOM);
    SPACE(NUB2); cout << "An \"ESC\" de thoat \"P\" de quay lai \"Enter\" de tiep tuc.";
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
        
        //cout << "Da tien hanh ghi file.\n";
        f << "======DON HANG " << (state ? "THANH CONG" : "THAT BAI") << " ======\n";
        f << "Ma don: " << stt << '\n';
        f << "Ten khach hang: " << o.getCustomer() << '\n';
        f << "Dia chi khach hang: " << o.getCustomerAdress() << '\n';
        f << "Dien thoai: " << o.getPhone() << '\n';
        f << "Ngay mua: " << o.getDay() << '\n';
        f << "\n***Cac san pham dat mua***" << '\n';
        for (size_t i = 0; i < o.szCodeItems.size(); i++)
            f << "   Ma hang hoa " << o.szCodeItems[i] << " voi " << o.szProducts[i] << " so luong.\n";
        f << "\n=========================================================================="<<endl;


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
    
    SPACE(NUB2);cout << "An \"ESC\" de thoat \"P\" de quay lai \"Enter\" de tiep tuc.";
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
            if (o.szProducts[i] <= 0 && greaterMaxProducts(o.szCodeItems[i],o.szProducts[i]))
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
bool Program::login()
{
    Account myAccount;

    GoTo(NUB2+15, TOP + BOTTOM + 3);
    myAccount.setUser();
    GoTo(NUB2+15, TOP + BOTTOM + 3 +  1);
    myAccount.setPin("");

    while (true)
    {
        _cKeyPress = _getch();

        if (_cKeyPress == BACKSPACE)
        {
            string newPassword = myAccount.getPin();
            if (newPassword != "") 
            {
                newPassword.pop_back();
                cout << "\b \b";
            }
            myAccount.setPin(newPassword);
        }
        else if (isspace(_cKeyPress))
            break;
        else
        {
            myAccount.setPin(myAccount.getPin() + _cKeyPress);
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
        SPACE(NUB2); cout << "Dang nhap thanh cong. ";
        NEWLINE(6);
        
        return true;
    }
    else
    {
        (soLanNhap > 0) ? soLanNhap-- : soLanNhap;
        SPACE(NUB2); cout << "Dang nhap khong thanh cong. \n";
        SPACE(NUB2); cout << "Ban con " << soLanNhap << " lan thu.";
        NEWLINE(6);
        
        return false;
    }

  
}
